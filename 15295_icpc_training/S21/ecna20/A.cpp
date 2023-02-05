#include <iostream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

map<string, int> mp;
vector<string> names;
int map_cnt=0;

int getNameId(string name){
	if (mp.find(name)==mp.end()){
		mp[name]=map_cnt++;
		names.push_back(name);
	}
	return mp[name];
}

int n,q;
vector<int> v[110];
int rootCand[110];
int par[110];
int f[110];

void dfs(int cur, int prev){
	par[cur]=prev;
	for(int i=0;i<v[cur].size();i++){
		int nxt=v[cur][i];
		dfs(nxt, cur);
	}
}

string getNum(int x){
	if (x%10==1 && x!=11) return "st";
	if (x%10==2 && x!=12) return "nd";
	if (x%10==3 && x!=13) return "rd";
	return "th";
}

int main(){
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string s;int k;cin>>s>>k;
		int id=getNameId(s);
		if (!rootCand[id]) rootCand[id]=1;
		for(int j=0;j<k;j++){
			cin>>s;
			int jd=getNameId(s);
			rootCand[jd]=2;
			v[id].push_back(jd);
		}
	}
	int root=0;
	for(int i=0;i<map_cnt && !root;i++) if (rootCand[i]==1) root=i;
	dfs(root, root);
	// for(int i=0;i<map_cnt;i++) cout<<i<<" "<<par[i]<<endl;
	for(int cnt=0;cnt<q;cnt++){
		string s,t;cin>>s>>t;
		string os=s, ot=t;
		int x=getNameId(s), y=getNameId(t);
		// cout<<x<<" "<<y<<endl;
		memset(f, 0, sizeof(f));
		int itx=x, ity=y;
		int cans = root;
		bool rx=true, ry=true;
		int i;
		int status=-1;
		for(i=1;true;i++){
			// cout<<i<<" "<<itx<<" "<<ity<<endl;
			if (itx!=-1 && f[itx]==0 && itx==ity){
				cans=itx;
				status=0;
				break;
			}
			if (itx!=-1 && f[itx]!=0){
				cans=itx;
				status=1;
				break;
			}
			if (ity!=-1 && f[ity]!=0){
				cans=ity;
				status=2;
				break;
			}
			if (itx!=-1){
				f[itx]=i;
				if (itx==root){
					itx=-1;
				}else{
					itx=par[itx];
				}
			}
			if (ity!=-1){
				f[ity]=i;
				if (ity==root){
					ity=-1;
				}else{
					ity=par[ity];
				}
			}
		}
		// cout<<itx<<" "<<ity<<endl;
		int ansx, ansy;
		if (status==0){
			ansx=i;
			ansy=i;
		}else if (status==1){
			ansy=f[cans];
			ansx=i;
		}else{
			ansx=f[cans];
			ansy=i;
		}
		ansx--;ansy--;
		// cout<<ansx<<" "<<ansy<<" "<<status<<endl;
		if (ansx>ansy){
			string tmp=s;s=t;t=tmp;
			int tmpi=x;x=y;y=tmpi;
			tmpi=ansx;ansx=ansy;ansy=tmpi;
		}
		if (ansx==0){
			if (ansy==1){
				cout<<t<<" is the child of "<<s<<endl;
			}else{
				cout<<t<<" is the ";
				for(int i=2;i<ansy;i++){
					cout<<"great ";
				}
				cout<<"grandchild of "<<s<<endl;
			}
		}else if (ansx==ansy){
			if (ansy==1){
				cout<<os<<" and "<<ot<<" are siblings"<<endl;
			}else{
				cout<<os<<" and "<<ot<<" are "<<ansx-1<<getNum(ansx-1)<<" cousins"<<endl;
			}
		}else{
			cout<<os<<" and "<<ot<<" are "<<ansx-1<<getNum(ansx-1)<<" cousins, "<<ansy-ansx<<" time"<<(ansy-ansx==1?"":"s")<<" removed"<<endl;
		}
	}
	return 0;
}

