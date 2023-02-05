#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int maxi(int x, int y){return x<y?y:x;}
int mini(int x, int y){return x<y?x:y;}

int n,k,m;
vector<int> v;
vector<vector<int>> w;

class node{
private:
	int code;
	int covered[10];
	bool col[10];
	bool eq[10];
public:
	node(){
		code=0;
		for(int i=0;i<n;i++) covered[i]=0;
		for(int i=0;i<n;i++) col[i]=0;
		for(int i=0;i<m;i++) eq[i]=0;
	}

	node(int x){
		code=x;
		for(int i=0;i<n;i++) covered[i]=0;
		for(int i=m-1;i>=0;i--){
			eq[i]=x&1;
			x>>=1;
			if (eq[i]){
				for(auto pos: w[i]) covered[pos]++;
			}
		}
		for(int i=n-1;i>=0;i--){
			col[i]=x&1;
			x>>=1;
		}
	}

	bool check_color(){
		for(int i=0;i<n;i++) if (!col[i]) return false;
		return true;
	}

	bool check_color(int idx){
		if (idx<0 || idx>=n){
			cout<<"USER ERROR: Invalid index"<<endl;
			abort();
		}
		return col[idx];
	}

	bool check_equipped(){
		for(int i=0;i<m;i++) if (eq[i]) return true;
		return false;
	}

	bool check_equipped(int idx){
		if (idx<0 || idx>=m){
			cout<<"USER ERROR: Invalid index"<<endl;
			abort();
		}
		return eq[idx];
	}

	bool check_covered(int idx){
		if (idx<0 || idx>=n){
			cout<<"USER ERROR: Invalid index"<<endl;
			abort();
		}
		return covered[idx]>0;
	}

	void set_color(int idx, bool c){
		if (idx<0 || idx>=n){
			cout<<"USER ERROR: Invalid index"<<endl;
			abort();
		}
		if (col[idx]==c) return;
		col[idx]=c;
		if (c) code+=1<<(m+n-idx-1);
		else code-=1<<(m+n-idx-1);
		return;
	}

	bool equip(int idx){
		if (idx<0 || idx>=m){
			cout<<"USER ERROR: Invalid index"<<endl;
			abort();
		}
		if (eq[idx]) return false;

		eq[idx]=1;
		code+=1<<(m-idx-1);
		for(auto pos: w[idx]) covered[pos]++;
		return true;
	}

	bool unequip(int idx){
		if (idx<0 || idx>=m){
			cout<<"USER ERROR: Invalid index"<<endl;
			abort();
		}
		if (!eq[idx]) return false;

		eq[idx]=0;
		code-=1<<(m-idx-1);
		for(auto pos: w[idx]) covered[pos]--;
		return true;
	}

	bool switch_equip(int idx){
		return equip(idx) || unequip(idx);
	}

	int to_int(){
		return code;
	}

	int to_int_but_unequip_all(){
		return ((code>>m)<<m);
	}

	node copy(){
		return node(code);
	}

	void print(){
		cout<<"XCode: "<<code<<"		";
		cout<<"Color: ";
		for(int i=0;i<n;i++) cout<<col[i];
		cout<<"		";
		cout<<"Equip: ";
		for(int i=0;i<m;i++) cout<<eq[i];
		cout<<"		";
		cout<<"Covered: ";
		for(int i=0;i<m;i++) cout<<(covered[i]>0);
		cout<<endl;
		return;
	}
};

int states[1050000];
queue<int> q;

int main(){
	cin>>n>>k>>m;
	memset(states, 0xff, sizeof(states));
	node initial{};
	for(int i=0;i<n;i++){
		int x;cin>>x;v.push_back(x);
		initial.set_color(i, (x==1));
	}

	w.resize(m);
	for(int i=0;i<m;i++){
		int sz;cin>>sz;
		for(int j=0;j<sz;j++){
			int x;cin>>x;w[i].push_back(x-1);
		}
	}

	states[initial.to_int()]=0;
	q.push(initial.to_int());
	while(!q.empty()){
		int curr_code=q.front();
		node curr(curr_code);
		// cout<<"SP: "<<states[curr_code]<<"	";
		// curr.print();
		q.pop();
		if (curr.check_color() && !curr.check_equipped()){
			cout<<states[curr.to_int()]<<endl;
			return 0;
		}

		for(int i=0;i<m;i++){
			curr.switch_equip(i);
			int code=curr.to_int();
			if (states[code]==-1){
				states[code]=states[curr_code]+1;
				q.push(code);
			}
			curr.switch_equip(i);
		}

		if (!curr.check_color()){
			node tmp=node(curr_code);
			for(int i=1;i<=k;i++){
				for(int j=0;j<n;j++){
					if (!curr.check_covered(j)){
						tmp.set_color(j, (i==v[j]));
					}
				}
				int code=tmp.to_int();
				if (states[code]==-1){
					states[code]=states[curr_code]+1;
					q.push(code);
				}
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}
