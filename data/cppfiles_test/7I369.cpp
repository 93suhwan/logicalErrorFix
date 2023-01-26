#include<bits/stdc++.h>
#define ll long long
#define ito ::iterator it
using std::cin;
using std::cout;
using std::string;
using std::map;
using std::multiset;
using std::multimap;
using std::set;
using std::stack;
using std::pair;
using std::vector;
using std::queue;
using std::priority_queue;
typedef pair < int , int > ptt;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;
const double eps = 1e-6;
ll a[N];
int Logn[N];
ll dp[N][150];
inline ll read(){
    ll s=0,f=1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') s = s*10+ch-'0',ch=getchar();
    return s*f;
}
void get_logn(){
    Logn[1] = 0;
    Logn[2] = 1;
    for(int i = 3; i <= N; i++){
        Logn[i] = Logn[i/2] + 1;
    }
}
void get_st(int n){
    for(int i = 1; i <= n; i++) dp[i][0] = a[i];
    for(int j = 1; j <= Logn[n]; j++){
        for(int i = 1; i + (1 << j) - 1 <= n; i++){
            dp[i][j] = std::__gcd(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }
}
ll query(int l,int r){
    int s = Logn[r-l+1];
    return std::__gcd(dp[l][s],dp[r-(1<<s)+1][s]);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(0);std::cout.tie(0);
    get_logn();
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        for(int i = 1; i <= n; i++) a[i] = read();
        for(int i = 1; i <= n-1; i++) a[i] = std::labs(a[i+1] - a[i]);
        a[n] = 1;
        get_st(n-1);
        int l = 1,r = 1;
        int ans = 1;
        while(r < n){
            ll q = 1;
            while(r < n && query(l,r) != 1){
                q = query(l,r);
                r++;
            }
            if(q != 1) ans = std::max(ans,r - l + 1);
            l++;
            r = std::max(l,r);
        }
        cout << ans <<'\n';
    }
    //system("pause");
    return 0;
}