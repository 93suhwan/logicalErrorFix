#include <bits/stdc++.h>
using namespace std;
const int dx[9] = {-1, 0, 1, 0, -1, -1, 1, 1, 0};
const int dy[9] = {0, 1, 0, -1, -1, 1, -1, 1, 0};
long long n;
void solve() { cout << sqrt(n) + cbrt(n) - sqrt(cbrt(n)) << "\n"; }
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
