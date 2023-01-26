#include <bits/stdc++.h>
using namespace std;
void _print(long long int t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
long long int powe(long long int x, long long int y,
                   long long int p = 998244353) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int inverse_modulo(long long int a, long long int p = 998244353) {
  return powe(a, p - 2, p);
}
vector<long long int> fact(200001, 1);
void fill_fact(long long int p = 998244353) {
  for (int i = 1; i < (int)200001; i++) {
    fact[i] = (fact[i - 1] * i) % p;
  }
}
template <class T, class vv>
void _print(pair<T, vv> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class vv>
void _print(map<T, vv> v);
template <class T>
void _print(multiset<T> v);
template <class T, class vv>
void _print(pair<T, vv> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class vv>
void _print(map<T, vv> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int ma = 0, ma2 = 0;
  for (int i = 0; i < (int)n; i++) {
    cin >> a[i];
    ma = max(ma, a[i]);
  }
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < (int)n; i++) {
    if (a[i] != ma)
      ma2 = max(ma2, a[i]);
    else
      cnt1++;
  }
  if (cnt1 > 1) {
    cout << fact[n] << "\n";
    return;
  }
  if (ma - ma2 > 1) {
    cout << 0 << "\n";
    return;
  }
  for (int i = 0; i < (int)n; i++) {
    if (a[i] == ma2) cnt2++;
  }
  long long int ans = ((cnt2 * fact[n]) % 998244353) * inverse_modulo(cnt2 + 1);
  ans %= 998244353;
  cout << ans << "\n";
}
int main() {
  freopen("Error.txt", "w", stderr);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  fill_fact();
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
