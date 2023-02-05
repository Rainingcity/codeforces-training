#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <utility>
using namespace std;
int n,m;
queue<string> q;
vector<pair<string,string>> ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string s;cin>>s;
		q.push(s);
	}
	string s;cin>>s;
	m=s.length();
	char cur=s[0];
	int mx=1,cnt=1;
	for(int j=1;j<m;j++){
		if (s[j]==cur) cnt++;
		else{
			if (cnt>mx) mx=cnt;
			cnt=1;
			cur=s[j];
		}
	}
	if (cnt>mx) mx=cnt;
	cnt=1;cur=s[0];
	for(int j=1;j<m;j++){
		if (s[j]==cur) cnt++;
		else{
			if (cnt==mx){
				s[j-cnt]+='a'-'A';
			}
			cnt=1;
			cur=s[j];
		}
	}
	if (cnt==mx) s[m-cnt]+='a'-'A';
	string b1,b2,w1,w2;
	w1=q.front();q.pop();
	b1=q.front();q.pop();
	w2=q.front();q.pop();
	b2=q.front();q.pop();
	string tmp="";
	for(int i=0;i<m;i++){
		if (s[i]=='w'){
			if (i==0) ans.push_back(make_pair(w1,w2));
			else ans.push_back(make_pair(w2,w1));
			tmp=w1;w1=w2;w2=tmp;
			q.push(b2);b2=b1;b1=q.front();q.pop();
		}else if (s[i]=='b'){
			if (i==0) ans.push_back(make_pair(b1,b2));
			else ans.push_back(make_pair(b2,b1));
			tmp=b1;b1=b2;b2=tmp;
			q.push(w2);w2=w1;w1=q.front();q.pop();
		}else if (s[i]=='W'){
			tmp=w1;w1=w2;w2=tmp;
			q.push(b2);b2=b1;b1=q.front();q.pop();
		}else if (s[i]=='B'){
			tmp=b1;b1=b2;b2=tmp;
			q.push(w2);w2=w1;w1=q.front();q.pop();
		}
	}
	for(auto& [p1,p2]: ans){
		cout<<p1<<" "<<p2<<endl;
	}
	return 0;
}
