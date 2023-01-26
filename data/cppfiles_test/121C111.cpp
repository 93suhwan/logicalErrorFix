#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  bool same = true;
  for (long long i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      same = false;
      break;
    }
  }
  if (same) {
    cout << 0 << '\n';
    return;
  }
  long long correct = 0;
  long long correct_ones = 0;
  long long wrong_ones = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] == b[i]) correct++;
    if (a[i] == b[i] && a[i] == '1') correct_ones++;
    if (a[i] != b[i] && a[i] == '1') wrong_ones++;
  }
  long long ans = INT_MAX;
  if (correct_ones != 0) {
    if (correct % 2 == 1) {
      if ((correct_ones >= correct / 2 + 1) &&
          ((correct - correct_ones) >= correct / 2))
        ans = min(ans, correct);
    }
  }
  if (wrong_ones != 0) {
    if ((n - correct) % 2 == 0) {
      if ((wrong_ones >= (n - correct) / 2) &&
          (n - correct - wrong_ones >= (n - correct) / 2))
        ans = min(ans, n - correct);
    }
  }
  if (ans == INT_MAX) ans = -1;
  cout << ans << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
