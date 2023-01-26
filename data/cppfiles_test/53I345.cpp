#include <bits/stdc++.h>
using namespace std;
using namespace chrono;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL) ; cout.tie(NULL);
#define MOD 1000000007;
#define all(x) (x).begin(), (x).end()
#define ll long long
#define nline '\n'
#define CHAR 256

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

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        if (a[i] ==  a[i - 1] + 1)
            continue;
        else
        {
            k--;
        }
    }
    if (k >= 0)
        cout << "Yes" << nline;
    else
        cout << "No" << nline;
}

int main()
{
    //
    fastio()
#ifndef ONLINE_JUDGE
    freopen("error.txt" , "w" , stderr);
#endif
    //code here

    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
