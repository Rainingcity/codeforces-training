template <typename T>
class Max_Heap{
private:
    int len;
    T[] a;
public:
    Max_Heap(){
        len=0;
        a=new T[];
    }
    void up(int pos){
        if (pos==0) return;
        int nxt=pos>>1;
        if (a[nxt]<a[pos]){
            T t=a[pos];a[pos]=a[nxt];a[nxt]=t;
            up(nxt);
        }else return;
    }
    void down(int pos){
        if (pos>=len) return;
        int nxt=(pos<<1)+1;
        if (nxt>=len) return;
        if (nxt+1<len && a[nxt]<a[nxt+1]) nxt++;
        if (a[nxt]>a[pos]){
            T t=a[pos];a[pos]=a[nxt];a[nxt]=t;
            down(nxt);
        }
    }
    void push(T x){
        a[len++]=x;
        up(len-1);
    }
    T pop(){
        T x=a[0];
        a[0]=a[--len];
        down(0);
        return x;
    }
    T front(){
        return a[0];
    }
};
