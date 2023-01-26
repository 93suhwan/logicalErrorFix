#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int p[maxn][10];
int n;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 5; j++) cin >> p[i][j];
  for (int i = 1; i <= 5; i++) {
    int a = 0, b = 0, c = 0;
    for (int j = 1; j <= 5; j++) {
      if (i == j) continue;
      for (int k = 1; k <= n; k++)
        if (p[k][i] == 1 && p[k][j])
          c++;
        else if (p[k][i] && !p[k][j])
          a++;
        else if (!p[k][i] && p[k][j])
          b++;
      if (a + c >= n / 2 && b + c >= n / 2) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}
int main() {
  int __;
  cin >> __;
  while (__--) solve();
}
