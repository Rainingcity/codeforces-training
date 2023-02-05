#include <cstdio>
#include <set>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int,int> pii;

int n,k,q;
set<pii> st;
vector<int> v{};
int main(){
	st.clear();
	scanf("%d%d%d", &n, &k, &q);
	for(int i=0;i<n;i++){
		int x;scanf("%d", &x);
		v.push_back(x);
	}

	int cnt=0;
	for(int i=0;i<q;i++){
		int typ, id;
		scanf("%d%d", &typ, &id);
		if (typ==1){
			st.insert(make_pair(v[id-1], id));
			if (cnt==k) st.erase(st.begin());
			else cnt++;
		}else{
			if (st.find(make_pair(v[id-1], id))!=st.end()){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	return 0;
}
