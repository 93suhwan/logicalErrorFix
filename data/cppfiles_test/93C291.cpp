#include <bits/stdc++.h>
using namespace std;
const int maxN = 3e5 + 5;
int xxor[maxN];
void preSolve(int& testcases) {
  cin >> testcases;
  xxor[0] = 0;
  for (int i = 1; i < maxN; i++) {
    xxor[i] = i ^ xxor[i - 1];
  }
}
void solve() {
  int a, b;
  cin >> a >> b;
  int v = xxor[a - 1];
  int ans = a;
  if (v == b) {
  } else {
    int t = b ^ v;
    if (t == a) {
      ans += 2;
    } else {
      ans += 1;
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int testcases = 1;
  preSolve(testcases);
  for (int caseno = 1; caseno <= testcases; ++caseno) {
    solve();
  }
  return 0;
}
