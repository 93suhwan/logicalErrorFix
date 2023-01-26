#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int mxm = 1e18;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n], i;
    set<long long int> x;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      x.insert(a[i]);
    }
    vector<long long int> v(n, 0);
    for (auto xx : x) {
      if (xx <= n) v[xx - 1] = xx;
    }
    long long int ans = 0;
    vector<long long int> w;
    for (i = 0; i < n; i++) {
      if (a[i] > n) {
        w.push_back(a[i]);
      }
    }
    sort((w).begin(), (w).end());
    long long int j = 0, m = w.size();
    for (i = 0; i < n && j < m; i++) {
      if (v[i] == 0) {
        if (w[j] > 2 * (i + 1)) {
          ans++;
        } else {
          ans = -1;
          break;
        }
        j++;
      }
    }
    cout << (ans) << endl;
  }
  return 0;
}
