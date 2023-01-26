// kitto kienai kyou wa ienai

#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define float           double
#define ll              long long
#define int             long long
#define pb              push_back
#define ppb             pop_back
#define pf              push_front
#define ppf             pop_front
#define mp              make_pair
#define all(v)          v.begin(),v.end()
#define uniq(v)         (v).erase(unique(all(v)),(v).end())
#define endl            "\n"

#define pii             pair<int,int>
#define pll             pair<ll, ll>
#define vi              vector<int>
#define vl              vector<ll>
#define vpii            vector<pii>
#define vpll            vector<pll>
#define vvi             vector<vi>
#define vvl             vector<vl>

#define rep(i,a,b)      for(int i=a;i<b;i++)
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mem1(a)         memset(a,-1,sizeof(a))
#define mem0(a)         memset(a,0,sizeof(a))
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)

#define PI              3.1415926535897932384626433832795
#define eps             1e-9
#define mod             1000000007
#define inf             1e18

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}
//template<typename T> using pbds = tree<T , null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update>;

void __print(int x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}


template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T&& t, V&&... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void runtime()
{
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
    cin >> a[i];
    if (n % 2 == 0)
    {
        for (int i = 0; i < n ; i += 2)
        {
            int x = abs(a[i]);
            int y = abs(a[i + 1]);
            int l = ((x * y) / __gcd(x, y));
            int p = l / x;
            int q = l / y;
            if (a[i]*a[i + 1] > 0)
            {
                cout << -p << " " << q << " ";
            }
            else
            {
                cout << p << " " << q << " ";
            }
        }
    }
    else
    {
        for (int i = 0; i < n - 3 ; i += 2)
        {
            int x = abs(a[i]);
            int y = abs(a[i + 1]);
            int l = ((x * y) / __gcd(x, y));
            int p = l / x;
            int q = l / y;
            if (a[i]*a[i + 1] > 0)
            {
                cout << -p << " " << q << " ";
            }
            else
            {
                cout << p << " " << q << " ";
            }
        }
        int r = a[n - 3] + a[n - 2];
        if (r == 0)
        {
            r += a[n - 3];
            int x = abs(r);
            int y = abs(a[n - 1]);
            int l = ((x * y) / __gcd(x, y));
            int p = l / x;
            int q = l / y;
            if (r * a[n - 1] > 0)
            {

                cout << -2 * p << " " << -p << " " << q << " ";
            }
            else
            {
                cout << 2 * p << " " << p << " " << q << " ";
            }

        }
        else
        {
            int x = abs(r);
            int y = abs(a[n - 1]);
            int l = ((x * y) / __gcd(x, y));
            int p = l / x;
            int q = l / y;
            if (r * a[n - 1] > 0)
            {

                cout << p << " " << -p << " " << q << " ";
            }
            else
            {
                cout << p << " " << p << " " << q << " ";
            }
        }

    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int TESTS = 1; // one input
    cin >> TESTS;
    while (TESTS--) {
        runtime();
        cout << "\n";
    }
    return 0;
}