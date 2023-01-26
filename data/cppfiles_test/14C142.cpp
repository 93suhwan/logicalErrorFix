#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, t, k, c, d;
  string s;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long> a, b, l, r;
    for (int i = 0; i < n; i++) {
      cin >> c;
      a.push_back(c);
      b.push_back(c);
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
      for (int j = n - i - 1; j > -1; j--) {
        if (i == 0 && j == n - i - 1 && a[j] == b[i]) {
          break;
        }
        if (a[j] == b[i]) {
          l.push_back(j + 1);
          a.erase(a.begin() + j);
          break;
        }
      }
    }
    cout << l.size() << endl;
    for (auto x : l) {
      cout << x << " " << n << " " << 1 << endl;
    }
  }
  return 0;
}
