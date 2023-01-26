#include <bits/stdc++.h>
using namespace std;
long long n = 0;
long long cnt = 0;
void solve(string ans, long long open, long long close) {
  if (cnt >= n) {
    return;
  }
  if (open == 0 && close == 0) {
    cout << ans << '\n';
    cnt++;
    return;
  }
  if (open > 0) {
    solve(ans + '(', open - 1, close);
  }
  solve(ans + ')', open, close - 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    cnt = 0;
    string ans;
    solve(ans, n, n);
  }
  return 0;
}
