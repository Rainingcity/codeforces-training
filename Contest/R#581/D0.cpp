#include <iostream>
#include <vector>
using namespace std;
int maxi(int x, int y){return x<y?y:x;}
int n;
int calc(auto& v, int st, int ed){
	int x=0, y=0;
	for(int i=st;i<=ed;i++){
		if (v[i]==0) y++;
		else if (x>=y) x++;
		else x=y+1;
	}
	return maxi(x, y);
}
int main(){
	cin>>n;
	int MX=1<<n;
	vector<bool> v;
	v.resize(n);
	cout<<"    i";
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++) cout<<" "<<i;
	}
	cout<<"\n    j";
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++) cout<<" "<<j;
	}cout<<endl;
	for(int i=0;i<MX;i++){
		for(int i=0;i<n;i++) cout<<v[i];
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				cout<<" "<<calc(v, i, j);
			}
		}cout<<endl;
		int j=n-1;
		while(j>0 && v[j]==1) v[j--]=0;
		v[j]=1;
	}
	return 0;
}
