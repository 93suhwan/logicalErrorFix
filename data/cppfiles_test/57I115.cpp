#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long s, n, k;
  cin >> s >> n >> k;
  if (k == s) {
    cout << "YES\n";
    return;
  }
  if (k >= n) {
    cout << "NO\n";
    return;
  }
  if (s / n >= 2) {
    cout << "NO\n";
    return;
  }
  long long nr2 = s - n;
  long long nr1 = n - nr2;
  if (nr2 >= k && nr1 < k) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
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
