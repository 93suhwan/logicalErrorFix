#include<bits/stdc++.h>
#include <bits/extc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
#define fopen freopen("input.txt", "r", stdin)
#define eb emplace_back
#define em emplace
#define prec(a) cout<<fixed;cout.precision(a);
#define all(a) (a).begin(), (a).end()
typedef long long ll;typedef long double ld;typedef unsigned long long ul;typedef unsigned int ui;typedef pair<int,int> pii;typedef pair<ll,ll> pll;typedef complex<double> cpx;
typedef tuple<int,int,int> tiii;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<class T>
void pr(T t) {cerr << t << " ";}
template<class T, class ...Args>
void pr(T a, Args ...args) {cerr << a << " ";pr(args...);}
template<class ...Args>
void prl(Args ...args) {pr(args...);cerr << endl;}
const ll INF = 2e18;
const int inf = 2e9;
const double PI = acos(-1);


int n, q;
ll A[100010], B[100010];
ll T[100010]; //A-B, 음수(, 양수 )
ll seg[400010], ma[400010], sum[400010], mi[400010];
void init(int x, int l, int r){
    if(l==r){
        ma[x] = seg[x] = mi[x] = T[l];
        return ;
    }
    init(x*2, l, (l+r)/2);
    init(x*2+1, (l+r)/2+1, r);
    seg[x] = seg[x*2] + seg[x*2+1];
    ma[x] = max(ma[x], seg[x*2] + ma[x*2+1]);
    mi[x] = min(mi[x], seg[x*2] + mi[x*2+1]);
}
ll getmi(int x, int l, int r, int s, int e){
    if(l>r||r<s||e<l) return INF;
    if(s<=l&&r<=e) return mi[x];
    int m = (l+r)/2;
    if(m<s) return getmi(x*2+1, m+1, r, s, e);
    else if(e<=m) return getmi(x*2, l, m, s, e);

    return min(getmi(x*2, l, m, s, e), sum[m]-sum[s-1] + getmi(x*2+1, m+1, r, s, e));
}
ll getma(int x, int l, int r, int s, int e){
    if(l>r||r<s||e<l) return 0;
    if(s<=l&&r<=e) return ma[x];
    int m = (l+r)/2;
    if(m<s) return getma(x*2+1, m+1, r, s, e);
    else if(e<=m) return getma(x*2, l, m, s, e);

    return max(getma(x*2, l, m, s, e), sum[m]-sum[s-1] + getma(x*2+1, m+1, r, s, e));
}
int main()
{
    //fopen;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>A[i];
    for(int i=1;i<=n;i++){
        cin>>B[i];
        T[i] = A[i]-B[i];
        sum[i] = sum[i-1] + T[i];

    }
    init(1, 1, n);
    while(q--){
        int l, r;cin>>l>>r;
        if(sum[r]-sum[l-1] !=0){
            cout<<"-1\n";
            continue;
        }
        ll t = getmi(1, 1, n, l, r);
        if(getma(1, 1, n, l, r) > 0){
            cout<<"-1\n";
            continue;
        }
        cout<<-getmi(1, 1,n, l,r)<<"\n";
    }
}