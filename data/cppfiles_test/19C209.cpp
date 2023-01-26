#include <bits/stdc++.h>
using namespace std;
void write(vector<int> &v) {
  for (auto i : v) cout << i << " ";
  cout << "\n";
}
void read(vector<int> &v) {
  for (auto &i : v) cin >> i;
}
const int INF = 1e9;
const int64_t INFF = 1e18;
const int N = 1e6 + 5;
int a[15];
int n;
bool calc(int i, int sum, int cnt) {
  if (i == n) {
    if (cnt > 0 && sum == 0) return true;
    return false;
  }
  bool sol1, sol2, sol3;
  sol1 = calc(i + 1, sum + a[i], 1);
  sol2 = calc(i + 1, sum - a[i], 1);
  sol3 = calc(i + 1, sum, cnt);
  return sol1 || sol2 || sol3;
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  if (calc(0, 0, 0)) {
    cout << "YES"
         << "\n";
  } else
    cout << "NO"
         << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
