#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int maxi(int x, int y){return x<y?y:x;}
int mini(int x, int y){return x<y?x:y;}
int mini(int x, int y, int z){return mini(mini(x, y), z);}

int n,k;
vector<int> ans;
vector<int> v1,v2;

priority_queue<int> q1,q2,q3;

int main(){
	cin>>n>>k;
	int sum1=0, sum2=0;
	v1.push_back(0);
	for(int i=1;i<n;i++){
		int x;cin>>x;sum1+=x;
		v1.push_back(sum1);
	}
	v2.push_back(0);
	for(int i=1;i<n;i++){
		int x;cin>>x;sum2+=x;
		v2.push_back(sum2);
	}

	q1.push(0);
	q2.push(0);
	q3.push(-k);
	for(int i=1;i<n;i++){
		int bw = -q1.top();
		int bwe = -q2.top();
		int be = -q3.top();
		bw += v1[i];
		bwe += v2[i]+k;
		be += v2[i];
		// cout<<bw<<" "<<bwe<<" "<<be<<endl;
		int beste = mini(bwe, be);
		int best = mini(bw, beste);
		ans.push_back(best);
		q1.push(-best+v1[i]);
		q2.push(-bw+v2[i]);
		q3.push(-beste+v2[i]);
	}

	cout<<0;
	for(auto c: ans){
		cout<<" "<<c;
	}
	cout<<endl;
	return 0;
}
