#include <bits/stdc++.h>
using namespace std;
int main(){
    int i;
    string ch;
    cout<<"Enter the value:";
    cin>>ch;
    //for(int i=0;i<ch.size();i++){
    while(i<ch.size()){
        if(ch[i]=='c'&&ch[i+1]=='|'&&ch[i+2]=='d'){
            cout<<"q["<<i<<"]\t"<<"e"<<"\t q["<<i+1<<"]\t, q["<<i+3<<"]\n";
            cout<<"q["<<i+1<<"]\t"<<ch[i]<<"\t q["<<i+2<<"]\n";
            cout<<"q["<<i+3<<"]\t"<<ch[i+2]<<"\t q["<<i+4<<"]\n";
            cout<<"q["<<i+2<<"]\t"<<"e"<<"\t q["<<i+5<<"] \n";
            cout<<"q["<<i+4<<"]\t"<<"e"<<"\t q["<<i+5<<"] \n";
        }
        if(ch[i] =='c' && ch[i+1] != '|'){
            cout<<"q["<<i<<"]\t"<<ch[i]<<"q["<<i+1<<"]\n";
        }
        if(ch[i] =='d' && ch[i+1] != '('){
            cout<<"q["<<i<<"]\t"<<ch[i]<<"q["<<i+1<<"]\n";
        }
        i++;
    }
    return 0;
}
