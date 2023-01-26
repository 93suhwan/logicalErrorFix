#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const double EPS = 1e-9;
const double PI = acos(-1.);
const long long LL_INF = 1e17 + 16;
const int INF = 1e9 + 10;
const long long MOD = 998244353;
const int MAXN = 3e5 + 5;
void solve() {
  int n, s;
  scanf("%d%d", &n, &s);
  int ans = s / (n / 2 + 1);
  printf("%d\n", ans);
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
