/*
 * Codeforces 1204A
 * BowWow and the Timetable
 */

#include <iostream>
#include <string>
using namespace std;
string s;
int n;
bool check_two(string s){
    for(int i=1;i<n;i++) if (s[i]=='1') return false;
    return true;
}
int main(){
    cin>>s;
    n=s.length();
    if (check_two(s)){
        cout<<n/2<<endl;
    }else if (n&1){
        cout<<(n+1)/2<<endl;
    }else cout<<n/2<<endl;
    return 0;
}
