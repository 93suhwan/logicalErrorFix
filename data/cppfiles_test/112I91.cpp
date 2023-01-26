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
    ll a[3] ; ll m;
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    cin >> m;
    sort(a , a + 3);
    ll aux = a[1] + a[0];
    ll minn = 0;
    ll pos = a[2] + 1;
    ll maxx = a[0] + a[1] + a[2] - 3;
    if (aux == pos) {
        minn = 0;
        if (m > maxx) {
            no; return;
        }
    }
    if (aux > pos) {
        pos = pos - a[1];
        pos += 1;
        minn = a[0] - pos;
        if ( m < minn || m > maxx) {
            no; return;
        }
    }
    if (aux < pos) {
        if (aux >= pos - 2) {
            minn = 0;
            if ( m < minn || m > maxx) {
                no; return;
            }
        }
        else {
            minn = a[2] - aux - 1;
            if ( m < minn || m > maxx) {
                no; return;
            }
        }
    }
    yes;
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
