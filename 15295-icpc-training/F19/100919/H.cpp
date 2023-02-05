#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int maxi(int x, int y){return x<y?y:x;}
int n;
int dat[200];
int dp[300][30];
int calc(int x1, int x2, int x3, int x4, int x5, int i){
	int cnt[7];
	for(int j=0;j<7;j++) cnt[j]=0;
	cnt[x1]++;cnt[x2]++;cnt[x3]++;cnt[x4]++;cnt[x5]++;
	switch(i){
		case 1:
			return cnt[1];
			break;
		case 2:
			return 2*cnt[2];
			break;
		case 3:
			return 3*cnt[3];
			break;
		case 4:
			return 4*cnt[4];
			break;
		case 5:
			return 5*cnt[5];
			break;
		case 6:
			return 6*cnt[6];
			break;
		case 7:
			for(int j=1;j<=6;j++) if (cnt[j]>=3) return x1+x2+x3+x4+x5;
			return 0;
			break;
		case 8:
			for(int j=1;j<=6;j++) if (cnt[j]>=4) return x1+x2+x3+x4+x5;
			return 0;
			break;
		case 9:
			for(int j=1;j<=6;j++){
				if (cnt[j]>=4) return 0;
				if (cnt[j]==3){
					for(int k=1;k<=6;k++){
						if (k==j) continue;
						if (cnt[k]==2) return 25;
					}
					return 0;
				}
			}
			return 0;
			break;
		case 10:
			if (cnt[1] && cnt[2] && cnt[3] && cnt[4]) return 30;
			if (cnt[5] && cnt[2] && cnt[3] && cnt[4]) return 30;
			if (cnt[5] && cnt[6] && cnt[3] && cnt[4]) return 30;
			return 0;
			break;
		case 11:
			if (cnt[1] && cnt[2] && cnt[3] && cnt[4] && cnt[5]) return 40;
			if (cnt[5] && cnt[2] && cnt[3] && cnt[4] && cnt[6]) return 40;
			break;
		case 12:
			return x1+x2+x3+x4+x5;
			break;
		case 13:
			if (x1==x2 && x2==x3 && x3==x4 && x4==x5) return 50;
			else return 0;
			break;
		default:
			return 0;
	}
	return 0;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>dat[i];
	memset(dp, 0xF0, sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=13;j++){
			if (i<5) continue;
			dp[i][j]=dp[i-5][j-1]+calc(dat[i-1], dat[i-2], dat[i-3], dat[i-4], dat[i-5], j);
			if (i>=6){
			for(int k1=i-6;k1<i-1;k1++){
				for(int k2=k1+1;k2<i-1;k2++){
					for(int k3=k2+1;k3<i-1;k3++){
						for(int k4=k3+1;k4<i-1;k4++){
							dp[i][j]=maxi(dp[i][j], dp[i-6][j-1]+calc(dat[k1], dat[k2], dat[k3], dat[k4], dat[i-1], j));
						}
					}
				}
			}}
			if (i>=7){
			for(int k1=i-7;k1<i-2;k1++){
				for(int k2=k1+1;k2<i-2;k2++){
					for(int k3=k2+1;k3<i-2;k3++){
						for(int k4=k3+1;k4<i-2;k4++){
							dp[i][j]=maxi(dp[i][j], dp[i-7][j-1]+calc(dat[k1], dat[k2], dat[k3], dat[k4], dat[i-1], j));
						}
					}
				}
			}
			for(int k1=i-7;k1<i-2;k1++){
				for(int k2=k1+1;k2<i-2;k2++){
					for(int k3=k2+1;k3<i-2;k3++){
						dp[i][j]=maxi(dp[i][j], dp[i-7][j-1]+calc(dat[k1], dat[k2], dat[k3], dat[i-2], dat[i-1], j));
					}
				}
			}}
			if (i>=8){
			for(int k1=i-8;k1<i-3;k1++){
				for(int k2=k1+1;k2<i-3;k2++){
					for(int k3=k2+1;k3<i-3;k3++){
						for(int k4=i-3;k4<i-1;k4++){
							dp[i][j]=maxi(dp[i][j], dp[i-8][j-1]+calc(dat[k1], dat[k2], dat[k3], dat[k4], dat[i-1], j));
						}
					}
				}
			}
			for(int k1=i-8;k1<i-3;k1++){
				for(int k2=k1+1;k2<i-3;k2++){
					dp[i][j]=maxi(dp[i][j], dp[i-8][j-1]+calc(dat[k1], dat[k2], dat[i-3], dat[i-2], dat[i-1], j));
				}
			}}
			if (i>=9){
			for(int k1=i-9;k1<i-4;k1++){
				for(int k2=k1+1;k2<i-4;k2++){
					for(int k3=k2+1;k3<i-4;k3++){
						dp[i][j]=maxi(dp[i][j], dp[i-9][j-1]+calc(dat[k1], dat[k2], dat[k3], dat[i-2], dat[i-1], j));
					}
				}
			}
			for(int k1=i-9;k1<i-4;k1++){
				for(int k2=k1+1;k2<i-4;k2++){
					for(int k3=i-4;k3<i-1;k3++){
						for(int k4=k3+1;k4<i-1;k4++){
							dp[i][j]=maxi(dp[i][j], dp[i-9][j-1]+calc(dat[k1], dat[k2], dat[k3], dat[k4], dat[i-1], j));
						}
					}
				}
			}
			for(int k1=i-9;k1<i-4;k1++){
				dp[i][j]=maxi(dp[i][j], dp[i-9][j-1]+calc(dat[k1], dat[i-4], dat[i-3], dat[i-2], dat[i-1], j));
			}}
			if (i>=10){
			for(int k1=i-10;k1<i-5;k1++){
				for(int k2=k1+1;k2<i-5;k2++){
					for(int k3=i-5;k3<i-2;k3++){
						dp[i][j]=maxi(dp[i][j], dp[i-10][j-1]+calc(dat[k1], dat[k2], dat[k3], dat[i-2], dat[i-1], j));
					}
				}
			}
			for(int k1=i-10;k1<i-5;k1++){
				for(int k2=i-5;k2<i-1;k2++){
					for(int k3=k2+1;k3<i-1;k3++){
						for(int k4=k3+1;k4<i-1;k4++){
							dp[i][j]=maxi(dp[i][j], dp[i-10][j-1]+calc(dat[k1], dat[k2], dat[k3], dat[k4], dat[i-1], j));
						}
					}
				}
			}
			dp[i][j]=maxi(dp[i][j], dp[i-10][j-1]+calc(dat[i-5], dat[i-4], dat[i-3], dat[i-2], dat[i-1], j));}
			if (i>=11){
			for(int k1=i-11;k1<i-6;k1++){
				for(int k2=k1+1;k2<i-6;k2++){
					dp[i][j]=maxi(dp[i][j], dp[i-11][j-1]+calc(dat[k1], dat[k2], dat[i-3], dat[i-2], dat[i-1], j));
				}
			}
			for(int k1=i-11;k1<i-6;k1++){
				for(int k2=i-6;k2<i-2;k2++){
					for(int k3=k2+1;k3<i-2;k3++){
						dp[i][j]=maxi(dp[i][j], dp[i-11][j-1]+calc(dat[k1], dat[k2], dat[k3], dat[i-2], dat[i-1], j));
					}
				}
			}
			for(int k1=i-6;k1<i-1;k1++){
				for(int k2=k1+1;k2<i-1;k2++){
					for(int k3=k2+1;k3<i-1;k3++){
						for(int k4=k3+1;k4<i-1;k4++){
							dp[i][j]=maxi(dp[i][j], dp[i-11][j-1]+calc(dat[k1], dat[k2], dat[k3], dat[k4], dat[i-1], j));
						}
					}
				}
			}}
			if (i>=12){
			for(int k1=i-12;k1<i-7;k1++){
				for(int k2=i-7;k2<i-3;k2++){
					dp[i][j]=maxi(dp[i][j], dp[i-12][j-1]+calc(dat[k1], dat[k2], dat[i-3], dat[i-2], dat[i-1], j));
				}
			}
			for(int k1=i-7;k1<i-2;k1++){
				for(int k2=k1+1;k2<i-2;k2++){
					for(int k3=k2+1;k3<i-2;k3++){
						dp[i][j]=maxi(dp[i][j], dp[i-12][j-1]+calc(dat[k1], dat[k2], dat[k3], dat[i-2], dat[i-1], j));
					}
				}
			}}
			if (i>=13){
			for(int k1=i-13;k1<i-8;k1++){
				dp[i][j]=maxi(dp[i][j], dp[i-13][j-1]+calc(dat[k1], dat[i-4], dat[i-3], dat[i-2], dat[i-1], j));
			}
			for(int k1=i-8;k1<i-3;k1++){
				for(int k2=k1+1;k2<i-3;k2++){
					dp[i][j]=maxi(dp[i][j], dp[i-13][j-1]+calc(dat[k1], dat[k2], dat[i-3], dat[i-2], dat[i-1], j));
				}
			}}
			if (i>=14){
			for(int k1=i-9;k1<i-4;k1++){
				dp[i][j]=maxi(dp[i][j], dp[i-14][j-1]+calc(dat[k1], dat[i-4], dat[i-3], dat[i-2], dat[i-1], j));
			}}
			if (i>=15) dp[i][j]=maxi(dp[i][j], dp[i-15][j-1]+calc(dat[i-5], dat[i-4], dat[i-3], dat[i-2], dat[i-1], j));
		}
	}
	int ans=0;
	for(int i=65;i<=n;i++) ans=maxi(ans, dp[n][13]);
	cout<<ans<<endl;
	return 0;
}
