
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

unordered_map<char, vector<string>> productions;

unordered_map<char, unordered_set<string>> closure;

unordered_set<string> getLR0Items(char nonTerminal, const string& production) {
    unordered_set<string> items;

    for (int i = 0; i <= production.length(); i++) {
        string item = production.substr(0, i) + "." + production.substr(i);
        items.insert(item);
    }

    closure[nonTerminal].insert(items.begin(), items.end());
    return items;
}

void computeClosure(char nonTerminal, const string& production) {
    if (closure[nonTerminal].count(production)) {
        return;
    }

    unordered_set<string> items = getLR0Items(nonTerminal, production);

    for (const auto& item : items) {
        if (item.back() == '.') {
            continue;
        }

        char nextSymbol = item[item.find('.') + 1];

        if (productions.count(nextSymbol)) {
            for (const auto& nextProduction : productions[nextSymbol]) {
                computeClosure(nextSymbol, nextProduction);
                for (const auto& closureItem : closure[nextSymbol]) {
                    string newProduction = nextSymbol + "->." + closureItem;
                    closure[nonTerminal].insert(newProduction);
                }
            }
        }
    }
}

void printClosure(char nonTerminal) {
    cout << "Closure of " << nonTerminal << ":" << endl;
    for (const auto& item : closure[nonTerminal]) {
        cout << "    " << item << endl;
    }
    cout << endl;
}

void computeLR0Items() {
    for (const auto& [nonTerminal, productionList] : productions) {
        for (const auto& production : productionList) {
            computeClosure(nonTerminal, production);
        }
    }
}

void printLR0Items() {
    cout << "LR(0) items:" << endl;
    for (const auto& [nonTerminal, closureSet] : closure) {
        cout << nonTerminal << ":" << endl;
        for (const auto& item : closureSet) {
            cout << "    " << nonTerminal << " -> " << item << endl;
        }
        cout << endl;
    }
}

int main() {
    productions['S'] = {"E"};
    productions['E'] = {"E+T", "E-T", "T"};
    productions['T'] = {"T*F", "T/F", "F"};
    productions['F'] = {"(E)", "id"};

    computeLR0Items();
    printLR0Items();

    return 0;
}
