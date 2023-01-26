#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k > n * m / 2) {
    cout << "NO" << '\n';
    ;
    return;
  }
  if (n % 2 == 0 && m % 2 == 0) {
    cout << ((k % 2 != 0) ? "NO" : "YES") << '\n';
    ;
  } else if (n % 2 != 0 && m % 2 == 0) {
    if (k < m / 2) {
      cout << "NO" << '\n';
      ;
    } else {
      k -= m / 2;
      cout << ((k % 2 != 0) ? "NO" : "YES") << '\n';
      ;
    }
  } else if (n % 2 == 0 && m % 2 != 0) {
    if (k > n * m / 2 - n / 2) {
      cout << "NO" << '\n';
      ;
    } else {
      int h = n * m / 2 - k;
      h -= n / 2;
      cout << ((h % 2 != 0) ? "NO" : "YES") << '\n';
      ;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
