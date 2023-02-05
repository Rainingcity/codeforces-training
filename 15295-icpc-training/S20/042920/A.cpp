#include <iostream>
#include <string>
using namespace std;
string s;
struct Node{
	char c;
	Node* next;
	Node* prev;
	Node(){
		c=0;next=NULL;prev=NULL;
	}
	Node(char _c){
		c=_c;next=NULL;prev=NULL;
	}
};
int main(){
	cin>>s;
	int n=s.length();
	Node *head=NULL, *cur=NULL;
	for(int i=0;i<n;i++){
		Node* nxt=new Node(s[i]);
		if (cur==NULL) head=cur=nxt;
		else{
			cur->next=nxt;
			nxt->prev=cur;
			cur=nxt;
		}
	}
	cur=head;
	while(cur!=NULL && cur->next!=NULL){
		if (cur->c==cur->next->c){
			Node* pre=cur->prev;
			Node* nxt=cur->next->next;
			free(cur);
			free(cur->next);
			if (pre==NULL){
				head=cur=nxt;
				if (nxt!=NULL) nxt->prev=NULL;
			}else{
				pre->next=nxt;
				cur=pre;
				if (nxt!=NULL) nxt->prev=pre;
			}
		}else cur=cur->next;
	}
	cur=head;
	while(cur!=NULL){
		cout<<cur->c;
		Node* cc=cur;
		cur=cur->next;
		free(cc);
	}
	cout<<endl;
	return 0;
}
