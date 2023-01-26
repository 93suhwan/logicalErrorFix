#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define ull unsigned long long
#define ld long double
#define F first
#define S second
#define pb push_back
#define pf push_front
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MP  make_pair
#define mem(a , v)  memset(a , v , sizeof(a))
#define all(v)  ((v).begin()), ((v).end())
#define endl '\n'
const int MOD = 1000000007;
const int MOD2 = 998244353;
//ld epsilon = 1e-9;

//cout << setprecision(5) << fixed << '\n';
//
ll poww(ll x, ll y) {
    if(y == 0)
        return 1;
    ll s = poww(x, y / 2);
    s = (s * s);
    if(y % 2 == 1)
        s = (s * x);
    return s;
}

ll powm(ll x, ll y) {
    if(y == 0)
        return 1;
    ll s = powm(x, y / 2);
    s = (s * s);
    if(y % 2 == 1) {
        s = s % MOD;
        s = (s * x);
    }
    return s % MOD;
}

//int bs(int x, int l, int r){
//    int mid = (r-l)/2 + l;
//    int ans = l-1;
//    while(l <= r){
//        if(x == a[mid]){
//            return mid;
//        }
//        else if(x > a[mid]){
//            ans = mid;
//            l = mid + 1;
//        }
//        else r = mid - 1;
//        mid = (r-l)/2 + l;
//    }
//    return ans;
//}

//LIS
//multiset <int> s;
//multiset <int> :: iterator it;
//for(int j = l + 1; j < r; j++) {
//    s.insert(a[j]);
//    it = s.upper_bound(a[j]);
//    if(it != s.end())
//        s.erase(it);
//}

//vector<int> p;
//bool pr[10000005];
//void seive(int n) {
//    p.clear();
//    for(int i = 2; i < ceil(sqrt(n)); i++) {
//        for(int j = i * i; j < n; j += i) {
//            pr[j] = 1;
//        }
//    }
//    for(int i = 2; i < n; i++) {
//        if(!pr[i]) {
//            p.pb(i);
//        }
//    }
//}


//int mod2 = 998244353;
//void add(ll &x, int y) {
//    x += y;
//    if(x >= mod)
//        x -= mod;
//}
//void add2(ll &x, ll y) {
//    x += y;
//    if(x >= mod2)
//        x -= mod2;
//}

//bool cmp2(const pair<int, int> &a, const pair<int, int> &b) {
//    if(a.F == b.F) {
//        return a.S > b.S;
//    }
//    return a.F < b.F;
//}

int n, m;


int main() {
    //freopen("ladder.in" , "r" , stdin);
    //freopen("ladder.out" , "w" , stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t = 1;
    cin >> _t;
    while(_t--) {
        cin >> m >> n;
        int p[m + 2][n + 2];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >> p[i][j];
            }
        }
        int mx[n + 2];
        for(int i = 0; i < n; i++) {
            int mxx = 0;
            for(int j = 0; j < m; j++) {
                mxx = max(mxx, p[j][i]);
            }
            mx[i] = mxx;
        }
        if(n > m) {
            int ans = 1e9 + 5;
            for(int i = 0; i < n; i++) {
                ans = min(ans,mx[i]);
            }
            cout << ans << endl;
        }
        else {
            vector<pair<int, int> > v[m + 2];
            int ans = 0;
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    v[i].pb({p[i][j], j});
                }
                sort(v[i].begin(), v[i].end());
                int mo = 0;
                for(int j = 0; j < n; j++) {
                    if(mo == n - 2) {
                        ans = max(ans, v[i][j].F);
                        break;
                    }
                    if(v[i][j].F != mx[v[i][j].S])
                        mo++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
/*
10101010
11010110
*/
