#include <bits/stdc++.h>
using namespace std;
void err() { cout << endl; }
template <class T, class... Ts>
void err(T arg, Ts &...args) {
  cout << arg << ' ';
  err(args...);
}
const int N = 2e5 + 10;
const long long mod = 1e9 + 7;
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
long long rng(long long l, long long r) {
  uniform_int_distribution<long long> uni(l, r);
  return uni(mt);
}
int a[N][5];
void solve(int tCase) {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 5; ++j) {
      cin >> a[i][j];
    }
  }
  bool f = false;
  for (int i = 0; i < 5; ++i) {
    for (int j = i + 1; j < 5; ++j) {
      int ci = 0, cj = 0, cij = 0;
      for (int k = 1; k <= n; ++k) {
        if (a[k][i]) ci++;
        if (a[k][j]) cj++;
        if (a[k][i] && a[k][j]) cij++;
      }
      if (ci >= n / 2 && cj >= n / 2 && ci + cj - cij == n) {
        f = true;
      }
    }
  }
  if (f)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve(t);
  }
  return 0;
}
