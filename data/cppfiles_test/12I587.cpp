/**
 * Created by prayutsu
 * at 11:28 AM on July 27, 2021.
 */

#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;

#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

#define ll long long
#define ld long double
#define ull unsigned long long

#ifdef prayutsu
#define dbg(a) cerr << #a << ": "; _print(a); cerr << '\n';
#define dbgi(a, i) cerr << #a << " in "<< #i << " -> " << (i) << " = "; _print(a); cerr<<'\n';
#else
#define dbg(a) // Chakhma...
#define dbgi(a, i) // Dobara chakhma...
#endif

using namespace __gnu_pbds;
#define pir pair< ll, ll >
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/** General Utility. */
#define vt                                  vector<ll>
#define ve                                  vector
#define mp                                  make_pair
#define pb                                  push_back
#define fi                                  first
#define se                                  second
#define mod                                 1000000007ll
#define sortf(v)                            sort((v).begin(), (v).end())
#define all(c)                              (c).begin(), (c).end()
#define in                                  read
#define setp(precision, double_number)      fixed << setprecision(precision) << double_number
#define sz(x)                               (ll)(x).size()
#define fill(container, value)              memset((container), (value), sizeof(container))
#define endn                                '\n'
#define setBits                             __builtin_popcountll
#define parity                              __builtin_parityll
#define case(count)                         cout<<"Case #"<<(count)<<": ";

/** Loops. */
#define fr(i, a, b, s)                      for (ll i=(a); (s)>0 ? (i)<(b) : (i)>(b); (i)+=(s))
#define fr1(e)                              fr(i, 0ll, e, 1ll)
#define fr2(i, e)                           fr(i, 0ll, e, 1ll)
#define fr3(i, b, e)                        fr(i, b, e, 1ll)
#define fr4(i, b, e, s)                     fr(i, b, e, s)
#define GET5(a, b, c, d, e, ...)            e
#define frc(...)                            GET5(__VA_ARGS__, fr4, fr3, fr2, fr1)
#define FOR(...)                            frc(__VA_ARGS__)(__VA_ARGS__)
#define repc(i, a, b, c)                    for (ll i=(a); (i)<=(b); (i)+=(c))
#define perc(i, a, b, c)                    for (ll i=(a); (i)>=(b); (i)+=(c))
#define rep(i, a, b)                        repc(i, a, b, 1)
#define per(i, a, b)                        perc(i, a, b, -1)
#define repn(i, b)                          rep(i, 1, b)

/** Debugging. */
#define show(a)                             for(int i=0; i<(a).size(); i++) cout<<(a)[i]<<' '; cout<<'\n';
#define each(x, a)                          for (auto& (x): (a))
#define show_stl(v)                         cerr << "[ "; for (auto i: (v)) { _print(i); cerr << ", ";} cerr << "]";
#define show_pair(p)                        cerr << "{ ";  _print((p).fi); cerr << ", "; _print((p).se); cerr << " }";

template<class A>
void _print(A x) { cerr << x; }

template<class T, class V>
void _print(pair<T, V> p) { show_pair(p) }

template<class T>
void _print(vector<T> v) { show_stl(v) }

template<class T>
void _print(set<T> v) { show_stl(v) }

template<class T>
void _print(multiset<T> v) { show_stl(v) }

template<class T>
void _print(ordered_set<T> &v) { show_stl(v) }

template<class T, class V>
void _print(map<T, V> v) { show_stl(v) }

ll gcd(ll a, ll b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

ll lcm(ll a, ll b) { return (a / (gcd(a, b))) * b; }

template<class A>
void read(ve<A> &x);

template<class A, size_t S>
void read(array<A, S> &x);

template<class T>
void read(T &x) { cin >> x; }

void read(double &d) {
    string t;
    read(t);
    d = stod(t);
}

void read(long double &d) {
    string t;
    read(t);
    d = stold(t);
}

template<class H, class... T>
void read(H &h, T &... t) {
    read(h);
    read(t...);
}

template<class A>
void read(ve<A> &x) { each(a, x) read(a); }

template<class A, size_t S>
void read(array<A, S> &x) { each(a, x) read(a); }

string to_string(char c) { return string(1, c); }

string to_string(ve<bool> v) {
    string res;
    FOR(sz(v))res += char('0' + v[i]);
    return res;
}

/** Use %mod to evaluate large powers %mod */
long long fastpow(long long a, long long b) {
    long long res = 1ll;
    while (b > 0ll) {
        if (b & 1ll)
            res = res * a;
        a = a * a;
        b >>= 1ll;
    }
    return res;
}

void solve() {
    ll n, m, k;
    in(n, m, k);
    ll maxi;
    if (n%2==0 && m%2==0) {
        maxi = n*m/2;
        cout<< (k&1 ? "No" : "Yes");
    } else if (n%2==0 && m%2!= 0){
        maxi = ((m*n))/2 - n/2;
        cout<< (k <= maxi && parity(k) == parity((n*m)/2) ? "Yes" : "No");
    } else if (n%2!=0 && m%2== 0){
        maxi = ((n*m))/2;
        cout<< (k <= maxi && parity(k) == parity((n*m)/2) ? "Yes" : "No");
    }
    cout<<endn;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef prayutsu
    freopen("inputs.txt", "r", stdin);
    freopen("outputs.txt", "w", stdout);
    freopen("errors.txt", "w", stderr);
#endif
    int test_cases;
    in(test_cases);
    auto start = high_resolution_clock::now();
//    factorial();
    rep(i, 0, test_cases - 1) {
//        case(i+1);
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

#ifdef prayutsu
    cerr << "Time: " << duration.count() / 1000.0 << " ms" << endn;
#endif
    return 0;
}