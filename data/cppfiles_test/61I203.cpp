#include <bits/stdc++.h>
using namespace std;
int main() {
  long long T = 1;
  cin >> T;
  while (T--) {
    long long n, i, j, m, ans = 0, c = 0, x, y, k;
    cin >> n;
    long long a[n];
    vector<long long> v[n + 1], v1[n + 1];
    for (i = 0; i < n; i++) {
      cin >> x >> y;
      v[x].push_back(y);
      v1[y].push_back(x);
    }
    c = (n * (n - 1) * (n - 2)) / 6;
    for (i = 1; i <= n; i++) {
      m = v[i].size();
      k = (m * (m - 1)) / 2;
      for (auto it : v[i]) {
        m = v1[it].size() - 1;
        c = c - k * m;
      }
    }
    cout << c;
    cout << endl;
  }
  return 0;
}
