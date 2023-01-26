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
const int N = 1e5+10;
const int M = 1e4+10;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
ll qpow(ll a,ll b){ll res = 1;while(b){if(b&1)	res = res*a%MOD;a = a*a%MOD;b >>= 1;}return res;}
int n,m,k;
int A[N],ans[N];
int st[M];
signed main(){
#ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
#endif
    int T = 1;  in(T);
    while(T--){
        in(n);
        memset(st,0,sizeof st);
        memset(ans,0,sizeof ans);
        for(int i = 1;i <= n;i++){
            ans[i] = 0;
            in(A[i]);
            int tp = abs(A[i]);
            if(!st[tp]){
                st[tp] = (A[i] < 0 ? -1 : 1) * i;
            }else{  // 如果前面出现过 不论正负
                if(A[i]*st[tp] > 0){    // 两个同号 需要一正一负
                    ans[abs(st[tp])] = 1,ans[i] = -1;
                }else{  // 异号 全正
                    ans[abs(st[tp])] = 1,ans[i] = 1;
                }
                st[tp] = 0;
            }
        }
        int sum = 0,gcd = 0;
        for(int i = 1;i <= n;i++){
            if(!ans[i]) sum += A[i],gcd = __gcd(gcd,abs(A[i]));
        }
        if(!sum){
            for(int i = 1;i <= n;i++)
                printf("%d ",ans[i]);
            puts("");
            continue;
        }
        sum /= gcd;
        int mn = INF;
        for(int i = 1;i <= n;i++)
            if(!ans[i]) mn = min(abs(A[i])/gcd,mn);

        ll check = 0;
        bool ok = 0;
        for(int i = 1;i <= n;i++){
            if(ans[i]) continue;
            if(!ok && abs(A[i]) == mn*gcd){
                int t;
                if(A[i] < 0)    t = (sum + mn);
                else            t = -(sum - mn);
                ok = 1;
                check += t*A[i];
                printf("%d ",t);
            }else{
                printf("%d ",mn);
                check += mn*A[i];
            }
        }
        puts("");
        //cout << check << endl;
    }
    return 0;
}
