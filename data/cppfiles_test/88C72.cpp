#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
using pi = pair<int, int>;
using vi = vector<int>;
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
void cdb(int n, db m) { cout << fixed << setprecision(n) << m; }
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
const db eps = 1e-6;
const db PI = acos((db)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
void init_code();
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (n % 2 == 0) {
    cout << "YES\n";
  } else {
    for (int i = 1; i + 1 <= n; i++) {
      if (a[i] >= a[i + 1]) {
        cout << "YES\n";
        return;
      }
    }
    cout << "NO\n";
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
void init_code() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
