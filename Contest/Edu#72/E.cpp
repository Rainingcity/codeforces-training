#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int v[15][200100];
int n,m;
int dat[200100];
int Lowbit(int x)
{
	return x&(-x);
}
void update(int id, int i, int x)
{
	while(i <= n)
	{
		v[id][i] += x;
		i += Lowbit(i);
	}
}
int sum(int id, int i)
{
	int sum=0;
	while(i>0)
	{
		sum+=v[id][i];
		i-=Lowbit(i);
	}
	return sum;
}
int Getsum(int id, int x1, int x2)
{
    return sum(id, x2) - sum(id, x1-1);
}
void add(int i, int x){
	int id=0;
	while(x){
		int cur=x%10;
		update(id, i, cur);
		x/=10;id++;
	}
}
void del(int i, int x){
	int id=0;
	while(x){
		int cur=x%10;
		update(id, i, -cur);
		x/=10;id++;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>dat[i];
		add(i, dat[i]);
	}
}
