#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long mod = 1e9 + 7;
const long long linf = 1e18;
const double EPS = 1e-10;
const double pi = acos(-1);
template <class T>
void chmin(T& x, T y) {
  if (x > y) x = y;
}
template <class T>
void chmax(T& x, T y) {
  if (x < y) x = y;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 1; i <= n / 2; i++) {
    cout << a[i] << " " << a[0] << endl;
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
