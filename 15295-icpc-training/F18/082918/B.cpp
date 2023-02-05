#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
using namespace std;
struct country{
    char name[50];
    vector<int> v;
    country(){}
    country(char _name[]){
        strcpy(name, _name);
    }
}c[300];
int n,m,k=0;
bool dfs(int cur, int tar){
    if (cur == tar) return true;
    for(int i=0;i < c[cur].v.size();i++){
        if (dfs(c[cur].v[i], tar)) return true;
    }return false;
}
int main(){
    scanf("%d%d", &n, &m);
    char c1[50], c2[50];
    for(int i=0;i<n;i++){
        scanf("%s are worse than %s", c1, c2);
        int pos1 = -1, pos2 = -1;
        for(int i=0;i<k;i++){
            if (strcmp(c1,c[i].name) == 0){
                pos1=i;
            }
            if (strcmp(c2,c[i].name) == 0){
                pos2=i;
            }
        }
        if (pos1==-1){
            c[pos1=(k++)]=country(c1);
        }
        if (pos2==-1){
            c[pos2=(k++)]=country(c2);
        }
        c[pos1].v.push_back(pos2);
    }
    for(int i=0;i<m;i++){
        scanf("%s are worse than %s", c1, c2);
        int pos1=-1,pos2=-1;
        for(int i=0;i<k;i++){
            if (strcmp(c1,c[i].name) == 0){
                pos1=i;
            }
            if (strcmp(c2,c[i].name) == 0){
                pos2=i;
            }
        }
        if (pos1==-1 || pos2==-1){
            printf("Pants on Fire\n");
        }else{
            if (dfs(pos1,pos2)) printf("Fact\n");
            else if (dfs(pos2,pos1)) printf("Alternative Fact\n");
            else printf("Pants on Fire\n");
        }
    }
}
