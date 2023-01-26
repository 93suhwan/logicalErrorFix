#include <bits/stdc++.h>
using namespace std;
const int mxn = 4000006;
int ans[mxn], timer, to[mxn], in[mxn];
bool in_cycle;
void solve(int v) {
  if (ans[v] != -2) {
    if (ans[v] == -1) {
      ans[v] = timer - in[v];
      in_cycle = 1;
    }
    return;
  }
  in[v] = timer++;
  ans[v] = -1;
  solve(to[v]);
  if (ans[v] != -1) {
    in_cycle = 0;
  } else {
    ans[v] = ans[to[v]] + !in_cycle;
  }
}
void PlayGround() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n * m; ++i) {
    ans[i] = -2;
    timer = 0;
  }
  char tab[n][m];
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j, ++cur) {
      cin >> tab[i][j];
      if (tab[i][j] == 'U') {
        if (i == 0) {
          to[cur] = cur;
        } else {
          to[cur] = (i - 1) * m + j;
        }
      } else if (tab[i][j] == 'D') {
        if (i == n - 1) {
          to[cur] = cur;
        } else {
          to[cur] = (i + 1) * m + j;
        }
      } else if (tab[i][j] == 'L') {
        if (j == 0) {
          to[cur] = cur;
        } else {
          to[cur] = i * m + j - 1;
        }
      } else {
        if (j == m - 1) {
          to[cur] = cur;
        } else {
          to[cur] = i * m + j + 1;
        }
      }
    }
  }
  cur = 0;
  int so_far = 0;
  int x, y;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j, ++cur) {
      solve(cur);
      if (ans[cur] > so_far) {
        so_far = ans[cur];
        x = i + 1, y = j + 1;
      }
    }
  }
  cout << x << ' ' << y << ' ' << so_far << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int Test_Case;
  cin >> Test_Case;
  while (Test_Case--) {
    PlayGround();
  }
  return 0;
}
