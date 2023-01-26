#include <bits/stdc++.h>
using namespace std;
using namespace chrono;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL) ; cout.tie(NULL);

#define all(x) (x).begin(), (x).end()
#define ll long long
#define nline '\n'
#define yes cout<<"YES"<<nline
#define no cout<<"NO"<<nline

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int n) {cerr << n;}
void _print(double n) {cerr << n;}
void _print(long long n) {cerr << n;}
void _print(char n) {cerr << n;}
void _print(string n) {cerr << n;}
void _print(bool n) {cerr << n;}
template<class T> _print(vector<T> v1) {cerr << "["; for (T i : v1) {_print(i); cerr << " ";} cerr << "]";}
template<class T> _print(set<T> s1) {cerr << "["; for (T i : s1) {_print(i); cerr << " ";} cerr << "]";}
template<class T> _print(unordered_set<T> s2) {cerr << "["; for (T i : s2) {_print(i); cerr << " ";} cerr << "]";}
template<class T1 , class T2> _print(unordered_map<T1 , T2> m2) {cerr << "["; for (auto i : m2) {cerr << "("; _print(i.first); cerr << " , "; _print(i.second); cerr << ")";} cerr << "]";}
#define MOD = 1000000007;
#define CHAR = 256;
#define INF INT_MAX;

void solve()
{
    ll a, b, c, m;
    cin >> a >> b >> c >> m;
    ll alph[3] = {a, b, c};
    sort(alph, alph + 3);
    a = alph[0], b = alph[1], c = alph[2];
    ll max1 = a + b + c - 3;
    ll min1 = max(0ll, c - b - 1);
    if (a + b >= c)
    {
        a -= c / 2;
        b -= c / 2;
        if (a < 0)
        {
            b -= c / 2 - a;
            a = 0;
        }
        min1 = min(min1, b - a - 1);
    }
    else
    {
        min1 = min(min1, c - a - b - 1);
    }

    if (m >= min1 && m <= max1)
        cout << "YES" << nline;
    else
        cout << "NO" << nline;
}

int main()
{
    fastio()
#ifndef ONLINE_JUDGE
    freopen("error.txt" , "w" , stderr);
#endif
    //// Why you always in mood *_* ////

    int T;
    // T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
