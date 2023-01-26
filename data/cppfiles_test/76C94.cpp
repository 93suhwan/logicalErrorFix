#include <bits/stdc++.h>
using namespace std;
const long long maxn = 200005;
long long res[maxn];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  res[1] = 1;
  long long total = 1;
  for (long long i = 2; i <= n; i++) {
    res[i] = total;
    vector<long long> v1, v2;
    long long maxi = 0;
    for (long long j = 1; j * j <= i; j++) {
      if (j != 1) {
        res[i] = (res[i] + res[i / j]) % m;
      }
      long long o = i / j;
      maxi = max(maxi, j);
      if (o != j) v2.push_back(o);
    }
    v2.push_back(maxi);
    for (long long j = v2.size() - 2; j >= 0; j--) {
      res[i] = (res[i] + res[i / v2[j]] * (v2[j] - v2[j + 1])) % m;
    }
    total = (total + res[i]) % m;
  }
  cout << res[n] << '\n';
}
