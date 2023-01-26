#include <bits/stdc++.h>
using namespace std;
int solve() {
  int n, s;
  cin >> n >> s;
  int z = (n + 1) / 2;
  int x = s / z;
  return x;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) cout << solve() << '\n';
  return 0;
}
