#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int occ[n + 2], a[n];
    for (int i = 0; i <= n + 1; i++) occ[i] = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[i] = x;
      occ[x]++;
    }
    sort(a, a + n);
    long long ans[n + 1];
    ans[0] = occ[0];
    priority_queue<int> pq;
    bool ok = 1;
    for (int i = 1; i <= n && ok; i++) {
      ans[i] = ans[i - 1] - occ[i - 1];
      for (int j = 0; j < occ[i - 1]; j++) pq.push(i - 1);
      if (pq.empty()) {
        ok = 0;
        for (int k = i; k <= n; k++) ans[k] = -1;
        break;
      }
      ans[i] += (i - 1 - pq.top());
      ans[i] += occ[i];
      pq.pop();
    }
    for (int i = 0; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
  }
}
