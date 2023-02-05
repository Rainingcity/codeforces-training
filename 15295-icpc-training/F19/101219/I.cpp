#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dat[4];
int ord[24][4]={{0,1,2,3},{0,1,3,2},{0,2,1,3},{0,2,3,1},{0,3,1,2},{0,3,2,1},
				{1,0,2,3},{1,0,3,2},{1,2,0,3},{1,2,3,0},{1,3,0,2},{1,3,2,0},
				{2,0,1,3},{2,0,3,1},{2,1,0,3},{2,1,3,0},{2,3,0,1},{2,3,1,0},
				{3,0,1,2},{3,0,2,1},{3,1,0,2},{3,1,2,0},{3,2,0,1},{3,2,1,0}};
int op[64][3]= {{0,0,0},{0,0,1},{0,0,2},{0,0,3},
				{0,1,0},{0,1,1},{0,1,2},{0,1,3},
				{0,2,0},{0,2,1},{0,2,2},{0,2,3},
				{0,3,0},{0,3,1},{0,3,2},{0,3,3},
				{1,0,0},{1,0,1},{1,0,2},{1,0,3},
				{1,1,0},{1,1,1},{1,1,2},{1,1,3},
				{1,2,0},{1,2,1},{1,2,2},{1,2,3},
				{1,3,0},{1,3,1},{1,3,2},{1,3,3},
				{2,0,0},{2,0,1},{2,0,2},{2,0,3},
				{2,1,0},{2,1,1},{2,1,2},{2,1,3},
				{2,2,0},{2,2,1},{2,2,2},{2,2,3},
				{2,3,0},{2,3,1},{2,3,2},{2,3,3},
				{3,0,0},{3,0,1},{3,0,2},{3,0,3},
				{3,1,0},{3,1,1},{3,1,2},{3,1,3},
				{3,2,0},{3,2,1},{3,2,2},{3,2,3},
				{3,3,0},{3,3,1},{3,3,2},{3,3,3}};
int op_ord[6][3]={{0,0,0},{0,1,0},{1,0,0},{1,1,0},{2,0,0},{2,1,0}};
int oper_ord[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
int swap_score[24]={0,1,1,2,2,3,1,2,2,3,3,4,2,3,3,4,4,5,3,4,4,5,5,6};
int op_score[8][6]={{0,1,1,1,1,2},{1,0,2,1,0,1},
					{1,2,0,1,2,1},{1,2,1,0,2,1},
					{0,1,1,1,1,2},{1,0,1,2,0,1},
					{0,1,1,1,1,2},{0,1,1,1,1,2}};
int op_priority[4]={0,0,1,1};
int tmp[4];
int calc(int x, int y, int op){
	switch(op){
		case 0:
			return x+y;
		case 1:
			return x-y;
		case 2:
			return x*y;
		case 3:
			if (y==0) return -10000;
			if (x%y==0) return x/y;
			else return -10000;
		default:
			return -10000;
	}
	return -10000;
}
int calc_priority(int x, int y, int z){
	return op_priority[x]*4+op_priority[y]*2+op_priority[z];
}
string output_op(int op){
	switch(op){
		case 0: return "+";
		case 1: return "-";
		case 2: return "*";
		case 3: return "/";
		default: return "";
	}
	return "";
}
int main(){
	cin>>dat[0]>>dat[1]>>dat[2]>>dat[3];
	int mi=10000;
	for(int i=0;i<24;i++){
		for(int j=0;j<64;j++){
			for(int k=0;k<6;k++){
				tmp[0]=dat[ord[i][0]];
				tmp[1]=dat[ord[i][1]];
				tmp[2]=dat[ord[i][2]];
				tmp[3]=dat[ord[i][3]];
				int l;
				for (l=0;l<3;l++){
					int cur=op_ord[k][l];
					tmp[cur]=calc(tmp[cur],tmp[cur+1],op[j][oper_ord[k][l]]);
					if (tmp[cur]==-10000) break;
					for(int it=cur+1;it<3-l;it++) tmp[it]=tmp[it+1];
				}
				if (tmp[0]!=24 || l!=3) continue;
				int cur_score=swap_score[i]*2+op_score[calc_priority(op[j][0],op[j][1],op[j][2])][k];
				if (mi>cur_score) mi=cur_score;
				// cout<<dat[ord[i][0]]<<" "<<dat[ord[i][1]]<<" "<<dat[ord[i][2]]<<" "<<dat[ord[i][3]]<<endl;
				// cout<<" "<<output_op(op[j][0])<<" "<<output_op(op[j][1])<<" "<<output_op(op[j][2])<<endl;
				// cout<<" "<<oper_ord[k][0]<<" "<<oper_ord[k][1]<<" "<<oper_ord[k][2]<<endl;
				// cout<<cur_score<<endl;
			}
		}
	}
	if (mi==10000){
		cout<<"impossible"<<endl;
	}else{
		cout<<mi<<endl;
	}
	return 0;
}
