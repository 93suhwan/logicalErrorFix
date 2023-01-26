#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long a[n];
  for (auto &x : a) cin >> x;
  long long ans[n];
  map<long long, vector<long long>> m;
  for (long long i = 0; i < n; i++) {
    ans[i] = -1;
    m[a[i]].push_back(i);
  }
  long long remaining = n, color = 0;
  map<long long, long long> count;
  for (auto it : m) {
    long long firstcolor = color;
    for (long long i = 0; i < it.second.size(); i++) {
      ans[it.second[i]] = color;
      count[color]++;
      color = (color + 1) % k;
      remaining--;
      if (color == firstcolor) {
        remaining -= (it.second.size() - i);
        break;
      }
    }
  }
  long long minimum = count[0];
  for (auto it : count) minimum = min(minimum, it.second);
  for (long long i = 0; i < n; i++) {
    if (count[ans[i]] > minimum) {
      count[ans[i]]--;
      cout << "0 ";
    } else
      cout << ans[i] + 1 << " ";
  }
  cout << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
