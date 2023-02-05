/*
 * Codeforces 1169B
 * Pairs
 */

#include<cstdio>
#include<set>
#include<algorithm>
#define MP(x,y) make_pair((x),(y))
using namespace std;
typedef pair<int,int> pii;
set<pii> st;
struct dat{
	int x;
	int id;
	bool operator< (dat y){
		if (x!=y.x) return x < y.x;
		else return id < y.id;
	}
};
dat cnt[300300];
int n,m;
bool cmp(dat x, dat y){
	if (x.x!=y.x) return x.x>y.x;
	else return x.id>y.id;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++) cnt[i].id=i;
	for(int i=0;i<m;i++){
		int x,y;scanf("%d%d", &x, &y);x--;y--;
		pii k = MP(x,y);
		if (st.find(k)!=st.end()){
			i--;m--;
			continue;
		}
		st.insert(k);
		st.insert(MP(y,x));
		cnt[x].x++;
		cnt[y].x++;
	}
	sort(cnt,cnt+n,cmp);
	for(int i=1;i<n && cnt[0].x+cnt[i].x>=m;i++){
		if (cnt[0].x+cnt[i].x-(st.find(MP(cnt[0].id,cnt[i].id))!=st.end())>=m){
			puts("YES");
			return 0;
		}
	}
	for(int i=2;i<n && cnt[1].x+cnt[i].x>=m;i++){
		if (cnt[1].x+cnt[i].x-(st.find(MP(cnt[1].id,cnt[i].id))!=st.end())>=m){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}
