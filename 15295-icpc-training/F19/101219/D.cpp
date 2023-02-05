#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n,k;
vector<int> v;
int pt;
string s;
int cur=0;
int main(){
	cin>>n>>k;
	v.push_back(0);
	for(int cnt=0;cnt<k;cnt++){
		cin>>s;
		if (s=="undo"){
			int t;cin>>t;
			pt-=t;cur=v[pt];
		}else{
			int t=atoi(s.c_str());cur=(((cur+t)%n)+n)%n;
			pt++;
			if (pt<v.size()) v[pt]=cur;
			else v.push_back(cur);
		}
	}
	cout<<v[pt]<<endl;
	return 0;
}
