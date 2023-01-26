#include <bits/stdc++.h>
using namespace std;
const long long INF = 1 << 31 - 1;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long res = -INF;
    long long n, e;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
      cin >> e;
      v[i] = e - i - 1;
    }
    for (auto e : v) {
      res = max(res, e);
    }
    cout << res << endl;
  }
}
