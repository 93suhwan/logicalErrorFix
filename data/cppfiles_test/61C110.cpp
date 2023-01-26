#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int Count = 10;
const int N = 1e3 + 5;
const int inf = 0x3f3f3f3f;
const int maxn = 4e3 + 5;
const int charSum = 26;
char str[N];
char ans[2][N];
int n;
int dfs(int id, int k) {
  if (id == n) return 0;
  if (ans[k][id] == '?') {
    if (ans[k][id - 1] == 'R')
      ans[k][id] = 'B';
    else
      ans[k][id] = 'R';
  }
  int res = 0;
  if (ans[k][id - 1] == ans[k][id]) res++;
  res += dfs(id + 1, k);
  return res;
}
int main() {
  int Tcase;
  cin >> Tcase;
  while (Tcase--) {
    scanf("%d", &n);
    scanf("%s", str);
    for (int i = (0); i <= (n); ++i) ans[0][i] = ans[1][i] = str[i];
    if (str[0] == '?') ans[0][0] = 'R', ans[1][0] = 'B';
    if (dfs(1, 0) > dfs(1, 1))
      printf("%s\n", ans[1]);
    else
      printf("%s\n", ans[0]);
  }
  return 0;
}
