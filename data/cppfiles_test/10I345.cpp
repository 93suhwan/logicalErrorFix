#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n), c(n, -1);
    vector<long long> adj[n + 1];
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      a[i] = x;
      adj[x].push_back(i);
    }
    long long rem = n, to_use = 1, l = -1;
    long long flag = 0, z = 0, f = 0;
    for (long long i = 0; i < n; i++) {
      if (c[i] == -1) {
        long long cnt = 0;
        f = 0;
        long long s = adj[a[i]].size();
        z += min(k, s);
        for (auto j : adj[a[i]]) {
          if (flag || (rem < k && to_use == 1)) {
            c[j] = 0;
            rem--;
            flag = 1;
            continue;
          }
          c[j] = to_use;
          cnt++;
          if (to_use == 0 && cnt < adj[a[i]].size())
            ;
          else if (cnt >= k && adj[a[i]].size() > cnt)
            l = (to_use == k) ? 1 : to_use + 1, to_use = 0;
          else if (to_use == 0 && cnt >= adj[a[i]].size())
            to_use = l;
          else
            to_use = (to_use == k) ? 1 : to_use + 1;
          rem--;
        }
      }
    }
    map<long long, long long> ct;
    for (long long i = 0; i < n; i++) {
      ct[c[i]]++;
      if (ct[c[i]] > z)
        cout << 0 << " ";
      else
        cout << c[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}
