#include <bits/stdc++.h>
using namespace std;

/*Weird define*/
#define taskname "?" //change
#define int long long // change if necessary
#define ll long long
#define nL "\n"
#define Fill(A, t) fill(begin(A), end(A), t)
#define gcd __gcd
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0)

/*some const*/
const int maxn = 1e6;
const ll IMA = LLONG_MAX;
const ll IMI = LLONG_MIN;
const ll INF = 1e15;
const ll MOD = 1000000007;

/*INPUT&OUTPUT*/
#define filein(name) freopen(name".INP", "r", stdin)
#define fileout(name) freopen(name".OUT", "w", stdout)

/*push-pop-pair define*/
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define l first
#define r second

/*Type-def*/
typedef unsigned long long 	ull;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef long double ld;

/*Simple Calc*/
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}

void Solve(){
    int n; cin >> n;
    int A[n+10];
    pll ans[n+10];
    for(int i=0; i<n; ++i){
        int l, r; cin >> l >> r;
        if(l == r)
            A[l] = -1;
        else for(int j=l; j<=r; ++j)
            A[j]++;
        ans[i+1] = {l, r};
    }
    for(int i=n; i>=1; --i){
        int l = ans[i].l, r = ans[i].r;
        if(l==r){
            cout << l << ' '<< r << ' ' << l << nL;
            continue;
        }
        int minn = l, cnt = A[l];
        for(int j=l+1; j<=r; ++j)
            if(cnt > A[j] && A[j] != -1){
                minn = j;
                cnt = A[j];
            }
        cout << l << ' ' << r  << ' ' << minn << nL;
    }
}

signed main()
{
    FAST_IO;
    //filein(taskname); fileout(taskname);
    int t = 1; cin >> t;
    while(t--)
        Solve();
    return 0;
}