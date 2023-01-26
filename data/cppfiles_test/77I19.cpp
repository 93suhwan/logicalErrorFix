#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node {
  int x, y;
  node(int a, int b) {
    x = a;
    y = b;
  }
};
int n, m;
int a[1010][1010];
int book[1010][1010];
int ans[1010000];
int sum;
void bfs(int bh, int x, int y) {
  queue<node> dl;
  dl.push(node(x, y));
  book[x][y] = bh;
  sum++;
  while (!dl.empty()) {
    int x = dl.front().x;
    int y = dl.front().y;
    if ((a[x][y] & (1 << 3)) == 0) {
      if (x - 1 >= 1 && book[x - 1][y] == 0) {
        cout << x << y << 1 << endl;
        dl.push(node(x - 1, y));
        book[x - 1][y] = bh;
      }
    }
    if ((a[x][y] & 1 << 2) == 0) {
      if (y + 1 <= m && book[x][y + 1] == 0) {
        dl.push(node(x, y + 1));
        book[x][y + 1] = bh;
      }
    }
    if ((a[x][y] & 1 << 1) == 0) {
      if (x + 1 <= n && book[x + 1][y] == 0) {
        dl.push(node(x + 1, y));
        book[x + 1][y] = bh;
      }
    }
    if ((a[x][y] & 1) == 0) {
      if (y - 1 >= 1 && book[x][y - 1] == 0) {
        cout << x << y << 2 << endl;
        dl.push(node(x, y - 1));
        book[x][y - 1] = bh;
      }
    }
    dl.pop();
  }
}
int main() {
  vector<int> js;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  int bh = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (book[i][j] == 0) {
        bfs(++bh, i, j);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans[book[i][j]]++;
    }
  }
  sort(ans + 1, ans + 1 + bh);
  for (int i = bh; i >= 1; --i) printf("%d ", ans[i]);
  return 0;
}
