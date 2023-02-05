#include<cstdio>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
int maxi(int x,int y){return x<y?y:x;}
/*
n,q as stated in the problem
pos[]: the position of each domino
hei[]: the height of each domino
par[]: the previous domino in the chain
dis[]: the farthest distance the dominos in the chain (from this domino to the head of the chain) can reach
pre[]: the minimum extension length needed to reach the last domino (actually we can also maintain answers inside prefix doubling)
fat[][]: the 2^k previous chain in prefix doubling
head[]: the head element of every list
nHead: the number of lists in L
v[]: the list of lists (it is enough to only maintain the most recent domino in the chain)
vn: current list
*/
int n,q;
int pos[200200],hei[200200],par[200200],dis[200200],pre[200200],fat[200200][20];
int head[200200],nHead;
int v[200200],vn;

//Binary Search to find out the farthest domino one domino can reach by itself
int binSearch(int tar,int st){
    int le=st,ri=n-1;
    while(le<ri){
        int mid=(le+ri+1)>>1;
        if (pos[mid]==tar) return mid;
        if (pos[mid]<tar) le=mid;
        else ri=mid-1;
    }return le;
}

int main(){
    //input
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d%d", pos+i, hei+i);
    }

    //set up the last domino because it can only reach itself
    v[0]=n-1;vn=1;
    head[nHead++]=n-1;
    par[n-1]=n-1;
    dis[n-1]=pos[n-1]+hei[n-1];

    //iterate from the last to the first domino
    for(int i=n-2;i>=0;i--){
        int t=binSearch(pos[i]+hei[i],i);
        if (i==t){//if it can only reach itself, then add a new list
            par[i]=i;
            dis[i]=pos[i]+hei[i];
            head[nHead++]=i;
        }else{//if it can reach others, find the oldest list we added
            while(vn>0 && v[--vn]<=t);//it can be replaced by binary search, but not so necessary
            if (v[vn]>t) vn++;
            int tpre=v[vn];
            par[i]=par[tpre];//record the chain
            dis[i]=maxi(dis[tpre],pos[i]+hei[i]);//calculate the farthest distance that this chain can reach
        }
        v[vn++]=i;//update the chain
    }

    //minimum extension length needed to reach the last domino
    pre[n-1]=0;
    for(int i=n-2;i>=0;i--){
        //the head of the current chain reaches the next domino with some length
        //and the next domino reaches the last domino with some length
        pre[i]=pre[par[i]+1]+pos[par[i]+1]-dis[i];
    }

    //construct prefix doubling
    int fatSz=0;
    fat[n-1][0]=n-1;
    for(int i=1;i<nHead;i++){//the head of each chain reaches the next domino
        int curHead=head[i];
        fat[curHead][0]=par[curHead+1];
    }
    for(int k=1;k<20;k++){//prefix doubling
        bool F=false;
        for(int i=0;i<nHead;i++){
            int curHead=head[i];
            fat[curHead][k]=fat[fat[curHead][k-1]][k-1];
            if (fat[curHead][k]!=n-1) F=true;
        }
        if (!F){
            fatSz=k+1;
            break;
        }
    }

    //answer queries
    scanf("%d", &q);
    for(int i=0;i<q;i++){
        int x,y;scanf("%d%d", &x, &y);x--;y--;
        //reaches y means reaches the chain whose head is larger than or equal to y
        int x1=par[x];
        if (x1>=y){//this chain already covers y
            puts("0");
            continue;
        }
        //search by prefix doubling
        //O(logn) time
        int it=0;
        while(it<fatSz && fat[x1][it]<y) it++;
        it--;
        while(it>=0){
            x1=fat[x1][it];
            while(it>=0 && fat[x1][it]>=y) it--;
        }
        printf("%d\n", pre[x]-pre[x1+1]);//x1+1 is equivalent to fat[x1][0] in this case according to procedures above
    }return 0;
}
