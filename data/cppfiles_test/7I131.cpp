#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int MX = 400005;
const long long MOD = 1000000007;
long long A[MX], B[MX];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  int sol = 1;
  B[0] = (1LL << 62LL);
  for (long long j = 2LL; j <= 100LL; j++) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      B[i] = A[i] % j;
      if (B[i] != B[i - 1]) {
        cnt = 1;
      } else
        cnt++;
      sol = max(sol, cnt);
    }
  }
  cout << sol << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
