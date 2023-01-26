#include <bits/stdc++.h>
using namespace std;
int n, m, digit[30], pos, ans[30];
int use[30];
bool f;
void dfs(int p, int yu, int co, bool li) {
  if (f) return;
  if (p == 0) {
    f = true;
    return;
  }
  int i, j, k;
  if (!li) {
    for (i = digit[p]; i <= 9; i++) {
      if (i == digit[p]) {
        if (use[i] == 1) {
          ans[p] = i;
          dfs(p - 1, yu - 1, co, li);
          if (f) return;
        } else {
          if (co == 0) continue;
          ans[p] = i;
          use[i] = 1;
          dfs(p - 1, yu - 1, co - 1, li);
          use[i] = 0;
          if (f) return;
        }
      } else {
        if (use[i] == 1) {
          ans[p] = i;
          dfs(p - 1, yu - 1, co, 1);
          if (f) return;
        } else {
          if (co == 0) continue;
          ans[p] = i;
          use[i] = 1;
          dfs(p - 1, yu - 1, co - 1, 1);
          use[i] = 0;
          if (f) return;
        }
      }
    }
  } else {
    if (co == 0) {
      for (i = 0; i <= 9; i++) {
        if (use[i]) {
          ans[p] = i;
          dfs(p - 1, yu - 1, co, 1);
          if (f) return;
          break;
        }
      }
    } else {
      {
        if (use[0]) {
          ans[p] = 0;
          dfs(p - 1, yu - 1, co, 1);
          if (f) return;
        } else if (co > 0) {
          use[0] = 1;
          ans[p] = 0;
          dfs(p - 1, yu - 1, co - 1, 1);
          if (f) return;
          use[0] = 0;
        } else {
          for (i = 0; i <= 9; i++) {
            if (use[i]) {
              use[i] = 1;
              ans[p] = i;
              dfs(p - 1, yu - 1, co, 1);
              if (f) return;
              use[i] = 0;
              break;
            }
          }
        }
      }
    }
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    pos = 0;
    cin >> n >> m;
    int i, j, k;
    int x = n;
    while (x) {
      digit[++pos] = x % 10;
      x /= 10;
    }
    f = false;
    memset(use, 0, sizeof(use));
    dfs(pos, pos, m, 0);
    if (f) {
      for (i = pos; i >= 1; i--) printf("%d", ans[i]);
      printf("\n");
    } else {
      pos++;
      if (m == 1) {
        for (i = 1; i <= pos; i++) printf("1");
        printf("\n");
      } else {
        printf("1");
        for (i = 2; i <= pos; i++) printf("0");
        printf("\n");
      }
    }
  }
  return 0;
}
