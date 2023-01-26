#include <bits/stdc++.h>
using namespace std;
template <class... Args>
void debug(Args... args) {
  auto tmp = {(cout << args << '\t', 0)...};
  cout << endl;
}
using ll = long long;
const int N = 1e3 + 10;
const int mod = 4933;
const double eps = 1e-9;
int a[N];
int n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  ll ans = 0;
  for (int i = 1; i <= n; i += 2) {
    int x = 0;
    int y = 0;
    int z = 0;
    for (int j = i + 1; j <= n; j += 2) {
      int d = abs(x - y);
      if (x == y) {
        if (z == 0) {
          ans += min(a[i], a[j]);
        } else {
          ans += max(0, min(a[i], a[j]) - z + 1);
        }
      } else if (x > y) {
        ans += max(0, min(a[i], a[j] - d) - z + 1);
      } else {
        ans += max(0, min(a[i] - d, a[j]) - z + 1);
      }
      y += a[j];
      z = max(z, y - x);
      x += a[j + 1];
    }
  }
  cout << ans;
}
