#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 2;
const long long mod = 1000000007;
long long a[N], n, d, vis[N], cost[N];
void dfs(long long u) {
  vis[u] = 1;
  a[u] = 0;
  long long v = (u + d + n) % n;
  if (vis[v]) return;
  if (a[v] == 0) return;
  cost[v] = cost[u] + 1;
  dfs(v);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans = -(1LL << 61), cantbe0 = 0;
    for (int i = 0; i < n; i++) {
      if (vis[i]) continue;
      long long mxLen = 0, curr = i, currLen = 0, fullLen = 0, preLen = 0,
                c0 = 0;
      while (1) {
        vis[curr] = 1;
        if (a[curr] == 1)
          currLen++;
        else {
          if (c0 == 0) preLen = currLen;
          c0++;
          mxLen = max(mxLen, currLen);
          currLen = 0;
        }
        fullLen++;
        curr = (curr + d) % n;
        if (curr == i) break;
      }
      currLen += preLen;
      mxLen = max(mxLen, currLen);
      if (fullLen == mxLen) cantbe0 = 1;
      ans = max(ans, mxLen);
    }
    if (cantbe0) ans = -1;
    cout << ans << "\n";
    for (int i = 0; i < n; i++) vis[i] = 0;
  }
}
