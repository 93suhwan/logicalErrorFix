#include <bits/stdc++.h>
using namespace std;
void solve() {}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> arr(n + 1);
    arr[0] = -1;
    for (long long int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    long long int ans = 0;
    long long int i = 1;
    for (i = 1; i <= n - 2 * k; i++) ans += arr[i];
    map<long long int, long long int> m;
    for (; i <= n; i++) m[arr[i]] += 1;
    set<long long int> a;
    for (auto e : m) {
      a.insert(e.first);
    }
    while (a.size() > 1) {
      long long int o = *a.begin(), p = *(++a.begin());
      ;
      ans += (o / p) * min(m[o], m[p]);
      m[o] -= min(m[o], m[p]);
      m[p] -= min(m[o], m[p]);
      if (m[o] == 0) a.erase(o);
      if (m[p] == 0) a.erase(p);
    }
    if (!a.empty()) ans += (m[*a.begin()] / 2);
    cout << ans << "\n";
  }
  return 0;
}
