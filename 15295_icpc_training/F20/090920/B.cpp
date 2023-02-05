#include <iostream>
#include <set>
using namespace std;
int W, H, n;
multiset<int> height;
multiset<int> width;
set<int> hcut;
set<int> wcut;
int main(){
	cin>>W>>H>>n;
	height.insert(H);
	width.insert(W);
	hcut.insert(0);hcut.insert(H);
	wcut.insert(0);wcut.insert(W);
	for(int i=0;i<n;i++){
		string op;int x;
		cin>>op>>x;
		if (op=="H"){
			if (hcut.find(x)==hcut.end()){
				auto it = hcut.lower_bound(x);
				int r=*it;
				it--;
				int l=*it;
				// cout<<l<<" "<<r<<endl;
				height.erase(height.find(r-l));
				height.insert(x-l);
				height.insert(r-x);
				hcut.insert(x);
			}
		}else{
			if (wcut.find(x)==wcut.end()){
				auto it = wcut.lower_bound(x);
				int r=*it;
				it--;
				int l=*it;
				// cout<<l<<" "<<r<<endl;
				width.erase(width.find(r-l));
				width.insert(x-l);
				width.insert(r-x);
				wcut.insert(x);
			}
		}
		cout<<(long long)(*height.rbegin())*(*width.rbegin())<<endl;
	}
	return 0;
}
