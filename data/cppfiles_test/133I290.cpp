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
ll mod = 1e9+7;
const int maxN = 2e6+2;
#define endl '\n'
 
inline void debugMode() {

#ifdef LOCAL
 
freopen("input.txt", "r", stdin);
 
freopen("output.txt", "w", stdout);
 
#endif // ONLINE_JUDGE
}

// #define int long long

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
    return pow(a , m-2);
}

int add(int a , int b) {
    int ans= ((ll)a+b)%mod;
    if(ans < 0) {
        ans += mod;
    }
    return ans;
}

void test_case() {
    int n;
    cin >> n;
    vector<string> a(n-2);
    for(int i = 0 ; i < n-2 ; i++) {
        cin >> a[i];
    }
    multiset<string> t(a.begin(), a.end());
    string ans = "";
    for(int i = 0 ; i < n-2 ; i++) {
        string temp = a[i];
        multiset<string> u = t;
        u.erase(u.find(temp));
        string last = temp;
        while(int(temp.size()) != n-1) {
            string z = "";
            z += last[1];
            z += "a";
            debug() << imie(z);
            if(u.find(z) != u.end()) {
                temp += "a";
                u.erase(u.find(z));
                last = z;
                continue;
            }
            z ="";
            z += last[1];
            z += "b";
            if(u.find(z) != u.end()) {
                temp += "b";
                u.erase(u.find(z));
                last = z;
                continue;
            }
            break;

        }
        debug() << imie(temp);
        if(int(temp.size()) == n-1) {
            ans = temp;
            ans += "a";
            break;
        }


    }
    cout << ans << endl;
}

// #undef int

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    debugMode();
    int t;
    // t = 1;
    cin >> t;
    while(t--) {
        test_case();
    }
    // for(int i = 1 ; i <= t ; i++) {
    //     cout << "Case #" << i << ": ";
    //     test_case();
    // }
    return 0;
}