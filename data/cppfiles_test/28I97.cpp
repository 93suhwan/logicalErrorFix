#include <bits/stdc++.h>
using namespace std;
void solve(long long TEST_CASE) {
  long long n, m;
  cin >> n >> m;
  vector<long long> p(n);
  for (long long i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  map<long long, long long> f;
  for (long long j = 0; j < n; j++) f[(n + j - p[j]) % n]++;
  set<long long> ans;
  for (auto it : f) {
    if (3 * it.second >= n) {
      vector<long long> a(n);
      map<long long, long long> rm;
      for (long long i = 0; i < n; i++) {
        a[(i + it.first) % n] = i;
        rm[i] = (i + it.first) % n;
      }
      vector<bool> visited(n);
      long long swaps = 0;
      for (long long i = 0; i < n; i++) {
        if (!visited[a[i]]) {
          long long cnt = 1;
          visited[a[i]] = true;
          for (long long j = p[rm[a[i]]]; j != a[i]; j = p[rm[j]]) {
            visited[j] = true;
            cnt++;
          }
          if (cnt > 2)
            swaps += cnt;
          else
            swaps += cnt - 1;
        }
      }
      if (swaps <= m) {
        ans.insert(it.first);
      }
    }
  }
  cout << ans.size() << " ";
  for (auto it : ans) cout << it << " ";
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long test_cases;
  cin >> test_cases;
  for (long long i = 1; i <= test_cases; i++) solve(i);
}
