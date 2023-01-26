#include <bits/stdc++.h>
using namespace std;
map<int, map<int, int>> ma;
map<int, map<int, map<int, map<int, map<int, int>>>>> ma1;
int a[10];
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    ma[x][y] = ma[y][x] = 1;
  }
  int cnt = 500000;
  while (cnt--) {
    for (int i = 1; i <= 5; i++) {
      a[i] = (rand()) % n + 1;
      for (int j = 1; j < i; j++) {
        if (a[i] == a[j]) {
          i--;
          break;
        }
      }
    }
    sort(a + 1, a + 6);
    if (50 <= n) {
      if (ma1[a[1]][a[2]][a[3]][a[4]][a[5]]) {
        cnt++;
        continue;
      } else
        ma1[a[1]][a[2]][a[3]][a[4]][a[5]] = 1;
    }
    int b = ma[a[1]][a[2]];
    for (int i = 1; i <= 5; i++) {
      for (int j = 1; j < i; j++) {
        if (ma[a[i]][a[j]] != b) {
          b = -1;
          break;
        }
      }
      if (b == -1) break;
    }
    if (b != -1) {
      for (int i = 1; i <= 5; i++) {
        printf("%d ", a[i]);
      }
      return;
    }
  }
  printf("-1");
}
int main() {
  srand(time(0));
  solve();
  return 0;
}
