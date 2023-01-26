#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  int ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
void print(vector<int> x) {
  for (int i = 0; i < (int)x.size(); i++)
    printf("%d%c", x[i], " \n"[i == (int)x.size() - 1]);
}
char s[2005][2005];
int ans[2005][2005], n;
void fix(int x, int y, int col) {
  if ((x + y) & 1) {
    int go = min(x - 1, y - 1);
    x -= go, y -= go, col ^= (go & 1);
    if (x == 1)
      y--;
    else
      x--;
  }
  int go = min(x - 1, n - y);
  x -= go, y += go, col ^= (go & 1);
  go = min(x - 1, y - 1);
  if (go) x -= go, y -= go;
  assert(x == 1);
  if (ans[x][y] != -1 && ans[x][y] != col) cout << "NONE\n", exit(0);
  ans[x][y] = col;
}
int getcol(int x, int y) {
  int col = 0;
  if ((x + y) & 1) {
    int go = min(x - 1, y - 1);
    x -= go, y -= go, col ^= (go & 1);
    if (x == 1)
      y--;
    else
      x--;
  }
  int go = min(x - 1, n - y);
  x -= go, y += go, col ^= (go & 1);
  go = min(x - 1, y - 1);
  if (go) x -= go, y -= go;
  return col ^ ans[x][y];
}
signed main() {
  memset(ans, -1, sizeof(ans));
  cin >> n;
  if (n & 1) cout << "NONE\n", exit(0);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (s[i][j] == '.') continue;
      fix(i, j, s[i][j] == 'S');
    }
  for (int i = 1; i <= n; i += 2)
    if (ans[1][i] == -1) cout << "MULTIPLE\n", exit(0);
  cout << "UNIQUE\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) printf("%c", "GS"[getcol(i, j)]);
    cout << "\n";
  }
  return 0;
}
