#include <iostream>
#include <unordered_set>
#include <utility>
using namespace std;
typedef long long ll;
int r,s,n;
bool dp[2][51][51];
ll a[51], b[51], c[110];
ll pa[52], pb[52], pc[52];

ll gcd(ll x, ll y){
	if (y==0) return x;
	return gcd(y, x%y);
}

ll gcdExtended(ll A, ll B, ll *x, ll *y) {
   if (A == 0) {
      *x = 0;
      *y = 1;
      return B;
   }
   ll x1, y1;
   ll gcd = gcdExtended(B%A, A, &x1, &y1);
   *x = y1 - (B/A) * x1;
   *y = x1;
   return gcd;
}

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

bool have_pos_solution(ll x, ll y, ll z){
	if (z==0) return true;
	ll g=gcd(x, y);
	if (z%g!=0) return false;
	ll A, B;
	g=gcdExtended(x, y, &A, &B);
	A*=z;
	B*=z;
	// cout<<x<<" "<<y<<" "<<A<<" "<<B<<" "<<z<<endl;
	if (A>=0 && B>=0) return true;
	ll tx=x/g, ty=y/g;
	if (A<0){
		ll times = A/ty;
		A=A+times*ty;
		B=B-times*tx;
		if (A<0){A+=ty;B-=tx;}
		return B>=0;
	}else{
		ll times = B/tx;
		A=A-times*ty;
		B=B+times*tx;
		if (B<0){A-=ty;B+=tx;}
		return A>=0;
	}
}

void trans(int cur, int nxt, ll x){
	for(int i=0;i<r;i++) for(int j=0;j<s;j++) dp[nxt][i][j]=false;
	unordered_set<pair<int,int>, hash_pair> st{};
	for(int i=0;i<r;i++) for(int j=0;j<s;j++) st.insert(make_pair(i,j));
	for(int i=0;i<r;i++){
		for(int j=0;j<s;j++){
			if (!dp[cur][i][j]) continue;
			for(auto& [ii, jj]: st){
				if (dp[nxt][ii][jj]) continue;
				ll sum=(i<=ii?pa[ii]-pa[i]:pa[r]-pa[i]+pa[ii])
					   +(j<=jj?pb[jj]-pb[j]:pb[s]-pb[j]+pb[jj]);
				if (sum>x) continue;
				sum=x-sum;
				// cout<<i<<" "<<j<<" "<<ii<<" "<<jj<<" "<<sum<<endl;
				if (have_pos_solution(pa[r], pb[s], sum)){
					dp[nxt][ii][jj]=true;
				}
			}
			for(auto it=st.begin();it!=st.end();){
				if (dp[nxt][it->first][it->second]) it=st.erase(it);
				else it++;
			}
		}
	}
}

int main(){
	cin>>r>>s>>n;
	for(int i=0;i<r;i++) cin>>a[i];
	for(int i=0;i<s;i++) cin>>b[i];
	for(int i=0;i<n;i++) cin>>c[i];
	pa[0]=0;
	for(int i=1;i<=r;i++){
		pa[i]=pa[i-1]+a[i-1];
	}
	pb[0]=0;
	for(int i=1;i<=s;i++){
		pb[i]=pb[i-1]+b[i-1];
	}
	dp[0][0][0]=true;
	for(int i=0;i<n;i++){
		bool cur = i&1;
		trans(cur, !cur, c[i]);
		// for(int j=0;j<r;j++){for(int k=0;k<s;k++) cout<<dp[!cur][j][k]<<" ";cout<<endl;}
	}
	int res=n&1;
	for(int i=0;i<r;i++){
		for(int j=0;j<s;j++){
			if (dp[res][i][j]){
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}
