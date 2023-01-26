#include<bits/stdc++.h>
using namespace std;
inline void reads(string& x){char kk[200'123]; scanf("%s",kk); x = kk;}
const int MOD = 1'000'000'007;
typedef long long       ll;

int main(){
    int t = 1; scanf("%d",&t);
    while(t--){
        int ans = 0;
        int n; scanf("%d", &n);
        int c2 = (2*n)/3;
        int c1 = n/3;
        printf("%d %d\n", c1, c2);
    }
}