// Author : rs258
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, 
tree_order_statistics_node_update>;
template <typename T>
using omultiset = tree<T, null_type, less_equal<T>, rb_tree_tag, 
tree_order_statistics_node_update>; 

#define ll         long long
#define ld         long double
#define endl       "\n"
#define pb         push_back
#define vll        vector<ll>
#define vvll       vector<vll>
#define pll        pair<ll,ll>
#define vbool      vector<bool>
#define vvbool     vector<vbool>
#define vstr       vector<string>
#define vpair      vector<pll>
#define F          first
#define S          second
#define mp(x,y)    make_pair(x,y)
#define all(a)     a.begin(),a.end()
#define rall(a)    a.rbegin(),a.rend()
#define rev(a)     reverse(all(a))
#define unq(a)     a.erase(std::unique(all(a)),a.end());
#define fr(i,a,b)  for(ll i = a ; i < b ; i++)
#define rf(i,a,b)  for(ll i = a ; i >= b; i--)
#define yes()      cout << "YES" << endl
#define no()       cout << "NO" << endl
#define err()      cout << "===========\n";
#define errA(A)    for(auto i : A) cout << i << " "; cout << "\n";
#define err1(a)    cout << #a <<" "<< a << "\n"
#define err2(a,b)  cout << #a <<" "<< a <<" "<< #b <<" "<< b << "\n"

const ll mod1 =    1000000007;
const ll mod2 =    998244353;
const ll infi =    1e18;
const ld eps  =    1e-9;

ll test_case = 0;
void google() {
    test_case++;
    cout << "Case #" << test_case << ": ";
}

ll pwr(ll a, ll b) {
    ll res = 1;
    while (b > 0) { 
        if (b & 1) res = (res * a);   
        a = (a * a); b >>= 1;
    }
    return res;
}

ll modpwr(ll a, ll b, ll x = mod1) {
    ll res = 1; 
    while (b > 0) { 
        if (b & 1) res = (res * a) % x;
        a = (a * a) % x; b >>= 1;
    } 
    return res;
}

ll modInverse(ll n, ll p = mod1) { 
    return modpwr(n, p - 2, p); 
}

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    fr(i, 0, n) {
        cin >> a[i];
    }

    // n == 2
    if(n == 2) {
        if(a[0] == a[1]) {
            yes();
            cout << 0 << " " << a[0] << endl;
        } else {
            no();
        }
        return;
    }

    // duplicates check
    map<ll, ll> m;
    fr(i, 0, n) {
        m[a[i]]++;
        if(m[a[i]] == 2) {
            fr(j, 0, i) {
                cout << a[j] << " ";
            }
            cout << 0 << " ";
            fr(j, i + 1, n) {
                cout << a[j] << " ";
            }
            cout << endl;
            return;
        }
    }

    // One even check
    vvll c(2);
    fr(i, 0, n) {
        c[(a[i] & 1)].pb(a[i]);
    }
    if(c[0].size() >= 1) {
        if(c[1].size() <= 1 && c[0].size() <= 2) {
            no();
            return;
        } else {
            yes();
            if(c[1].size() >= 2) {
                ll x = (c[1][1] + c[1][0] - c[0][0])/2;
                vll ans;
                ans.pb(x);
                fr(i, 1, c[0].size()) {
                    ans.pb(c[0][i] - x);
                }
                fr(i, 0, c[1].size()) {
                    ans.pb(c[1][i] - x);
                }
                errA(ans);
            } else {
                ll x = (c[0][2] + c[0][1] - c[0][0])/2;
                vll ans;
                ans.pb(x);
                fr(i, 1, c[0].size()) {
                    ans.pb(c[0][i] - x);
                }
                fr(i, 0, c[1].size()) {
                    ans.pb(c[1][i] - x);
                }
                errA(ans);
            }
            return;
        }
    }

    // No evens and no duplicates
    // we check first 28 elements for a subset sum
    ll num = min(28 * 1ll, n);
    vector<map<ll, ll>> M(num + 1);
    fr(i, 1, (1 << num)) {
        ll sum = 0;
        ll bits = __builtin_popcount(i);
        fr(j, 0, num) {
            if(i & (1 << j)) {
                sum += a[j];
            }
        }
        if(M[bits][sum] != 0) {
            ll x = M[bits][sum], y = i;
            ll u = x ^ y;
            x = u & x;
            y = u & y;
            set<ll> s;
            fr(j, 0, n) {
                s.insert(a[j]);
            }
            vll a1, a2;
            fr(j, 0, num) {
                if(x & (1 << j)) {
                    a1.pb(a[j]);
                    s.erase(a[j]);
                }
                if(y & (1 << j)) {
                    a2.pb(a[j]);
                    s.erase(a[j]);
                }
            }
            vll ans;
            ans.pb(0);
            fr(i, 0, a1.size() + a2.size() - 1) {
                if(i % 2 == 0) {
                    ans.pb(a1[i/2] - ans.back());
                    s.erase(a1[i/2]);
                } else {
                    ans.pb(a2[i/2] - ans.back());
                    s.erase(a2[i/2]);
                }
            }
            for(auto i : s) {
                ans.pb(i);
            }
            yes();
            errA(ans);
            return;
        } else {
            M[bits][sum] = i;
        }
    }
    no();

}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t = 1; 
    while(t--) solve();
    return 0;
}