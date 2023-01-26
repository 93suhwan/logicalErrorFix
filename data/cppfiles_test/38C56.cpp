#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;
const ll inf = (1e18);
const ll mod = 1000000007;
const vector<int> dy = {-1, 0, 1, 0}, dx = {0, -1, 0, 1};
ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
ll LCM(ll c, ll d) { return c / GCD(c, d) * d; }
struct __INIT {
  __INIT() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} __init;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
void debag(const vector<T> &a) {
  cerr << "debag :";
  for (auto v : a) cerr << v << " ";
  cerr << "\n";
}
template <class T>
void print(const vector<T> &a) {
  for (auto v : a) cout << v << " ";
  cout << "\n";
}
void solve() {
  int n, m;
  cin >> n >> m;
  V<string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  V<int> cnt(m + 1, 0);
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      if (s[i][j + 1] == 'X' && s[i + 1][j] == 'X') {
        cnt[j + 1] = 1;
      }
    }
  }
  for (int i = 0; i < m; i++) cnt[i + 1] += cnt[i];
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    if (cnt[b] - cnt[a] > 0)
      cout << "NO"
           << "\n";
    else
      cout << "YES"
           << "\n";
  }
}
int main() {
  int t = 1;
  while (t--) solve();
}
