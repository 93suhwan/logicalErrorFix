#include<bits/stdc++.h>
//#include <chrono>
//using namespace std::chrono;
using namespace std;
#define int     long long
#define vi      vector<int>
#define all(v)  v.begin(), v.end()
#define vvi     vector<vi>
#define pb      push_back
#define ppb     pop_back
#define pii     pair<int, int>
#define mp      make_pair
#define ff      first
#define ss      second
#define endl    "\n"
#define MAX     LONG_LONG_MAX
#define MIN     LONG_LONG_MIN
#define lb      lower_bound
#define ub      upper_bound
#define INF     1e18
#define MOD     1000000007
#define set_bits __builtin_popcountll
#define rep(i,a,b) for(int i = a; i < b; i++)
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(bool t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*---------------------------------------------------------------------------------------------------------------------------*/
int lcm(int a, int b) {return (a*b)/__gcd(a, b);};
bool revsort(int a, int b) {return a > b;}
void precision(int a) {cout << setprecision(a) << fixed;}
int fact(int i) {if (i <= 1) return 1; else return i * fact(i - 1);}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = i * i; j <= n; j += i)arr[j] = 1;} return vect;}
string decToBin(int n) {string s = ""; int i = 0; while (n > 0) {s = to_string(n % 2) + s; n = n / 2; i++;} return s;}
int binToDec(string n) {string num = n; int dec_value = 0; int base = 1; int len = num.length(); for (int i = len - 1; i >= 0; i--) {if (num[i] == '1')dec_value += base; base = base * 2;} return dec_value;}
int mpow(int a, int b) {if (b == 0) return 1; int res = 1; a %= MOD; while (b) {if (b & 1) {res = (res * a) % MOD;} a = (a * a) % MOD; b >>= 1;} return res;}
int madd(int a, int b) {a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD;}
int msub(int a, int b) {a = a % MOD; b = b % MOD; return (((a - b) % MOD) + MOD) % MOD;}
int mmul(int a, int b) {a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD;}

const int dx[4] = { -1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
/*---------------------------------------------------------------------------------------------------------------------------*/

vi l(300005);

void pre() {
    l[1] = 2;
    rep(i,2,l.size()) {
        l[i] = lcm(l[i-1],i+1);
    }
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (auto &val : v) {
        cin >> val;
    }
    if(!(v[0] & 1)) {
        cout << "NO" << endl;
    } else {
        rep(i,0,n) {
            if(v[i] % l[i+1] != 0) {
                cout <<"YES" << endl;
                break;
            } 
        }
        cout << "NO" << endl;
    }
}
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    //auto start1 = high_resolution_clock::now();
    int t;
    cin >> t;
    pre();
    while (t--) {
        solve();
    }
    /*auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1-start1);
    #ifndef ONLINE_JUDGE
    cerr << "TIME: " << duration.count()/1000 << endl;
    #endif*/
}