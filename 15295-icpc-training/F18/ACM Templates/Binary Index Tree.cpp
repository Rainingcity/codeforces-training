template <typename T>
class Binary_Index_Tree{
private:
    T* a;
    int n;
public:
    Binary_Index_Tree(int len){
        n=len;
        a=new T[2*n];
    }
    int inc(int i){
        return i&(-i);
    }
    void init(T dat[]){
        for(int i=0;i<n;i++){
            a[i+1]=dat[i];
        }
        for(int i=1;i<=n;i++){
            int j=i+inc(i);
            if (j<=n){
                a[j]=a[j]+a[i];
            }
        }
    }
    void update(T num,int pos){
        pos+=1;
        while(pos<=n){
            a[pos]=a[pos]+num;
            pos+=inc(pos);
        }return;
    }
    T prefSum(int pos){
        pos+=1;
        T ans=a[pos];
        pos-=inc(pos);
        while(pos>0){
            ans=ans+a[pos];
            pos-=inc(pos);
        }return ans;
    }
    T rangeSum(int l,int r){
        return prefSum(r)-prefSum(l-1);
    }
};
