#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<int> st;
int n,k,q;
vector<int> dat;
int main(){
	cin>>n>>k>>q;
	for(int i=0;i<n;i++){
		int x;cin>>x;dat.push_back(x);
	}
	for(int i=0;i<q;i++){
		int op,id;cin>>op>>id;id--;
		if (op==1){
			st.insert(dat[id]);
			if (st.size()>k){
				st.erase(st.begin());
			}
		}else{
			if (st.find(dat[id])!=st.end()){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
