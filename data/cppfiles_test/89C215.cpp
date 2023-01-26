#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void debug() { cerr << "\n"; }
template <typename Head, typename... Tail>
void debug(Head a, Tail... b) {
  cerr << a << " ";
  debug(b...);
}
template <class T>
void umin(T &a, T b) {
  a = min(a, b);
}
template <class T>
void umax(T &a, T b) {
  a = max(a, b);
}
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int mod = 1e9 + 7, N = 1e6 + 5;
void solve() {
  int n;
  int del = 0;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] % 2 == 0) {
      int index = i - del;
      if (a[i] % (index + 1) != 0) {
        continue;
      } else {
        int left = i - 1 - del;
        bool ok = 0;
        while (left > 0) {
          left--;
          del++;
          index = i - del;
          if (a[i] % (index + 1) != 0) {
            ok = 1;
            break;
          }
        }
        if (!ok) {
          cout << "NO\n";
          return;
        }
        del = 0;
      }
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
