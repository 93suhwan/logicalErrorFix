#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T;
  cin >> T;
  while (T--) {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> a(n), ans(n + 1);
    map<long long int, long long int> freq, m, vis;
    vector<vector<long long int> > v(n + 1);
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      freq[a[i]]++;
      v[a[i]].push_back(i);
    }
    long long int tem = 0;
    for (long long int i = 0; i < n; i++) {
      if (freq[a[i]] >= k) {
        m[a[i]]++;
        if (m[a[i]] <= k) {
          ans[i] = m[a[i]];
        }
      } else
        tem++;
    }
    tem = tem - tem % k;
    long long int t = 0, r = 0;
    for (long long int i = 0; i < n; i++) {
      if (vis[a[i]] == 0 && freq[a[i]] < k) {
        for (auto j : v[a[i]]) {
          t++;
          if (t % (k + 1) == 0) t++;
          r++;
          if (r > tem) break;
          ans[j] = t % (k + 1);
        }
        vis[a[i]] = 1;
      }
      if (r > tem) break;
    }
    for (long long int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
  }
}
