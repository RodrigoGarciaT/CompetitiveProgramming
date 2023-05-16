#include<bits/stdc++.h>
using namespace std;

int main(){
    //check if  a string is a palindrome

    string s;
    cin>>s;

    for(int i =0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            cout<<"NO"<<endl;
            return 0;
        }

    }

    cout<<"YES"<<endl;
    return 0;
}