#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 50;
long long n;
long long a[N];
vector<long long> ancestors[N];
long long findPar(long long u) {
  long long k = (long long)log2(u);
  if ((1ll << k) < u) {
    return (1ll << (k + 1)) - u;
  }
  return (1ll << k) - u;
}
void findAncestors(long long i) {
  long long u = a[i];
  while (true) {
    ancestors[i].push_back(u);
    if (u == 0) break;
    long long par = findPar(u);
    u = par;
  }
  reverse((ancestors[i]).begin(), (ancestors[i]).end());
}
long long findDistance(long long i, long long j) {
  long long k = 0;
  long long ans =
      (long long)ancestors[i].size() - 1 + (long long)ancestors[j].size() - 1;
  while (k < min(ancestors[i].size(), ancestors[j].size())) {
    if (ancestors[i][k] != ancestors[j][k]) break;
    k++;
  }
  --k;
  return ans - 2 * k;
}
signed main(signed argc, const char *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < n; i++) {
    findAncestors(i);
  }
  long long ptr_deepest = -1;
  long long mx = 0;
  for (long long i = 0; i < n; i++) {
    if (mx < ancestors[i].size()) {
      mx = (long long)ancestors[i].size();
      ptr_deepest = i;
    }
  }
  long long ans = 0;
  long long x, y;
  for (long long i = 0; i < n; i++) {
    long long distance = findDistance(ptr_deepest, i);
    if (distance > ans) {
      ans = distance;
      x = i;
      y = ptr_deepest;
    }
  }
  cout << x + 1 << ' ' << y + 1 << ' ' << ans << '\n';
}
