#include <bits/stdc++.h>
using namespace std;
const long long N = 300010, M = 5005;
long long t, n, k, a[N], freq[N][6], sz[N], f[6];
string s;
priority_queue<long long> pq;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    long long len = 0, res = 0;
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; i++) {
      cin >> s;
      sz[i] = s.length();
      for (auto u : s) {
        freq[i][u - 'a']++;
        f[u - 'a']++;
      }
      len += sz[i];
    }
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < n; j++) {
        pq.push(sz[j] - 2 * freq[j][i]);
      }
      long long x = f[i], y = len - f[i];
      while (!pq.empty() && x <= y) {
        y -= pq.top();
        pq.pop();
      }
      if (x > y) res = max(res, (long long)pq.size());
      while (!pq.empty()) pq.pop();
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        freq[i][j] = 0;
      }
    }
    cout << res << "\n";
  }
  return 0;
}
