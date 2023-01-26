#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }
 
#define ll long long
#define ld long double
const int mod = 998244353;
const int maxN = 1e6+2;
#define endl '\n'
 
inline void debugMode() {

#ifdef LOCAL
 
freopen("input.txt", "r", stdin);
 
freopen("output.txt", "w", stdout);
 
#endif // ONLINE_JUDGE
}

#define int long long

int mul(int a , int b) {
    return (ll)a*b%mod;
}

int my_pow(int a , int p) {
    int ans = 1;
    while(p) {
        if(p&1) {
            ans = mul(a , ans);
        }
        a = mul(a , a);
        p/=2;
    }
    return ans%mod;
}

int inv(int a , int m) {
    return my_pow(a , m-2);
}

int add(int a , int b) {
    int ans= ((ll)a+b)%mod;
    if(ans < 0) {
        ans += mod;
    }
    return ans;
}

int gcd(int a, int b) {
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

void test_case(int tc) {
    int n, k, x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    // if(tc == 111) {
    //     cout << s << " " << n << " " << k << " " << x;
    // }
    if(n == 1) {
        cout << s << endl;
        return;
    }
    vector<int> b;
    int sz = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') {
            if(sz != 0){
                b.push_back(k*sz+1);
            }
            sz = 0;
        }
        else {
            sz++;
        }
    }
    if(sz != 0) {
        b.push_back(k*sz+1);
    }
    if(b.size() == 0) {
        cout << s << endl;
        return;
    }
    debug() << imie(b);
    int p = 1;
    vector<int> prod((int)b.size());
    int j = 0;
    for(int i = (int)b.size()-1; i >= 1; i--) {
        if(p >= (x+b[i]-1)/b[i]) {
            j = i;
            break;
        }
        else {
            p *= b[i];
            prod[i] = p;
        }
    }
    string ans = "";
    for(int i = 0 ; i < n; i++) {
        if(s[i] == 'a') {
            ans += "a";
        }
        else{
            break;
        }
    }
    for(int i = 0 ; i < j; i++) {
        ans += "a";
    }
    debug() << imie(j) << imie(prod);
    for(int i = j; i < (int)b.size()-1; i++) {
        int k = (x-1+prod[i+1])/prod[i+1];
        for(int j = 0; j < k-1; j++) {
            ans += "b";
        }
        x -= (k-1)*prod[i+1];
        ans += "a";
    }
    for(int i = 0; i < x-1; i++) {
        ans += "b";
    }
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == 'a') {
            ans += "a";
        }
        else {
            break;
        }
    }
    cout << ans << endl;
}

#undef int

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    debugMode();
    int t;
    t = 1;
    cin >> t;
    // while(t--) {
    //     test_case();
    // }
    for(int i = 1 ; i <= t ; i++) {
        // cout << "Case #" << i << ": ";
        test_case(i);
    }
    return 0;
}