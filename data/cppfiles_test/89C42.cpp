#include <bits/stdc++.h>
long long T, U;
using namespace std;
long long ans;
vector<long long> bian[1000005];
long long go(long long now, long long fa) {
  long long cnt = 0;
  for (long long next : bian[now]) {
    if (next == fa) continue;
    cnt += go(next, now);
  }
  if (cnt) {
    ans += cnt - 1;
    return 0;
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  srand(time(NULL));
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) bian[i].clear();
    U = n - 1;
    while (U--) {
      long long u, v;
      cin >> u >> v;
      bian[u].push_back(v);
      bian[v].push_back(u);
    }
    ans = 1;
    go(1, 0);
    cout << ans << "\n";
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms";
  return 0;
}
