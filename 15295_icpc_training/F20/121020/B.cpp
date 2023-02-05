#include <iostream>
#include <set>
using namespace std;
int digit[4];
int permutation[24][4]={{0,1,2,3}, {0,1,3,2}, {0,2,1,3}, {0,2,3,1}, {0,3,1,2}, {0,3,2,1},
						{1,0,2,3}, {1,0,3,2}, {1,2,0,3}, {1,2,3,0}, {1,3,0,2}, {1,3,2,0},
						{2,0,1,3}, {2,0,3,1}, {2,1,0,3}, {2,1,3,0}, {2,3,0,1}, {2,3,1,0},
						{3,0,1,2}, {3,0,2,1}, {3,1,0,2}, {3,1,2,0}, {3,2,0,1}, {3,2,1,0}};
set<int> ans{};

int count(int* num, int* sign, int mx_num, int mx_sign){
	if (mx_sign==1){
		if (sign[0]==1) return num[0]+num[1];
		if (sign[0]==2) return num[0]-num[1];
		if (sign[0]==3) return num[0]*num[1];
	}else if (mx_sign==2){
		if (sign[1]==3){
			int tmp=num[1]*num[2];
			if (sign[0]==1) return num[0]+tmp;
			if (sign[0]==2) return num[0]-tmp;
			if (sign[0]==3) return num[0]*tmp;
		}else if (sign[0]==3){
			int tmp=num[0]*num[1];
			if (sign[1]==1) return tmp+num[2];
			if (sign[1]==2) return tmp-num[2];
			if (sign[1]==3) return tmp*num[2];
		}else{
			int tmp=(sign[0]==1?num[0]+num[1]:num[0]-num[1]);
			return (sign[1]==1?tmp+num[2]:tmp-num[2]);
		}
	}else{
		if (sign[2]==3){
			num[2]=num[2]*num[3];
			return count(num, sign, mx_num-1, mx_sign-1);
		}else{
			int prev=count(num, sign, mx_num-1, mx_sign-1);
			return (sign[2]==1?prev+num[3]:prev-num[3]);
		}
	}
	return -1;
}

int main(){
	for(int i=0;i<4;i++) cin>>digit[i];
	for(int i=0;i<24;i++){
		int temp_digit[4];
		for(int j=0;j<4;j++) temp_digit[j]=digit[permutation[i][j]];
		for(int s1=0;s1<4;s1++){
			for(int s2=0;s2<4;s2++){
				for(int s3=0;s3<4;s3++){
					if (s1==0 && s2==0 && s3==0) continue;
					int num[4]={0,0,0,0};
					int cur_num=0;
					int sign[3]={0,0,0};
					int cur_sign=0;
					num[cur_num]=temp_digit[0];
					if (s1==0){
						num[cur_num]*=10;
						num[cur_num]+=temp_digit[1];
					}else{
						cur_num++;
						num[cur_num]=temp_digit[1];
						sign[cur_sign++]=s1;
					}
					if (s2==0){
						num[cur_num]*=10;
						num[cur_num]+=temp_digit[2];
					}else{
						cur_num++;
						num[cur_num]=temp_digit[2];
						sign[cur_sign++]=s2;
					}
					if (s3==0){
						num[cur_num]*=10;
						num[cur_num]+=temp_digit[3];
					}else{
						cur_num++;
						num[cur_num]=temp_digit[3];
						sign[cur_sign++]=s3;
					}
					cur_num++;
					int cur = count(num, sign, cur_num, cur_sign);
					if (cur<0) continue;
					ans.insert(cur);
				}
			}
		}
	}
	cout<<ans.size()<<endl;
}
