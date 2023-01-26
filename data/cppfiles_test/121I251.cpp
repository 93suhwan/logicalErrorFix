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
  bool correct_x = false;
  bool wrong = false;
  for (long long i = 0; i < n; i++) {
    if (a[i] == b[i]) correct++;
    if (a[i] == b[i] && a[i] == '1') correct_x = true;
    if (a[i] != b[i] && a[i] == '1') wrong = true;
  }
  long long ans = -1;
  if (correct_x == false && wrong == false)
    ans = -1;
  else if (correct_x && wrong)
    ans = min(correct, n - correct);
  else if (correct_x)
    ans = correct;
  else if (wrong)
    ans = n - correct;
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
