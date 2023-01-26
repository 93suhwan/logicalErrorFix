#include <bits/stdc++.h>
using namespace std;
#include<tr1/unordered_map>
using namespace std::tr1;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=a;i>=n;i--)
typedef long long ll;
typedef pair<int,int> PII;
#define INF 0x3f3f3f3f
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int maxn = 100050;
const int mod = 998244353;
const int NIL = -1;
const double eps = 0.0000001;
const double pi = acos(-1.0);
const int N = 1010,M = 100050;
int T,n;
int mul[50000];
void init(){
    for(int i = 1;i <= 2000000000/i; i++){
        mul[i] = i*i;
    }
}
int main(){
    scanf("%d",&T);
    init();
    while(T--){
        scanf("%d",&n);
        int x,y;
        if(n <= 4){
            if(n == 1||n == 2){
                x = n == 1?1:2;
                y = 1;
            }  else {
                x = n == 3?2:1;
                y = 2;
            }
        } else {
            int temp = 0;
            for(int i = 3;i <= n;i++){
                if(mul[i] > n){
                    temp = i;
                    break;
                }
            }
            if(n - mul[temp-1] <= temp) {
                x = temp;
                y = n - mul[temp-1];
            } else {
                y = temp;
                x = temp - (n - mul[temp-1] - temp);
            }
        }
        printf("%d %d\n",y,x);
    }
//     system("pause");
    return 0;
}
/*
*/