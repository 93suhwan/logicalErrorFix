#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

#define int          long long int
#define w(t)         int t;cin>>t;while(t--)
#define rep(i,a,b)   for(int i=a;i<b;i++)
#define REP          for(int i=0;i<n;i++)
#define FTR(v,itr)   for(itr=v.begin();itr!=v.end();itr++)
#define si           set<int>
#define vi           vector<int>
#define pii          pair<int,int>
#define all(a)       (a).begin(),(a).end()
#define sortall(x)   sort(all(x))
#define mii          map<int,int>
#define stk          stack<int>
#define FF           first
#define SS           second
#define mp(a,b)      make_pair(a,b)
#define pb           push_back
#define FIO          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ITR(x,y)     x::iterator y
#define endl         "\n"
#define INF          1e18

#ifdef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(vi v1) {
  cerr << "[";
  for (int i : v1)cerr << i << " ";
  cerr << "]";
}

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PDBS;

vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

const int M = 1e9 + 7;
int mod(int x) {
  return (x % M + M) % M;
}

int fastExp(int b, int e, int m)
{
  int result = e & 1 ? b : 1;
  while (e) {
    e >>= 1;
    b = (b * b) % m;
    if (e & 1)
      result = (result * b) % m;
  }
  return result;
}

void FST() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}


int32_t main() {
  FST();
  w(t) {
    int n; cin >> n;
    vector<vector<int>> v(2, vector<int>(n));
    for (auto &i : v[0])cin >> i;
    for (auto &i : v[1])cin >> i;

    for (int i = n - 2; i >= 0; i--) {
      v[0][i] += v[0][i + 1];
    }

    for (int i = 1; i < n; i++)
      v[1][i] += v[1][i - 1];

    // for (auto i : v[0])cout << i << " ";
    // cout << endl;
    // for (auto i : v[1])cout << i << " ";
    // cout << endl;

    int temp = INT_MAX;
    for (int i = 0; i < n; i++) {
      int r = 0;
      if (i - 1 >= 0)r += v[1][i - 1];
      if (i + 1 < n)r += v[0][i];
      temp = min(r, temp);
    }

    cout << temp;
    cout << endl;
  }


  return 0;
}