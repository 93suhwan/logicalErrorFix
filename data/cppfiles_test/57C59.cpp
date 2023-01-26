#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long s, n, k;
  cin >> s >> n >> k;
  if (s < k)
    cout << "NO";
  else if (s == k)
    cout << "YES";
  else {
    auto a = s / (2 * k) * k;
    auto b = s % (2 * k);
    b = min(b, k - 1);
    if (a + b < n)
      cout << "YES";
    else
      cout << "NO";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
