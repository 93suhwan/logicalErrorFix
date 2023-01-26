#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;
int ask(const string &s, int i, int j) {
  cout << s << " " << ++i << " " << ++j << endl;
  cin >> i;
  return i;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n - 1), o(n - 1);
  vector<int> res(n);
  for (int i = 0; i + 1 < n; i++) {
    a[i] = ask("and", i, i + 1);
    o[i] = ask("or", i, i + 1);
  }
  int a02 = ask("and", 0, 2);
  for (int bit = 0; bit < 3; bit++) {
    if ((o[0] >> bit & 1) == (a[0] >> bit & 1)) {
      res[0] |= (a[0] & (1 << bit));
      res[1] |= (a[0] & (1 << bit));
    } else {
      if (a02 >> bit & 1) {
        res[0] |= 1 << bit;
      } else {
        res[1] |= 1 << bit;
      }
    }
    for (int i = 2; i < n; i++) {
      int a1 = a[i - 1] >> bit & 1;
      int o1 = o[i - 1] >> bit & 1;
      int pbit = res[i - 1] >> bit & 1;
      for (int c = 0; c <= 1; c++) {
        if ((pbit & c) == a1 && (pbit | c) == o1) {
          res[i] |= c << bit;
        }
      }
    }
  }
  sort(res.begin(), res.end());
  cout << "finish " << res[k - 1] << endl;
  return 0;
}
