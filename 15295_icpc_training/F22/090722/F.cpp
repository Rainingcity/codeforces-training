#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef pair<int,int> pii;

struct node{
	node *left, *right;
	int id;
	node(){
		left=right=NULL;
		id=-1;
	}
};

void add(node* curr, int target, int id){
	if (target==0){
		curr->id=id;
		return;
	}
	if (target&1){
		if (curr->right==NULL) curr->right=new node();
		add(curr->right, target>>1, id);
	}else{
		if (curr->left==NULL) curr->left=new node();
		add(curr->left, target>>1, id);
	}
}

int ans=0,axid,ayid;
pii rec(node* curr, bool dir, bool zero){
	if (curr==NULL) return make_pair(-100,-1);
	pii lprev=rec(curr->left, false, zero);
	pii rprev=rec(curr->right, true, false);
	if (curr->id!=-1){
		if (lprev.first>ans){
			ans=lprev.first;
			axid=lprev.second;
			ayid=curr->id;
		}
		if (rprev.first>ans){
			ans=rprev.first;
			axid=rprev.second;
			ayid=curr->id;
		}
	}

	if (dir){
		if (lprev.first+rprev.first>ans){
			ans=lprev.first+rprev.first;
			axid=lprev.second;
			ayid=rprev.second;
		}
	}else{
		if (zero){
			if (lprev.first+rprev.first-1>ans){
				ans=lprev.first+rprev.first-1;
				axid=lprev.second;
				ayid=rprev.second;
			}
		}else{
			if (lprev.first+rprev.first+1>ans){
				ans=lprev.first+rprev.first+1;
				axid=lprev.second;
				ayid=rprev.second;
			}
		}
	}

	if (dir) lprev.first++;
	else rprev.first++;
	pii prev=(lprev.first>rprev.first?lprev:rprev);
	if (curr->id!=-1 && prev.first<1) prev=make_pair(1, curr->id);
	return prev;
}

int main(){
	int n;cin>>n;
	node* head=new node();
	for(int i=0;i<n;i++){
		int x;cin>>x;
		add(head, x, i+1);
	}
	rec(head, true, true);
	cout<<axid<<" "<<ayid<<" "<<ans<<endl;
	return 0;
}
