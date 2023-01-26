#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
vector<pair<int, int>> q;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), d(n);
    long long ans = 0, t = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      q.push_back({a[i], a[i]});
      for (int j = q.size() - 2; j >= 0 && q[j + 1].second < q[j].first; j--) {
        auto &z = q[j];
        t -= d[j];
        int div = ((a[j] - 1) / q[j + 1].first);
        t += (d[j] = div * (j + 1));
        t %= mod;
        z = make_pair(a[j] / (div + 1) + ((a[j] % (div + 1)) > 0),
                      a[j] / (div + 1));
      }
      ans = (ans + t) % mod;
      ;
    }
    q.clear();
    cout << (ans + mod) % mod << endl;
  }
  return 0;
}
