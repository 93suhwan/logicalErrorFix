#include <bits/stdc++.h>
using namespace std;
int T, n;
int solve() {
  int sum = 0, f = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> f;
    sum += f;
  }
  int div = sum / n;
  if (div * n == sum) {
    cout << 0 << "\n";
  } else if (div * n != sum)
    cout << 1 << "\n";
  return 0;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) solve();
  return 0;
}
