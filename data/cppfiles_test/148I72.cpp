#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, mod = 1e9 + 7;
const int64_t N1 = 1e18;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> z(k);
  for (int &it : z) {
    cin >> it;
  }
  cin >> k;
  vector<int> z1(k);
  for (int &it : z1) {
    cin >> it;
  }
  cin >> k;
  vector<int> z2(k);
  for (int &it : z2) {
    cin >> it;
  }
  cin >> k;
  vector<int> z3(k);
  for (int &it : z3) {
    cin >> it;
  }
  cout << max(m * max(abs(z[0] - z.back()), abs(z1[0] - z1.back())),
              n * max(abs(z2[0] - z2.back()), abs(z3[0] - z3.back())))
       << "\n";
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int tq = 1;
  cin >> tq;
  for (; tq; tq--) {
    solve();
  }
}
