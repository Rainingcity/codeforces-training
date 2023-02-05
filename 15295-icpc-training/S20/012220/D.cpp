#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
int n;
multiset<ll> st;
vector<ll> psum;
vector<ll> v;
vector<int> ord;
set<int> cuts;
int main(){
	cin>>n;
	ll cur_sum=0;
	psum.push_back(cur_sum);
	for(int i=0;i<n;i++){
		int x;cin>>x;v.push_back(x);
		cur_sum+=x;
		psum.push_back(cur_sum);
	}
	st.insert(cur_sum);
	for(int i=0;i<n;i++){
		int x;cin>>x;x--;
		ord.push_back(x);
	}
	cuts.insert(-1);
	cuts.insert(n);
	for(int i=0;i<n;i++){
		auto pos=cuts.lower_bound(ord[i]);
		int r=*pos;
		pos--;
		int l=*pos;
		// cout<<l<<" "<<r<<endl;
		cuts.insert(ord[i]);
		st.erase(st.find(psum[r]-psum[l+1]));
		st.insert(psum[r]-psum[ord[i]+1]);
		st.insert(psum[ord[i]]-psum[l+1]);
		cout<<*st.rbegin()<<endl;
	}
}
