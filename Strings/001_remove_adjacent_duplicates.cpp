#include<iostream>
using namespace std;

string removeDuplicate(string s){
    string result;

    for(char c:s){
        if(result.empty() || result.back()!=c){
            result.push_back(c);
        }
        else{
            result.pop_back();
        }
    }
    return result;
}

int main(){
    string s;
    cin>>s;

    cout<<removeDuplicate(s)<<endl;
}