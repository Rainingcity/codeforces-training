#include <iostream>
using namespace std;
typedef long long ll;
ll me[10][2];
ll mac[10][3];
ll work(ll st){
	ll cur=st;
	for(int i=0;i<10;i++){
		ll t=0;
		if (cur>=mac[i][2]){
			t=(cur-mac[i][2])%(mac[i][0]+mac[i][1]);
			if (t<mac[i][0]) cur+=(mac[i][0]-t);
		}
		cur+=me[i][0];
		if (cur>=mac[i][2]){
			if (cur-me[i][0]<mac[i][2]) mac[i][2]=cur;
			else{
				ll q1=(cur-mac[i][2])/(mac[i][0]+mac[i][1]);
				ll q2=(cur-me[i][0]-mac[i][2])/(mac[i][0]+mac[i][1]);
				t=(cur-mac[i][2])%(mac[i][0]+mac[i][1]);
				if (!(q1==q2 || (q2==q1+1 && t==0))) mac[i][2]=cur;
			}
		}
		cur+=me[i][1];
	}
	return cur;
}
int main(){
	for(int i=0;i<10;i++){
		cin>>me[i][0]>>me[i][1];
	}
	for(int i=0;i<10;i++){
		cin>>mac[i][0]>>mac[i][1]>>mac[i][2];
	}
	cout<<work(work(work(0)))-me[9][1]<<endl;
	return 0;
}
