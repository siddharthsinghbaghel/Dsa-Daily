#include<iostream>
#include<string>
using namespace std;

string removeOccurence(string s, string part){
    string result = "";

    for(char c:s){
        result.push_back(c);

        //check if the end of result contains part
        if(result.size()>= part.size() && result.substr(result.size() - part.size()) == part) {
            result.erase(result.size() - part.size());
        }
    }
    return result;
}