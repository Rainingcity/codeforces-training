#include <iostream>
using namespace std;
int n,m;
void Swap(int& a, int& b){
	a^=b^=a^=b;
}
int main(){
	cin>>n>>m;
	if (n>m) Swap(n,m);
	if (n==1 && m==5){
		cout<<2<<endl;
	}else if (n==1 && m==4){
		cout<<3<<endl;
	}else if (m>=4){
		cout<<0<<endl;
	}else if (n==3 && m==3){
		cout<<16<<endl;
	}else if (n==2 && m==3){
		cout<<5<<endl;
	}else if (n==1 && m==3){
		cout<<3<<endl;
	}else if (n==2 && m==2){
		cout<<9<<endl;
	}else if (n==1 && m==2){
		cout<<4<<endl;
	}else{
		cout<<4<<endl;
	}
	return 0;
}
