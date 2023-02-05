#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;

void swap(int& x, int& y){
	x=x^y;y=x^y;x=x^y;
}

class Heap{
private:
	int dat[1001000];
	int n;
public:
	Heap(){
		memset(dat,0,sizeof(dat));
		n=1;
	}
	bool empty(){return n==1;}
	void up(int id){
		if (id==1) return;
		int par = id>>1;
		if (dat[id]<dat[par]){
			swap(dat[id], dat[par]);
			up(par);
		}
		return;
	}
	void down(int id){
		int ch = id<<1;
		if (ch>=n) return;
		if (ch+1<n) ch = (dat[ch]>dat[ch+1]?ch+1:ch);
		if (dat[id]>dat[ch]){
			swap(dat[id], dat[ch]);
			down(ch);
		}
	}
	void insert(int x){
		dat[n++]=x;
		up(n-1);
	}
	void removeMin(){
		if (n==1) return;
		dat[1]=dat[--n];
		down(1);
	}
	int getMin(){return dat[1];}
}hp;

struct ANS{
	int op;
	int x;
	ANS(){}
	ANS(int _op, int _x){
		op=_op;x=_x;
	}
}out[1001000];
int outn;

int n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string op;cin>>op;
		if (op[0]=='i'){
			int x;cin>>x;
			hp.insert(x);
			out[outn++]=ANS(0, x);
		}else if (op[0]=='r'){
			if (hp.empty()){
				hp.insert(0);
				out[outn++]=ANS(0, 0);
			}
			hp.removeMin();
			out[outn++]=ANS(2, 0);
		}else{
			int x;cin>>x;
			int t=hp.getMin();
			while(!hp.empty() && t<x){
				hp.removeMin();
				out[outn++]=ANS(2, 0);
				if (!hp.empty()) t=hp.getMin();
			}
			if (hp.empty() || t>x){
				hp.insert(x);
				out[outn++]=ANS(0, x);
			}
			out[outn++]=ANS(1, x);
		}
	}
	cout<<outn<<endl;
	for(int i=0;i<outn;i++){
		if (out[i].op==0){
			cout<<"insert "<<out[i].x<<endl;
		}else if (out[i].op==1){
			cout<<"getMin "<<out[i].x<<endl;
		}else{
			cout<<"removeMin\n";
		}
	}
	return 0;
}
