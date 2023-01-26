#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 1;
const long long infll = 1e18 + 1;
const int mod = 998244353;
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T>
bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
struct smth {
  int x;
};
void solve() {
  int n;
  cin >> n;
  long long b[n];
  long long s = 0;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    s += b[i];
  }
  long long bg = 1ll * n * (n + 1) / 2;
  if (s % bg != 0) {
    cout << "NO\n";
    return;
  }
  s /= bg;
  vector<long long> a;
  for (int i = 0; i < n; i++) {
    long long cur;
    if (i == 0) {
      cur = b[n - 1] - b[0] + s;
    } else {
      cur = b[i - 1] - b[i] + s;
    }
    if (cur <= 0 || cur % n != 0) {
      cout << "NO\n";
      return;
    }
    a.push_back(cur / n);
  }
  cout << "YES\n";
  for (long long i : a) {
    cout << i << ' ';
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
