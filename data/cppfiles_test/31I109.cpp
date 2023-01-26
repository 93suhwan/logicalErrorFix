#include <bits/stdc++.h>
#define pb emplace_back
#define xx first
#define yy second
#define in(x) scanf("%d",&x)
#define lin(x) scanf("%lld",&x)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N = 2e6+10;
const int M = N*2;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
ll qpow(ll a,ll b){ll res = 1;while(b){if(b&1)	res = res*a%MOD;a = a*a%MOD;b >>= 1;}return res;}
int n,m,k;
int A[N];
char str[N];
signed main(){
#ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
#endif
    int T = 1;  in(T);
    while(T--){
        in(n);
        for(int i = 1;i <= n;i++)   in(A[i]);
        if(n&1){
            for(int i = 1;i <= n-3;i += 2)
                printf("%d %d ",-A[i+1],A[i]);
            int a = n,b = n-1,c = n-2;
            int gcd = __gcd(abs(A[a]),abs(A[b]));
            gcd = __gcd(abs(A[c]),gcd);
            int sum = A[b] + A[c];
            printf("%d %d %d",A[a],A[a],-sum);
        }else{
            for(int i = 1;i <= n;i += 2)
                printf("%d %d ",-A[i+1],A[i]);
        }
        puts("");
    }
    return 0;
}