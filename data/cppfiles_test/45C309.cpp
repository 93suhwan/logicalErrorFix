#include <bits/stdc++.h>
using namespace std;
void solution() {
  long long n, ans = 1;
  cin >> n;
  bool chk = 0;
  vector<long long> a(n);
  for (long long i = 0; i < n; i += 1) cin >> a[i];
  for (long long i = 0; i < n; i += 1) {
    if (a[i])
      ans += ((i > 0 && a[i - 1]) ? 5 : 1);
    else if (i > 0 && !a[i - 1]) {
      chk = 1;
      break;
    }
  }
  cout << (chk ? -1 : ans) << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solution();
  return 0;
}
