#include <bits/stdc++.h>
#include <random>
#include <ext/pb_ds/assoc_container.hpp>

#define clr(X , val)         memset(X , val , sizeof(X))
#define all(X)               (X).begin() , (X).end()
#define rall(X)              (X).rbegin() , (X).rend()
#define sz(X)                (int)X.size()
//#define                      Judge
#define int                  intmax_t
#define endl                   '\n'
#define tab                  '\t'
#define mp                   make_pair

// I see it , I like it , I want it , I got it...

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

template <class T> inline bool isSquare(T n) {
    T s = sqrt(n);
    return s * s == n || (s + 1) * (s + 1) == n;
}

typedef long long ll;
typedef unsigned long long ull;

template < class T > using indexed_set = tree < T , null_type , less < T > , rb_tree_tag , tree_order_statistics_node_update >;
template < class T > using indexed_multiset = tree < T , null_type , greater_equal < T > , rb_tree_tag , tree_order_statistics_node_update >;

template < typename T1 >  ostream &operator << (std::ostream &out, vector < T1 > &ar){for (int i = 0;i < ar.size();++i) out << ar[i] << " ";return out;}
template < typename T1 >  istream &operator >> (std::istream &in , vector < T1 > &ar){for (int i = 0;i < ar.size();++i) in >> ar[i];return in;}
template < typename T1 >  ostream &operator << (std::ostream &out, deque < T1 > &ar){for (int i = 0;i < ar.size();++i) out << ar[i] << " ";return out;}
template < typename T1 >  istream &operator >> (std::istream &in , deque < T1 > &ar){for (int i = 0;i < ar.size();++i) in >> ar[i];return in;}
template < typename T1 >  istream &operator >> (std::istream &in , vector < vector < T1 > > &ar){for (int i = 0;i < ar.size();++i){for (int j = 0;j < ar[i].size();++j) in >> ar[i][j];}return in;}
template < typename T1 >  ostream &operator << (std::ostream &out , vector < vector < T1 > > &ar){for (int i = 0;i < ar.size();++i){for (int j = 0;j < ar[i].size();++j){ out << ar[i][j] << ' ';} out << '\n';}return out;}
template < typename T1 , typename T2 >  istream &operator >> (std::istream &in , vector < pair < T1 , T2 > > &ar){for (int i = 0;i < ar.size();++i) in >> ar[i].first >> ar[i].second;return in;}
template < typename T1 , typename T2 >  ostream &operator << (std::ostream &out, vector < pair < T1 , T2 > > &ar){for (int i = 0;i < ar.size();++i) out << ar[i].first << " " << ar[i].second << '\n';return out;}
template < typename T1 , typename T2 >  ostream &operator << (std::ostream &out, deque < T1 , T2 > &ar){for (int i = 0;i < ar.size();++i) out << ar[i].first << ' ' << ar[i].second << '\n';return out;}
template < typename T1 , typename T2 >  istream &operator >> (std::istream &in , deque < T1 , T2 > &ar){for (int i = 0;i < ar.size();++i) in >> ar[i].first >> ar[i].second;return in;}
template < typename T1 , typename T2 > ostream &operator << (std::ostream &out , pair < T1 , T2 > pp){out << pp.first << ' ' << pp.second;return out;}

constexpr int maxN = 1000;
const string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr long double EPS = 1e-8;
constexpr int X[] = {0, 1, 0, -1};
constexpr int Y[] = {1, 0, -1, 0};

constexpr int MOD = 1e9 + 7;


void solve() { // check for T; don't use auto;
    int n;
    cin >> n;
    if (n & 1){
        cout << n / 2 << ' ' << n / 2 + 1 << endl;
    }else{
        cout << n / 3 - 1 << ' ' << n / 3 << ' ' << n / 3 + 1 << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef Judge
    freopen("teamwork.in" , "r" , stdin);
    freopen("teamwork.out" , "w" , stdout);
#endif
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* SPECIAL CASES (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
    * DP: If you have overlapping , try to swap loops(or try to iterate from end)
*/