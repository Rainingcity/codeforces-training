#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;
const int MOD = 1e9+7;
typedef pair<int,int> pii;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const
    {
        return std::hash<T1>()(pair.first) * 100000 + std::hash<T2>()(pair.second);
    }
};

int n;
unordered_set<pii, pair_hash> box;
unordered_map<pii, int, pair_hash> dp;

int calc_rec(int x, int y){
	pii pos = make_pair(x, y);
	if (dp.find(pos) != dp.end()) return dp[pos];
	if (box.find(pos) == box.end()){
		dp[pos] = 0;
		return 0;
	}
	int ans = (calc_rec(x+1, y) + calc_rec(x, y+1))%MOD;
	if (ans == 0) ans = 1;
	dp[pos]=ans;
	return ans;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;cin>>x>>y;
		box.insert(pii(x,y));
	}
	cout<<calc_rec(1,1)<<endl;
}
