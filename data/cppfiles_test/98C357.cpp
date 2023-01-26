#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m, t;
char str[100];
int prea[100], preb[100];
void solve() {
  cin >> n;
  cin >> str + 1;
  memset(prea, 0, sizeof prea);
  memset(preb, 0, sizeof preb);
  for (int i = 1; i <= n; i++) {
    prea[i] = prea[i - 1] + (str[i] == 'a');
    preb[i] = preb[i - 1] + (str[i] == 'b');
  }
  for (int l = 1; l <= n; l++)
    for (int r = l + 1; r <= n; r++)
      if (prea[r] - prea[l - 1] == preb[r] - preb[l - 1]) {
        cout << l << " " << r << endl;
        return;
      }
  cout << -1 << " " << -1 << endl;
}
int main() {
  cin >> t;
  while (t--) {
    solve();
  }
}
