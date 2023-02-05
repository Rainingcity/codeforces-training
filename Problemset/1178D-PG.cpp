/*
 * Codeforces 1178D
 * Prime Graph
 */

#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
int n;
bool v[1001000];
vector<int> pm;
vector<pii> ans;
int main(){
	scanf("%d", &n);
	for(int i=2;i<1000000;i++){
		if (!v[i]) pm.push_back(i);
		for(auto k: pm){
			if (i*k>1000000) break;
			v[i*k]=1;
			if (i%k==0) break;
		}
	}
	int tot=0;
	if (n==3){
		cout<<3<<endl;
		cout<<"1 2"<<endl;
		cout<<"1 3"<<endl;
		cout<<"2 3"<<endl;
		return 0;
	}else if (n==4){
		cout<<5<<endl;
		cout<<"1 2"<<endl;
		cout<<"1 3"<<endl;
		cout<<"2 3"<<endl;
		cout<<"2 4"<<endl;
		cout<<"3 4"<<endl;
		return 0;
	}else if (n==5){
		cout<<7<<endl;
		cout<<"1 2"<<endl;
		cout<<"1 3"<<endl;
		cout<<"2 3"<<endl;
		cout<<"2 4"<<endl;
		cout<<"3 4"<<endl;
		cout<<"1 5"<<endl;
		cout<<"4 5"<<endl;
		return 0;
	}else if (n==7){
		cout<<11<<endl;
		cout<<"1 2"<<endl;
		cout<<"1 3"<<endl;
		cout<<"2 3"<<endl;
		cout<<"2 4"<<endl;
		cout<<"3 4"<<endl;
		cout<<"5 6"<<endl;
		cout<<"5 7"<<endl;
		cout<<"6 7"<<endl;
		cout<<"1 5"<<endl;
		cout<<"2 6"<<endl;
		cout<<"2 7"<<endl;
		return 0;
	}else if (n==8){
		cout<<11<<endl;
		cout<<"1 2"<<endl;
		cout<<"1 3"<<endl;
		cout<<"2 3"<<endl;
		cout<<"2 4"<<endl;
		cout<<"3 4"<<endl;
		cout<<"5 6"<<endl;
		cout<<"5 7"<<endl;
		cout<<"6 7"<<endl;
		cout<<"6 8"<<endl;
		cout<<"7 8"<<endl;
		cout<<"1 5"<<endl;
		return 0;
	}else if (n%3==0){
		for(int i=1;i<n;i+=3){
			ans.push_back(make_pair(i,i+1));
			ans.push_back(make_pair(i,i+2));
			ans.push_back(make_pair(i+1,i+2));
		}
		tot=n;
		int i=1;
		while(v[tot]){
			ans.push_back(make_pair(i, i+3));
			i++;tot++;
			if (i%3==1) i+=3;
		}
	}else if (n%3==1){
		for(int i=1;i<n-4;i+=3){
			ans.push_back(make_pair(i, i+1));
			ans.push_back(make_pair(i, i+2));
			ans.push_back(make_pair(i+1, i+2));
		}
		ans.push_back(make_pair(n-3,n-2));
		ans.push_back(make_pair(n-3,n-1));
		ans.push_back(make_pair(n-2,n-1));
		ans.push_back(make_pair(n-2,n));
		ans.push_back(make_pair(n-1,n));
		tot=n+1;
		int i=1;
		while(v[tot]){
			ans.push_back(make_pair(i, i+3));
			i++;tot++;
			if (i%3==1) i+=3;
		}
	}else if (n%3==2){
		for(int i=1;i<n-8;i+=3){
			ans.push_back(make_pair(i, i+1));
			ans.push_back(make_pair(i, i+2));
			ans.push_back(make_pair(i+1, i+2));
		}
		ans.push_back(make_pair(n-3,n-2));
		ans.push_back(make_pair(n-3,n-1));
		ans.push_back(make_pair(n-2,n-1));
		ans.push_back(make_pair(n-2,n));
		ans.push_back(make_pair(n-1,n));
		ans.push_back(make_pair(n-7,n-6));
		ans.push_back(make_pair(n-7,n-5));
		ans.push_back(make_pair(n-6,n-5));
		ans.push_back(make_pair(n-6,n-4));
		ans.push_back(make_pair(n-5,n-4));
		tot=n+2;
		int i=1;
		while(v[tot]){
			ans.push_back(make_pair(i, i+3));
			i++;tot++;
			if (i%3==1) i+=3;
		}
	}
	cout<<tot<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
}
