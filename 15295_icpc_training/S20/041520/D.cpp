#include <iostream>
#include <string>
using namespace std;
string s;
int n;
string ans="";
int zero;
bool f1=false,f6=false,f8=false,f9=false;
void add_digit(string& ss, int& md, char c){
	ss+=c;
	md=md*10+(c-'0');
	md%=7;
}
int table[7]={1869, 1968, 1689, 6198, 1698, 1986, 1896};
int main(){
	cin>>s;n=s.length();
	int md=0;
	for(int i=0;i<n;i++){
		if (s[i]=='0') zero++;
		else if (s[i]=='1'){
			if (f1) add_digit(ans, md, s[i]);
			else f1=true;
		}else if (s[i]=='6'){
			if (f6) add_digit(ans, md, s[i]);
			else f6=true;
		}else if (s[i]=='8'){
			if (f8) add_digit(ans, md, s[i]);
			else f8=true;
		}else if (s[i]=='9'){
			if (f9) add_digit(ans, md, s[i]);
			else f9=true;
		}else add_digit(ans, md, s[i]);
	}
	md=(md*4)%7;
	md=(7-md)%7;
	cout<<ans;
	cout<<table[md];
	for(int i=0;i<zero;i++) cout<<"0";
	cout<<endl;
	return 0;
}
