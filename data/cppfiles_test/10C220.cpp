#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 5;
vector<long long> a[maxn];
long long b[maxn];
long long ans[maxn];
signed main() {
  ios::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    set<long long> s;
    cin >> n >> k;
    long long min = 1e9;
    long long sum = 0;
    for (long long i = 1; i <= n; i++) {
      cin >> b[i];
      s.insert(b[i]);
      a[b[i]].push_back(i);
    }
    for (auto& i : s) {
      long long tmp = a[i].size() < k ? a[i].size() : k;
      sum += tmp;
    }
    sum = sum - sum % k;
    long long now = 1;
    for (auto& i : s) {
      long long tmp = 1;
      for (auto& j : a[i]) {
        if (tmp <= k && sum != 0) {
          tmp++;
          ans[j] = now++;
          if (now > k) now -= k;
          sum--;
        } else
          ans[j] = 0;
      }
    }
    for (long long i = 1; i <= n; i++) {
      a[b[i]].pop_back();
    }
    for (long long i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
  }
}
