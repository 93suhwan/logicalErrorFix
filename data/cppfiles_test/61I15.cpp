#include <bits/stdc++.h>
using namespace std;
long long a[200005];
void solve() {
  int n;
  cin >> n;
  int a[n + 1], b[n + 1];
  unordered_map<int, int> ma, mb;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    ma[a[i]]++;
    mb[b[i]]++;
  }
  long long ans = n * 1LL * (n - 1) * (n - 2) / 6;
  for (int i = 0; i < n; i++) {
    ans -= (ma[a[i]] - 1) * (mb[b[i]] - 1);
  }
  cout << ans << '\n';
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
