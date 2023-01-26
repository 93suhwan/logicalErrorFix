#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long s, n, k;
  cin >> s >> n >> k;
  if (k == s) {
    cout << "YES\n";
    return;
  }
  long long smin;
  smin = (n / k) * 2LL * k + n % k;
  if (s >= smin) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int nrt;
  cin >> nrt;
  for (int i = 1; i <= nrt; i++) {
    solve();
  }
  return 0;
}
