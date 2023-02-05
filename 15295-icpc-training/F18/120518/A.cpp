#include <cstdio>
#include <cstring>
using namespace std;
class segTree{
private:
    int dat[6001000];
    int lastpos;
    int n;
public:
    void build(int id,int l,int r,int tar){
        if (l==r){
            if (l>=tar) dat[id]=1;
            else dat[id]=0;
            return;
        }
        int mid=(l+r)>>1;
        build(id<<1,l,mid,tar);
        build((id<<1)^1,mid+1,r,tar);
        dat[id]=dat[id<<1]+dat[(id<<1)^1];
    }
    segTree(){
        n=0;
        lastpos=0;
    }
    segTree(int szn,int szm){
        n=szn+szm;
        lastpos=szm-1;
        memset(dat,0,sizeof(dat));
        build(1,0,n-1,szm);
    }
    int fnd(int id,int l,int r,int tl,int tr){
        if (l==tl && r==tr) return dat[id];
        int mid=(l+r)>>1;
        int ans=0;
        if (tl<=mid && tr>mid) ans=fnd(id<<1,l,mid,tl,mid)+fnd((id<<1)^1,mid+1,r,mid+1,tr);
        else if (tr<=mid) ans=fnd(id<<1,l,mid,tl,tr);
        else ans=fnd((id<<1)^1,mid+1,r,tl,tr);
        return ans;
    }
    void update(int id,int l,int r,int tar,int val){
        if (l==r){
            dat[id]=val;
            return;
        }
        int mid=(l+r)>>1;
        if (tar<=mid) update(id<<1,l,mid,tar,val);
        else update((id<<1)^1,mid+1,r,tar,val);
        dat[id]=dat[id<<1]+dat[(id<<1)^1];
        return;
    }
    int update(int pos){
        update(1,0,n-1,pos,0);
        update(1,0,n-1,lastpos,1);
        return lastpos--;
    }
    int getpos(int pos){
        return fnd(1,0,n-1,0,pos-1);
    }
}st;
int n,m;
int curpos[1501000];
int main(){
    scanf("%d%d", &n, &m);
    st=segTree(n,m);
    for(int i=0;i<n;i++) curpos[i]=i+m;
    for(int i=0;i<m;i++){
        int op;scanf("%d", &op);
        if (i) printf(" ");
        printf("%d", st.getpos(curpos[op]));
        curpos[op]=st.update(curpos[op]);
    }puts("");
    return 0;
}
