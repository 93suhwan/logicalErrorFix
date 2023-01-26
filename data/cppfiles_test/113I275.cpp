#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  set<int> ms;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    ms.insert(a[i]);
  }
  sort(a.begin(), a.end());
  int m;
  cin >> m;
  while (m--) {
    long long x, y;
    cin >> x >> y;
    long long myMin = 1e9;
    auto it = ms.lower_bound(x);
    if (it != ms.end()) myMin = min(myMin, max(y - (sum - *it), 0ll));
    it--;
    myMin = min(max(x - *it, 0ll) + max(y - (sum - *it), 0ll), myMin);
    cout << myMin << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
