#include <bits/stdc++.h>
using namespace std;
const int maxsize = 1e6 + 10;
string map[maxsize];
int sum[maxsize];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> map[i];
  }
  for (int j = 0; j < m; j++) {
    for (int i = 1; i <= n; i++) {
      if (i - 1 > 0 && j - 1 >= 0 && map[i][j] != 'X') {
        if (map[i - 1][j] == 'X' && map[i][j - 1] == 'X') {
          sum[j] = 1;
        }
      }
    }
  }
  for (int i = 1; i < m; i++) {
    sum[i] += sum[i - 1];
  }
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    if (sum[b - 1] - sum[a - 1] > 0)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
