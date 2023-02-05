/*
 * Codeforces 1205C
 * Palindromic Paths
 */

#include <cstdio>
#include <iostream>
using namespace std;
int n;
bool ans[51][51];
bool x;
bool valid_pos(int x, int y){
	return 0<=x && x<n && 0<=y && y<n;
}
void print_board(bool x){
	if (x){
		cout<<"!"<<endl;
		cout.flush();
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if ((i+j)&1) cout<<!ans[i][j];
				else cout<<ans[i][j];
			}cout<<endl;
			cout.flush();
		}
	}else{
		cout<<"!"<<endl;
		cout.flush();
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) cout<<ans[i][j];
			cout<<endl;
			cout.flush();
		}
	}
}
int main(){
	cin>>n;
	ans[0][0]=true;
	for(int i=2;i<n;i+=2){
		cout<<"? 1 "<<i-1<<" 1 "<<i+1<<"\n";
		cout.flush();
		x;cin>>x;
		ans[0][i]=!(x^ans[0][i-2]);
	}
	for(int i=2;i<n;i+=2){
		cout<<"? "<<i-1<<" 1 "<<i+1<<" 1\n";
		cout.flush();
		x;cin>>x;
		ans[i][0]=!(x^ans[i-2][0]);
	}
	for(int i=1;i<n;i++){
		for(int j=(i&1?1:2);j<n;j+=2){
			if (i==n-1 && j==n-1) continue;
			cout<<"? "<<i<<" "<<j<<" "<<i+1<<" "<<j+1<<endl;
			cout.flush();
			x;cin>>x;
			ans[i][j]=!(x^ans[i-1][j-1]);
		}
	}
	for(int i=3;i<n;i+=2){
		cout<<"? 1 "<<i-1<<" 1 "<<i+1<<endl;
		cout.flush();
		x;cin>>x;
		ans[0][i]=!(x^ans[0][i-2]);
	}
	for(int i=2;i<n;i+=2){
		for(int j=1;j<n;j+=2){
			cout<<"? "<<i-1<<" "<<j+1<<" "<<i+1<<" "<<j+1<<endl;
			cout.flush();
			x;cin>>x;
			ans[i][j]=!(x^ans[i-2][j]);
		}
	}
	cout<<"? 1 2 2 3\n";
	cout.flush();
	x;cin>>x;
	ans[1][2]=!(x^ans[0][1]);
	cout<<"? 2 1 2 3\n";
	cout.flush();
	x;cin>>x;
	ans[1][0]=!(x^ans[1][2]);
	for(int i=4;i<n;i+=2){
		cout<<"? 2 "<<i-1<<" 2 "<<i+1<<endl;
		cout.flush();
		x;cin>>x;
		ans[1][i]=!(x^ans[1][i-2]);
	}
	for(int i=3;i<n;i+=2){
		for(int j=0;j<n;j+=2){
			cout<<"? "<<i-1<<" "<<j+1<<" "<<i+1<<" "<<j+1<<endl;
			cout.flush();
			x;cin>>x;
			ans[i][j]=!(x^ans[i-2][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if (valid_pos(i-3, j)){
				if ((ans[i-3][j]==ans[i-1][j])^(ans[i-2][j]!=ans[i][j])){
					cout<<"? "<<i-2<<" "<<j+1<<" "<<i+1<<" "<<j+1<<endl;
					cout.flush();
					x;cin>>x;
					print_board(x^(ans[i][j]==ans[i-3][j]));
					return 0;
				}
			}
			if (valid_pos(i, j-3)){
				if ((ans[i][j-3]==ans[i][j-1])^(ans[i][j-2]!=ans[i][j])){
					cout<<"? "<<i+1<<" "<<j-2<<" "<<i+1<<" "<<j+1<<endl;
					cout.flush();
					x;cin>>x;
					print_board(x^(ans[i][j]==ans[i][j-3]));
					return 0;
				}
			}
			if (valid_pos(i-2, j-1)){
				if (!(ans[i-1][j]==ans[i][j-1] && ans[i-2][j]==ans[i-1][j-1] && ((ans[i][j]==ans[i-2][j])^(ans[i][j-1]==ans[i-2][j-1])))){
					cout<<"? "<<i-1<<" "<<j<<" "<<i+1<<" "<<j+1<<endl;
					cout.flush();
					x;cin>>x;
					print_board(x^(ans[i][j]==ans[i-2][j-1]));
					return 0;
				}
			}
			if (valid_pos(i-1, j-2)){
				if (!(ans[i-1][j]==ans[i][j-1] && ans[i][j-2]==ans[i-1][j-1] && ((ans[i][j]==ans[i][j-2])^(ans[i-1][j]==ans[i-1][j-2])))){
					cout<<"? "<<i<<" "<<j-1<<" "<<i+1<<" "<<j+1<<endl;
					cout.flush();
					x;cin>>x;
					print_board(x^(ans[i][j]==ans[i-1][j-2]));
					return 0;
				}
			}
		}
	}
}
