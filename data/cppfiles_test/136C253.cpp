#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
long long power(long long x, long long y) {
  long long ans = 1;
  x %= 1000000007;
  while (y) {
    if (y & 1) ans = (x * ans) % 1000000007;
    x = (x * x) % 1000000007;
    y >>= 1;
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  long long tot = (n * (n + 1)) / 2;
  if (sum % tot) {
    cout << "NO\n";
    return;
  }
  sum /= tot;
  vector<long long> ans;
  for (long long i = 0; i < n; i++) {
    long long diff;
    if (i) {
      diff = arr[i - 1] + sum - arr[i];
    } else {
      diff = arr[n - 1] + sum - arr[0];
    }
    if (diff <= 0 || (diff % n)) {
      cout << "NO\n";
      return;
    } else {
      ans.push_back(diff / n);
    }
  }
  cout << "YES\n";
  for (long long x : ans) {
    cout << x << " ";
  }
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
