#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
void solve();
int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int max_horizontal = (m / 2) * n;
  if (k % 2 == max_horizontal % 2)
    printf("YES\n");
  else
    printf("NO\n");
  return;
}
