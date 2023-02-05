#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include "AVL.h"
using namespace std;

template <class T> class AVL_cl : public AVL<T> {
private:
	void rec_print(AVL_node<T>* cur){
		if (cur==NULL){
			cout<<"( 0 )";
			return;
		}
		cout<<"( "<<cur->get_data()<<" | ";
		rec_print(cur->lc);
		cout<<" | ";
		rec_print(cur->rc);
		cout<<" )";
	}
public:
	AVL_cl() : AVL<T>(){}

	void print(){
		cout<<"Current AVL status: ";
		rec_print(AVL<T>::head);
		cout<<endl;
	}
};

AVL_cl<string> b;

int main(){
	int op;
	puts("Input Format:");
	puts("\'1 x\' to add;");
	puts("\'2 x\' to delete;");
	puts("\'3 x\' to look up;");
	puts("\'0\'   to stop.");
	cin>>op;
	while(op!=0){
		string x;
		if (op==1){
			cin>>x;
			b.add(x);
		}else if (op==2){
			cin>>x;
			b.del(x);
		}else if (op==3){
			cin>>x;
			if (b.has_elem(x)) puts("Exist!"); else puts("Not Exist!");
		}else puts("Operation Undefined!");
		b.print();
		cin>>op;
	}
	return 0;
}
