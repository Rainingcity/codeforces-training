#include<cstring>
using namespace std;

template <typename T>
inline T maxi(T const& x, T const& y){return x<y?y:x;}
int absi(int x){return x<0?-x:x;}

template <class T> class AVL_node {
private:
	T data;
	int dep;
public:
	AVL_node<T>* lc;
	AVL_node<T>* rc;

	AVL_node(){
		data=0;dep=1;
		this->lc=this->rc=NULL;
	}

	AVL_node(T const& dat){
		data=dat;dep=1;
		this->lc=this->rc=NULL;
	}

	AVL_node(T const& dat, AVL_node<T>* l, AVL_node<T>* r){
		data=dat;
		lc=l;rc=r;
		this->update_depth();
	}

	T get_data() const{return data;}
	void set_data(T const& x){data=x;}
	int get_dep() const{return dep;}

	bool is_balanced(){
		return absi(calc_bal())<2;
	}

	int calc_bal() const{
		if (this->lc==NULL && this->rc==NULL) return 0;
		else if (this->lc==NULL) return -(this->rc->get_dep());
		else if (this->rc==NULL) return this->lc->get_dep();
		else return this->lc->get_dep()-this->rc->get_dep();
	}

	void update_depth(){
		if (this->lc==NULL && this->rc==NULL) dep=1;
		else if (this->lc==NULL) dep=this->rc->get_dep()+1;
		else if (this->rc==NULL) dep=this->lc->get_dep()+1;
		else dep=maxi(this->lc->get_dep(),this->rc->get_dep())+1;
	}

	AVL_node<T>* lSpin(){
		AVL_node<T>* tmp = this->rc;
		this->rc = this->rc->lc;
		tmp->lc = this;
		this->update_depth();
		tmp->update_depth();
		return tmp;
	}

	AVL_node<T>* rSpin(){
		AVL_node<T>* tmp = this->lc;
		this->lc = this->lc->rc;
		tmp->rc = this;
		this->update_depth();
		tmp->update_depth();
		return tmp;
	}
};
