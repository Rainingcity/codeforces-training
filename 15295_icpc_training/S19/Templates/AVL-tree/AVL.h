#include<cstring>
#include "AVL_node.cpp"
using namespace std;


template <class T> class AVL {
private:
	AVL_node<T>* rec_add(AVL_node<T>* cur, T const& x) const{
		if (cur==NULL){
			AVL_node<T>* nw = new AVL_node<T>(x);
			return nw;
		}
		T cur_data = cur->get_data();
		if (x==cur_data) return cur;
		else if (x<cur_data){
			cur->lc = rec_add(cur->lc, x);
			cur->update_depth();
			if (!cur->is_balanced()){
				if (x<(cur->lc->get_data())) return cur->rSpin();
				else{
					cur->lc=cur->lc->lSpin();
					return cur->rSpin();
				}
			}else return cur;
		}else{
			cur->rc = rec_add(cur->rc, x);
			cur->update_depth();
			if (!cur->is_balanced()){
				if ((cur->rc->get_data())<x) return cur->lSpin();
				else{
					cur->rc=cur->rc->rSpin();
					return cur->lSpin();
				}
			}else return cur;
		}
	}

	AVL_node<T>* rec_del(AVL_node<T>* cur, T const& x) const{
		if (cur->lc==NULL && cur->rc==NULL) return NULL;
		T cur_data = cur->get_data();
		if (x==cur_data){
			if (cur->lc!=NULL && cur->rc!=NULL){
				AVL_node<T>* f = cur->lc;
				while(f->rc!=NULL) f=f->rc;
				T f_data = f->get_data();
				cur->set_data(f_data);
				cur->lc=rec_del(cur->lc, f_data);
				cur->update_depth();
				if (!cur->is_balanced()){
					if (x<(cur->lc->get_data())) return cur->rSpin();
					else{
						cur->lc=cur->lc->lSpin();
						return cur->rSpin();
					}
				}else return cur;
			}else if (cur->lc==NULL){
				return cur->rc;
			}else return cur->lc;
		}else if (x<cur_data){
			cur->lc = rec_del(cur->lc, x);
			cur->update_depth();
			if (!cur->is_balanced()){
				if (x<(cur->lc->get_data())) return cur->rSpin();
				else{
					cur->lc=cur->lc->lSpin();
					return cur->rSpin();
				}
			}else return cur;
		}else{
			cur->rc = rec_del(cur->rc, x);
			cur->update_depth();
			if (!cur->is_balanced()){
				if ((cur->rc->get_data())<x) return cur->lSpin();
				else{
					cur->rc=cur->rc->rSpin();
					return cur->lSpin();
				}
			}else return cur;
		}
	}

	AVL_node<T>* look_up(AVL_node<T>* cur, T const& x) const{
		if (cur==NULL) return NULL;
		T cur_data = cur->get_data();
		if (x==cur_data) return cur;
		else if (x<cur_data) return look_up(cur->lc, x);
		else return look_up(cur->rc, x);
	}
protected:
	AVL_node<T>* head;
public:
	AVL(){
		head = NULL;
	}

	void add(T const& x){
		head = rec_add(head, x);
	}

	void del(T const& x){
		if (has_elem(x)) head = rec_del(head, x);
	}

	bool has_elem(T const& x) const{
		return look_up(head, x)!=NULL;
	}
};
