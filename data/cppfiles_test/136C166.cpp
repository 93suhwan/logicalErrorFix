#include <bits/stdc++.h>
using namespace std;
long long N = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  long long b[n];
  long long sum = 0;
  for (int i = 0; i < n; i++) sum += v[i];
  long long x = (n * (n + 1)) / 2;
  long long tot = sum / x;
  if (sum % x != 0) {
    cout << "NO";
    return;
  }
  b[0] = v[n - 1] - v[0];
  for (int i = 1; i < n; i++) {
    b[i] = v[i - 1] - v[i];
  }
  long long ans = 0;
  vector<long long> an;
  for (int i = 0; i < n; i++) {
    ans = (b[i] + tot) / (n);
    an.push_back(ans);
  }
  if ((b[0] + tot) % n != 0) an[0] = -1;
  int f = 1;
  for (int i = 0; i < n; i++) {
    if (an[i] <= 0) f = 0;
  }
  if (f) {
    cout << "YES\n";
    for (auto y : an) cout << y << " ";
  } else {
    cout << "NO";
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
