#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 50;
const long long M = 1e6 + 50;
long long a[N];
signed main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    map<long long, long long> vis;
    long long n;
    cin >> n;
    long long p = INT_MAX;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      vis[a[i]]++;
      p = min(p, a[i]);
    }
    long long cnt = 0;
    for (auto it : vis) {
      if (it.first == p) continue;
      for (long long i = 1; i <= it.second; i++) {
        cout << it.first << " " << p << endl;
        cnt++;
        if (cnt == n / 2) break;
      }
      if (cnt == n / 2) break;
    }
  }
  return 0;
}
