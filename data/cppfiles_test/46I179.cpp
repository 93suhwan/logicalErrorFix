#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const char nl = '\n';
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
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
  cerr << '[';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "]";
}
void _print() { cerr << "\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int mi = INT_MAX;
  int mx = 0;
  int mx_pos = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mi = min(mi, a[i]);
    if (mx < a[i]) {
      mx = a[i];
      mx_pos = i;
    }
  }
  if (mi == mx) {
    cout << 0 << nl;
    return;
  }
  if (a.back() == mx) {
    cout << 0 << nl;
    return;
  }
  ll add = 0;
  if (a.back() == mi) {
    vector<int> b, c;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] <= a[n - 1]) {
        b.push_back(a[i]);
      } else {
        c.push_back(a[i]);
      }
    }
    b.push_back(a[n - 1]);
    for (int e : c) {
      b.push_back(e);
    }
    mx = 0;
    for (int i = 0; i < n; i++) {
      if (mx < b[i]) {
        mx_pos = i;
        mx = b[i];
      }
    }
    a = b;
    add = 1;
  }
  if (mx_pos == n - 1) {
    cout << 1 << nl;
    return;
  }
  int ans = 0;
  for (int i = mx_pos + 1; i < n; i++) {
    if (a[i] > a[n - 1]) {
      ans++;
    }
  }
  cout << ans + add + 1 << nl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
