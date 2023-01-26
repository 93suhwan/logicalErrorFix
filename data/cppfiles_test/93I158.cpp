#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxN = 3e5 + 5, mod = 1e9 + 7, LOG = 20;
int x[mxN];
void solve() {
  int a, b;
  cin >> a >> b;
  if (x[a - 1] == b)
    cout << a;
  else if (a == b)
    cout << a + 2;
  else
    cout << a + 1;
}
int main() {
  ios ::sync_with_stdio(false), cin.tie(nullptr);
  for (int i = 1; i < mxN; ++i) x[i] = (x[i - 1] ^ i);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
