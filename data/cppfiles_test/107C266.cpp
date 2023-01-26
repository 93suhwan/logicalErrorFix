#include <bits/stdc++.h>
const int xsz = 60 + 1;
const int MOD = 1e9 + 7;
const long long oo = 1e18 + 5;
using namespace std;
void Solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (abs(a - b) > 1 or a + b > n - 2) {
    cout << "-1\n";
    return;
  }
  int t = 1, rt = n;
  if (a < b) swap(t, rt);
  for (int i = 1; i <= n; ++i) {
    if (i <= a + b + 1) {
      cout << t << " ";
      if (t < rt)
        t++;
      else
        t--;
      swap(t, rt);
    } else {
      cout << rt << " ";
      if (rt < t)
        rt++;
      else
        rt--;
    }
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    Solve();
  }
  return 0;
}
