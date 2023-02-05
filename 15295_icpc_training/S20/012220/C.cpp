#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int maxi(int x, int y){return x<y?y:x;}
int n;
set<int,std::greater<int>> st;
int rec_add(int x){
	if (x==0) return 0;
	if (st.count(x)){
		return rec_add(x>>1);
	}else{
		return x;
	}
}
int main(){
	cin>>n;
	int mx=0;
	for(int i=0;i<n;i++){
		int x;cin>>x;st.insert(x);
	}
	while(true){
		int cur=*st.begin();
		st.erase(st.begin());
		int t=rec_add(cur>>1);
		if (t) st.insert(t);
		else{
			st.insert(cur);
			break;
		}
	}
	bool beg=false;
	for(auto& x:st){
		if (beg) cout<<" ";
		else beg=true;
		cout<<x;
	}cout<<endl;
	return 0;
}
