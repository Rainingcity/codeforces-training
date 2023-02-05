#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;
int n1,n2,n3,n;
struct node{
	int x;
	node* next;
	node(){x=0;next=NULL;}
	node(int _x){
		x=_x;
		next=NULL;
	}
};
node *c1,*c2,*c3;
ll run(int cur){
	if (cur==0) return 0;
	if (c2!=NULL && c2->x==cur) return -1;
	bool rev=0;
	if (c3!=NULL && c3->x==cur){
		node* tmp=c3;c3=c1;c1=tmp;
		rev=1;
	}
	if (c1==NULL || c1->x!=cur) return -1;
	c1=c1->next;
	node* tmp=c2;c2=c3;c3=tmp;
	ll ans = run(cur-1);
	if (ans==-1) return -1;
	if (rev==1) return (1ll<<cur)-ans-1;
	else return ans;
}
int main(){
	cin>>n1;
	c1=new node();
	node* it=c1;
	for(int i=0;i<n1;i++){
		int x;cin>>x;
		node* nw=new node(x);
		it->next=nw;
		it=nw;
	}
	it=c1;
	c1=c1->next;
	free(it);
	cin>>n2;
	c2=new node();
	it=c2;
	for(int i=0;i<n2;i++){
		int x;cin>>x;
		node* nw=new node(x);
		it->next=nw;
		it=nw;
	}
	it=c2;
	c2=c2->next;
	free(it);
	cin>>n3;
	c3=new node();
	it=c3;
	for(int i=0;i<n3;i++){
		int x;cin>>x;
		node* nw=new node(x);
		it->next=nw;
		it=nw;
	}
	it=c3;
	c3=c3->next;
	free(it);
	n=n1+n2+n3;
	ll ans = run(n);
	if (ans==-1){
		cout<<"No"<<endl;
	}else{
		cout<<(1ll<<n)-ans-1<<endl;
	}
	return 0;
}
