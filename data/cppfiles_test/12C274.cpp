#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vp = vector<P>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
template <class T>
void out(T a) {
  cout << a << endl;
}
template <class T>
void outv(T v) {
  for (int i = 0; i < ((int)v.size()); ++i) {
    if (i) cout << ' ';
    cout << v[i];
  }
  cout << endl;
}
template <class T>
void outvv(T v) {
  for (int i = 0; i < ((int)v.size()); ++i) outv(v[i]);
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    int cnt = 0;
    if (n % 2 == 1) {
      n--;
      cnt += m / 2;
    }
    if (m % 2 == 1) {
      m--;
    }
    bool ok = 1;
    if (cnt > k) ok = 0;
    cnt += (n * m) / 2;
    if (cnt < k) ok = 0;
    if ((cnt % 2) != (k % 2)) ok = 0;
    out(ok ? "YES" : "NO");
  }
  return 0;
}
