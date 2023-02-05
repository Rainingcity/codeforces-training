#include <iostream>
using namespace std;
const int inf = 1e5;
int mini(int x, int y){return x<y?x:y;}
int mini(int x, int y, int z){return mini(x, mini(y, z));}
int mini(int x, int y, int z, int w){return mini(x, mini(y, mini(z, w)));}
int n;
int f[110][3];
int main(){
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		int op;cin>>op;
		if (op==0){
			f[i][0]=mini(f[i-1][0], f[i-1][1], f[i-1][2])+1;
			f[i][1]=f[i][2]=inf;
			ans=f[i][0];
		}else if (op==1){
			f[i][1]=mini(f[i-1][0], f[i-1][2]);
			f[i][0]=mini(f[i-1][0], f[i-1][1], f[i-1][2])+1;
			f[i][2]=inf;
			ans=mini(f[i][0], f[i][1]);
		}else if (op==2){
			f[i][2]=mini(f[i-1][0], f[i-1][1]);
			f[i][0]=mini(f[i-1][0], f[i-1][1], f[i-1][2])+1;
			f[i][1]=inf;
			ans=mini(f[i][0], f[i][2]);
		}else if (op==3){
			f[i][1]=mini(f[i-1][0], f[i-1][2]);
			f[i][2]=mini(f[i-1][0], f[i-1][1]);
			f[i][0]=mini(f[i-1][0], f[i-1][1], f[i-1][2])+1;
			ans=mini(f[i][0], f[i][1], f[i][2]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
