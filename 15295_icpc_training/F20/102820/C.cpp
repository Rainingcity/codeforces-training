#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long double ld;
int n;
vector<ld> b{};
int main(){
	cin>>n;
	ld denom=0.0;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		b.push_back(x);
		denom+=log(x);
	}
	for(int i=n-1;i>0;i--){
		b[i-1]=min(b[i],b[i-1]);
	}
	ld ans=1.0;
	ld fact=-1.0;
	for(int i=1;i<=n;i++){
		fact=-fact;
		fact/=i;
		ld sum=0.0;
		ld cur_acc=1.0;
		for(int j=0;j<i;j++){
			cur_acc*=b[j];
			ld cur=cur_acc;
			for(int k=1;k<i;k++) cur*=b[j];
			for(int k=j+i;k<n;k++) cur*=b[k];
			sum+=cur;
		}
		ans+=sum*fact;
	}
	cout<<log(ans)-denom<<endl;
}
