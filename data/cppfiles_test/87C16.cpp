#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
void solve(int cases) {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, a[i] - i - 1);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tt = 1;
  cin >> tt;
  int cases = 1;
  while (tt--) {
    solve(cases);
    cases++;
  }
  return 0;
}
