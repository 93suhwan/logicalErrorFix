#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
const int mx = 1e6 + 5;
const int INF = 1000000007;
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y >>= 1;
    x = (x * x) % 1000000007;
  }
  return (res % 1000000007);
}
void solve() {
  long long n;
  cin >> n;
  long long ans = n / 10 + (n % 10 == 9 ? 1 : 0);
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
