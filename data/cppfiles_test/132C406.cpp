#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vvvl = vector<vector<vector<ll>>>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
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
template <class T>
inline void prn(vector<T>& v) {
  int n = (int)v.size();
  for (int i = (0); i < ((n)); i++) cout << v[i] << ' ';
}
template <class T>
inline void printv(vector<T>& v) {
  int n = (int)v.size();
  for (int i = (0); i < ((n)); i++) cout << v[i] << (i == n - 1 ? '\n' : ' ');
}
template <class T>
inline void printvv(vector<vector<T>>& v) {
  for (auto u : v) printv(u);
}
template <class T>
inline void printvm(vector<T>& v) {
  int n = (int)v.size();
  for (int i = (0); i < ((n)); i++)
    cout << v[i].val() << (i == n - 1 ? '\n' : ' ');
}
template <class T>
inline void printvvm(vector<vector<T>>& v) {
  for (auto u : v) printvm(u);
}
template <class T>
inline void printlnv(vector<T>& v) {
  int n = (int)v.size();
  for (int i = (0); i < ((n)); i++) cout << v[i] << '\n';
}
const int MOD = 1000000007;
const int INF = 1000000001;
const ll LINF = 1000000001000000001LL;
void solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(numeric_limits<double>::max_digits10);
  solve();
  return 0;
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n = 7;
    vi b(n);
    for (int i = (0); i < ((n)); i++) cin >> b[i];
    sort((b).begin(), (b).end());
    vi a = b;
    do {
      vi ans(n);
      ans[0] = a[0];
      ans[1] = a[1];
      ans[2] = a[2];
      ans[3] = a[0] + a[1];
      ans[4] = a[0] + a[2];
      ans[5] = a[1] + a[2];
      ans[6] = a[0] + a[1] + a[2];
      sort((ans).begin(), (ans).end());
      if (ans == b) {
        cout << a[0] << " " << a[1] << " " << a[2] << '\n';
        break;
      }
    } while (next_permutation((a).begin(), (a).end()));
  }
}
