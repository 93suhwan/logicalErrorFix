#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
template <class P>
void take(P &x) {
  cin >> x;
}
template <class P>
void take(P &x, P &y) {
  cin >> x >> y;
}
template <class P>
void take(P &x, P &y, P &z) {
  cin >> x >> y >> z;
}
template <class P>
void take(vector<P> &arr) {
  for (P &ai : arr) cin >> ai;
}
template <class P>
void take(vector<vector<P>> &arr) {
  long long n = arr.size();
  for (long long i = 0; i < (long long)(n); ++i) {
    for (long long j = 0; j < (long long)(arr[i].size()); ++j) cin >> arr[i][j];
  }
}
const long long M = 1e9 + 7;
long long mod(long long x) { return ((x % M + M) % M); }
long long add(long long a, long long b) { return mod(mod(a) + mod(b)); }
long long multiply(long long a, long long b) { return mod(mod(a) * mod(b)); }
void print() { cout << "\n"; }
void _print() { cerr << "\n"; }
template <typename Head, typename... Tail>
void print(Head H, Tail... T) {
  cout << H << " ";
  print(T...);
}
template <class P>
void print(vector<P> &arr) {
  for (P i : arr) cout << i << " ";
  cout << "\n";
}
template <class P>
void print(vector<vector<P>> &arr) {
  long long n = arr.size();
  for (long long i = 0; i < (long long)(n); ++i) {
    for (long long j = 0; j < (long long)(arr[i].size()); ++j)
      cout << arr[i][j] << " ";
    cout << "\n";
  }
}
template <typename Head, typename... Tail>
void _print(Head H, Tail... T) {
  cerr << H << " ";
  _print(T...);
}
template <class P>
void _print(vector<P> &arr) {
  cerr << "= [ ";
  for (P i : arr) cerr << i << " ";
  cerr << "]";
  cerr << "\n";
}
template <class P>
void _print(vector<vector<P>> &arr) {
  long long n = arr.size();
  cerr << "=[ ";
  for (long long i = 0; i < (long long)(n); ++i) {
    cerr << "[ ";
    for (long long j = 0; j < (long long)(arr[i].size()); ++j)
      cerr << arr[i][j] << " ";
    if (i != n - 1)
      cerr << "],";
    else
      cerr << "]";
  }
  cerr << " ]"
       << "\n";
}
long long findMin(vector<long long> arr) {
  long long mini = INT_MAX;
  for (long long i : arr) mini = min(mini, i);
  return mini;
}
long long findMax(vector<long long> arr) {
  long long maxi = INT_MIN;
  for (long long i : arr) maxi = max(maxi, i);
  return maxi;
}
long long leaf[200001];
vector<long long> adj[200001];
void dfs(long long cur = 1, long long par = 0) {
  leaf[cur] = 1;
  for (long long ch : adj[cur])
    if (ch != par) {
      dfs(ch, cur);
      if (leaf[ch]) leaf[cur] = 0;
    }
}
void solve(long long tc) {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; ++i) adj[i].clear();
  for (long long u = 1; u <= n - 1; ++u) {
    long long i, j;
    cin >> i >> j;
    adj[i].push_back(j);
    adj[j].push_back(i);
  }
  dfs();
  long long b = 0, l = 0;
  for (long long i = 2; i <= n; ++i)
    if (leaf[i])
      l++;
    else
      b++;
  long long direct_l = 0;
  for (long long i : adj[1]) direct_l += leaf[i];
  if (direct_l)
    cout << l - b << '\n';
  else
    cout << l - b + 1 << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(10);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}
