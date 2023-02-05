#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
typedef long double ld;
int N;
struct card{
	int a,b,c,d,id;
	card(){}
	card(int x1, int x2, int x3, int x4, int i){
		a=x1;b=x2;c=x3;d=x4;id=i;
	}
	bool operator< (card y){
		if (a!=y.a) return a<y.a;
		if (b!=y.b) return b<y.b;
		if (c!=y.c) return c<y.c;
		if (d!=y.d) return d<y.d;
		return id<y.id;
	}
	bool operator== (card y){
		return id==y.id;
	}
};
vector<card> inside;
vector<card> side;
vector<card> corner;
vector<card> oneLineCorner;
vector<card> oneLineSide;
vector<card> counter[700100];
int mark = 0;
bool vis[300100];
card rotToA(card x, int val){
	if (x.d==val) return card(x.d, x.a, x.b, x.c, x.id);
	if (x.a==val) return x;
	if (x.b==val) return card(x.b, x.c, x.d, x.a, x.id);
	if (x.c==val) return card(x.c, x.d, x.a, x.b, x.id);
	return x;
}
card rotToB(card x, int val){
	if (x.a==val) return card(x.d, x.a, x.b, x.c, x.id);
	if (x.b==val) return x;
	if (x.c==val) return card(x.b, x.c, x.d, x.a, x.id);
	if (x.d==val) return card(x.c, x.d, x.a, x.b, x.id);
	return x;
}
card rotToC(card x, int val){
	if (x.b==val) return card(x.d, x.a, x.b, x.c, x.id);
	if (x.c==val) return x;
	if (x.d==val) return card(x.b, x.c, x.d, x.a, x.id);
	if (x.a==val) return card(x.c, x.d, x.a, x.b, x.id);
	return x;
}
card rotToD(card x, int val){
	if (x.c==val) return card(x.d, x.a, x.b, x.c, x.id);
	if (x.d==val) return x;
	if (x.a==val) return card(x.b, x.c, x.d, x.a, x.id);
	if (x.b==val) return card(x.c, x.d, x.a, x.b, x.id);
	return x;
}
bool update(int a, int b, int c, int d, int id){
	card nw = card(a,b,c,d,id);
	if (card(b,c,d,a,id)<nw) nw = card(b,c,d,a,id);
	if (card(c,d,a,b,id)<nw) nw = card(c,d,a,b,id);
	if (card(d,a,b,c,id)<nw) nw = card(d,a,b,c,id);
	int cnt=(a==0)+(b==0)+(c==0)+(d==0);
	if (cnt==0){
		if (mark==2) return false;
		mark=1;
		inside.push_back(nw);
	}else if (cnt==1){
		if (mark==2) return false;
		mark=1;
		side.push_back(nw);
	}else if (cnt==2){
		if (nw.c==0){
			if (mark==1) return false;
			mark=2;
			oneLineSide.push_back(nw);
		}else{
			if (mark==2) return false;
			mark=1;
			corner.push_back(nw);
		}
	}else if (cnt==3){
		if (mark==1) return false;
		mark=2;
		oneLineCorner.push_back(nw);
	}else return false;
	if (nw.a!=0) counter[nw.a].push_back(nw);
	if (nw.b!=0) counter[nw.b].push_back(nw);
	if (nw.c!=0) counter[nw.c].push_back(nw);
	if (nw.d!=0) counter[nw.d].push_back(nw);
	return true;
}
bool getanswer(int n, int m){
//	printf("%d %d", n, m);
	memset(vis,0,sizeof(vis));
	vector<vector<card> > ans;ans.clear();
	for(int i=0;i<n;i++){
		vector<card> v;v.clear();
		ans.push_back(v);
	}
	ans[0].push_back(corner[0]);
	vis[corner[0].id]=1;
	card prev = corner[0];
	for(int j=1;j<m;j++){
		card cur = counter[prev.d][0];
		if (cur==prev) cur = counter[prev.d][1];
		cur=rotToB(cur, prev.d);
		if (vis[cur.id]) return false;
		vis[cur.id]=1;
		if (cur.a!=0 || cur.c==0 || ((j+1==m) ^ (cur.d==0))) return false;
		ans[0].push_back(cur);
		prev = cur;
	}
//	printf("\nLine %d:\n", 0);
//	for(int j=0;j<m;j++) printf("%d ", ans[0][j].id);
	for(int i=1;i<n;i++){
		prev = counter[ans[i-1][0].c][0];
		if (prev==ans[i-1][0]) prev = counter[ans[i-1][0].c][1];
		ans[i].push_back(rotToA(prev, ans[i-1][0].c));
		if (ans[i][0].b!=0 || ans[i][0].d==0 || ((i+1==n) ^ (ans[i][0].c==0))) return false;
		if (vis[ans[i][0].id]) return false;
		vis[ans[i][0].id]=1;
		prev = ans[i][0];
//		puts("YES");
		for(int j=1;j<m;j++){
			card cur = counter[prev.d][0];
			if (cur==prev) cur = counter[prev.d][1];
//			printf(" %d", cur.id);
			cur = rotToB(cur, prev.d);
			if (vis[cur.id]) return false;
			vis[cur.id]=1;
			ans[i].push_back(cur);
			if (cur.a!=ans[i-1][j].c || ((i+1==n) ^ (cur.c==0)) || ((j+1==m) ^ (cur.d==0))) return false;
			prev = cur;
		}
//		printf("\nLine %d:\n", i);
//		for(int j=0;j<m;j++) printf("%d ", ans[i][j].id);
	}
	printf("%d %d\n", n, m);
	for(int i=0;i<n;i++){
		printf("%d", ans[i][0].id);
		for(int j=1;j<m;j++){
			printf(" %d", ans[i][j].id);
		}
		puts("");
	}
	return true;
}
int main(){
	scanf("%d", &N);
	if (N==1){
		int a,b,c,d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (a==0 && b==0 && c==0 && d==0){
			puts("1 1\n1");
			return 0;
		}else{
			puts("impossible");
			return 0;
		}
	}
	for(int i=0;i<N;i++){
		int a,b,c,d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (!update(a,b,c,d,i+1)){
			puts("impossible");
			return 0;
		}
	}
//	printf("%d\n", mark);
	if (mark==1){
		if (corner.size()!=4){
			puts("impossible");
			return 0;
		}
//		printf("%d\n", side.size());
		if (side.size()&1){
			puts("impossible");
			return 0;
		}
		ll ltr = ((ll)side.size()/2)+4;
		ll l_r2 = ltr*ltr-(N<<2);
		if (l_r2<0){
			puts("impossible");
			return 0;
		}
		ll l_r = sqrt((ld)l_r2);
//		printf("%d\n", l_r);
		if (l_r*l_r!=l_r2){
			puts("impossible");
			return 0;
		}
		if ((ltr+l_r)&1){
			puts("impossible");
			return 0;
		}
		int n = (ltr+l_r)>>1;
		int m = n-l_r;
//		printf("%d %d\n", n, m);
		if (!getanswer(n,m) && !getanswer(m,n)){
			puts("impossible");
			return 0;
		}
	}else if (mark==2){
		if (oneLineCorner.size()!=2){
			puts("impossible");
			return 0;
		}
		vector<card> ans;ans.clear();
		card prev = oneLineCorner[0];
		vis[prev.id]=1;
		ans.push_back(prev);
		for(int i=1;i<N;i++){
			card cur = counter[prev.d][0];
			if (cur==prev) cur = counter[prev.d][1];
			if (vis[cur.id]){
				puts("impossible");
				return 0;
			}
			vis[cur.id]=1;
			cur = rotToB(cur, prev.d);
			if (cur.a!=0 || cur.c!=0 || cur.b!=prev.d || ((i+1==N) ^ (cur.d==0))){
				puts("impossible");
				return 0;
			}
			ans.push_back(cur);
			prev = cur;
		}
		printf("1 %d\n%d", N, ans[0].id);
		for(int i=1;i<ans.size();i++){
			printf(" %d", ans[i].id);
		}puts("");
	}
	return 0;
}
