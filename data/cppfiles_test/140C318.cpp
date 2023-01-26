#include <bits/stdc++.h>
using namespace std;
const int dx[9] = {-1, 0, 1, 0, -1, -1, 1, 1, 0};
const int dy[9] = {0, 1, 0, -1, -1, 1, -1, 1, 0};
long long n;
void solve() {
  n += 0.5;
  int a = sqrt(n);
  int b = cbrt(n);
  int c = sqrt(cbrt(n));
  cout << a + b - c << "\n";
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    solve();
  }
  return 0;
}
