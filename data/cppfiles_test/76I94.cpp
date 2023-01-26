#include <bits/stdc++.h>
using namespace std;
map<int, map<int, int>> ma;
int a[10];
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    ma[x][y] = ma[y][x] = 1;
  }
  int cnt = 700000;
  while (cnt--) {
    for (int i = 1; i <= 5; i++) {
      a[i] = (rand() + 1000000007) % n + 1;
      for (int j = 1; j < i; j++) {
        if (a[i] == a[j]) {
          i--;
          break;
        }
      }
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
      sort(a + 1, a + 6);
      for (int i = 1; i <= 5; i++) {
        printf("%d ", a[i]);
      }
      return;
    }
  }
  for (long long i = 1; i <= n - 4; i++) {
    for (long long j = 1; j <= 5; j++) {
      a[j] = i + j - 1;
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
      sort(a + 1, a + 6);
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
