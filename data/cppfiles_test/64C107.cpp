#include <bits/stdc++.h>
using namespace std;
const int w = 5e5 + 5;
long long mod = 998244353;
int f[3][w];
int get(int x, int pos) {
  if (x != f[pos][x]) f[pos][x] = get(f[pos][x], pos);
  return f[pos][x];
}
int main() {
  int i, j;
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  for (j = 1; j <= 2; j++)
    for (i = 1; i <= n; i++) f[j][i] = i;
  for (i = 1; i <= m1; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    int fx = get(x, 1), fy = get(y, 1);
    if (fx != fy) f[1][fx] = fy;
  }
  for (i = 1; i <= m2; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    int fx = get(x, 2), fy = get(y, 2);
    if (fx != fy) f[2][fx] = fy;
  }
  int ans = 0;
  queue<pair<int, int> > qu;
  queue<int> qu1, qu2;
  int fx1 = get(1, 1), fx2 = get(1, 2);
  for (j = 2; j <= n; j++) {
    int fy1 = get(j, 1), fy2 = get(j, 2);
    if (fx1 == fy1 && fx2 == fy2) continue;
    if (fx1 != fy1 && fx2 != fy2) {
      ans++;
      qu.push({1, j});
      f[1][fy1] = fx1;
      f[2][fy2] = fx2;
    }
  }
  for (j = 2; j <= n; j++) {
    int fy1 = get(j, 1), fy2 = get(j, 2);
    if (fx1 == fy1 && fx2 == fy2) continue;
    if (fx1 != fy1) qu1.push(j), f[1][fy1] = fx1;
    if (fx2 != fy2) qu2.push(j), f[2][fy2] = fx2;
  }
  cout << ans + min(qu1.size(), qu2.size()) << endl;
  while (!qu.empty()) {
    printf("%d %d\n", qu.front().first, qu.front().second);
    qu.pop();
  }
  while (!qu1.empty() && !qu2.empty()) {
    printf("%d %d\n", qu1.front(), qu2.front());
    qu1.pop(), qu2.pop();
  }
  return 0;
}
