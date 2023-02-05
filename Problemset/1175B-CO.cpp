/*
 * Codeforces 1175B
 * Catch Overflow!
 */

#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
typedef long long ll;
const long long UIntMx = (1ll<<32)-1;
struct status{
	ll iter;
	ll res;
	status(): iter(0), res(0){}
	status(ll i, ll j): iter(i), res(j){}
};
stack<status> st;
int n;
int main(){
	cin>>n;
	st.push(status(1,0));
	while(n--){
		string op;cin>>op;
		if (op=="for"){
			int x;cin>>x;
			st.push(status(x,0));
		}else if (op=="add"){
			status cur = st.top();st.pop();
			cur.res++;
			if (cur.res>UIntMx){
				puts("OVERFLOW!!!");
				return 0;
			}
			st.push(cur);
		}else if (op=="end"){
			status cur = st.top();st.pop();
			status nxt = st.top();st.pop();
			nxt.res += cur.iter * cur.res;
			if (nxt.res>UIntMx){
				puts("OVERFLOW!!!");
				return 0;
			}
			st.push(nxt);
		}else return 0;
	}
	status lst = st.top();
	cout<<lst.res<<endl;
	return 0;
}
