#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int s[N];
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char> > g(n + 2, vector<char>(m + 2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> g[i][j];
    }
  }
  for (int j = 1; j <= m; j++) {
    bool flag = false;
    for (int i = 1; i <= n; i++)
      if (g[i][j] == 'X' && g[i + 1][j - 1] == 'X') {
        flag = true;
        break;
      }
    s[j] = flag;
    s[j] += s[j - 1];
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (s[r] - s[l] > 0)
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
