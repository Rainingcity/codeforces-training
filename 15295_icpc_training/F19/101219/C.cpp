#include <iostream>
#include <string>
using namespace std;
string s;
int main(){
	cin>>s;
	size_t len = s.length();
	size_t hlen=len/2;
	int sum = 0;
	for(int i=0;i<hlen;i++){
		sum += s[i]-'A';
	}
	sum %= 26;
	string ans="";
	for(int i=0;i<hlen;i++){
		char c = 'A'+ (s[i]-'A'+sum)%26;
		ans=ans+c;
	}
	sum=0;
	for(int i=hlen;i<len;i++){
		sum+=s[i]-'A';
	}
	sum %=26;
	for(int i=0;i<hlen;i++){
		ans[i]='A'+(ans[i]-'A'+s[i+hlen]-'A'+sum)%26;
	}
	cout<<ans<<endl;
	return 0;
}
