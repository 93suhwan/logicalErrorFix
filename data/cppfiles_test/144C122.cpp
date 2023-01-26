#include <bits/stdc++.h>
using namespace std;
long long i, j, k, n, m, t, x, y, l, r, sb;
vector<long long> v;
void show() {
  cout << v.size() << ' ';
  for (auto i : v) {
    cout << i << ' ';
  }
  v.clear();
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> m >> sb;
    x = n % m;
    y = n / m + 1;
    l = 1;
    r = l + y * x - 1;
    for (i = 1; i <= sb; i++) {
      v.clear();
      for (j = l; j <= r; j++) {
        k = (j % n + 1);
        v.push_back(k);
        if (v.size() == y) {
          show();
        }
      }
      for (j = r + 1; j <= l + n - 1; j++) {
        k = (j % n + 1);
        v.push_back(k);
        if (v.size() == (y - 1)) {
          show();
        }
      }
      l = r + 1;
      r = l + y * x - 1;
    }
    cout << '\n';
  }
}
