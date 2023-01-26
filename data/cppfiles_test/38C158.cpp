#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, q, flag[N];
char str[N];
vector<char> V[N];
vector<int> used[N];
bool check(int i, int j) {
  if (i == 0 || j == 0) return 0;
  if (V[i - 1][j] == 'X' && V[i][j - 1] == 'X') return 1;
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    for (int j = 0; j < m; j++) {
      V[i].push_back(str[j]);
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      used[i].push_back(check(i, j));
    }
  for (int i = 0; i < n; i++) {
    V[i].clear();
    used[i].clear();
  }
  for (int j = 0; j < m; j++) {
    flag[j] = 0;
    for (int i = 0; i < n; i++) {
      if (used[i][j] == 1) flag[j] = 1;
    }
  }
  for (int j = 1; j < m; j++) {
    flag[j] += flag[j - 1];
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    if (a == b) {
      printf("YES\n");
      continue;
    } else {
      if (flag[b] - flag[a] > 0) {
        printf("NO\n");
      } else {
        printf("YES\n");
      }
    }
  }
  return 0;
}
