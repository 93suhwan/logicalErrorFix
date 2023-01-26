#include <bits/stdc++.h>
using namespace std;
const int64_t N = 1e5 + 5, mod = 1e9 + 7;
const int64_t N1 = 1e18;
void solve() {
  int64_t n, m, k;
  cin >> n >> m >> k;
  vector<int64_t> z(k);
  for (int64_t &it : z) {
    cin >> it;
  }
  cin >> k;
  vector<int64_t> z1(k);
  for (int64_t &it : z1) {
    cin >> it;
  }
  cin >> k;
  vector<int64_t> z2(k);
  for (int64_t &it : z2) {
    cin >> it;
  }
  cin >> k;
  vector<int64_t> z3(k);
  for (int64_t &it : z3) {
    cin >> it;
  }
  cout << max(m * max(abs(z[0] - z.back()), abs(z1[0] - z1.back())),
              n * max(abs(z2[0] - z2.back()), abs(z3[0] - z3.back())))
       << "\n";
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int64_t tq = 1;
  cin >> tq;
  for (; tq; tq--) {
    solve();
  }
}
