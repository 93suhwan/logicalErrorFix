#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const int inf = 1e9;
const int N = 2e5 + 10;
bool flag;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long cnt = n * (n - 1) >> 1;
  if (cnt < m || m < n - 1) {
    cout << "NO";
    return;
  }
  long long fl = 2;
  if (cnt == m) fl = 1;
  if (n == 1) fl = 0;
  cout << (fl < k - 1 ? "YES" : "NO");
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(12);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    flag = 0;
    solve();
    cout << '\n';
  }
  return 0;
}
