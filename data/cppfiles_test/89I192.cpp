#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const long long INF = 1e18;
long long biex(long long a, long long b) {
  if (b == 0) return 1;
  long long ans = biex(a, b / 2);
  ans = ans * ans;
  if (b & 1)
    return ans * a;
  else
    return ans;
}
const int N = 1e5;
long long fact[N] = {0};
void solve() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (a[1] % 2 == 0) {
    cout << "NO\n";
  } else {
    for (int i = 2; i <= n; i++) {
      if (fact[i + 1] == 0) continue;
      if (a[i] % fact[i + 1] == 0) {
        cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fact[0] = 1;
  fact[1] = 1;
  for (int i = 2; i <= 100; i++) {
    long long x = (long long)i * fact[i - 1];
    if (x > 1e9) break;
    fact[i] = x;
  }
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) solve();
  return 0;
}
