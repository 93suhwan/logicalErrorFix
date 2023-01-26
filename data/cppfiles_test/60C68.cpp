#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const long long inf = 2e18;
int a[maxn];
map<int, int> cnt;
void solve() {
  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sum *= 2;
  if (sum % n) {
    cout << 0 << endl;
    return;
  }
  cnt.clear();
  long long kk = sum / n;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += cnt[kk - a[i]];
    cnt[a[i]]++;
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
