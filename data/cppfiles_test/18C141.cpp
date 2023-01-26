#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int n, d, a[N + 9], Ans;
vector<int> b;
bool used[N + 9];
void cal(int s) {
  int now = s, m, res = 0;
  b.clear();
  while (!used[now]) {
    b.push_back(a[now]);
    used[now] = 1;
    now = (now + d) % n;
  }
  m = b.size();
  for (int i = 0, sum = 0; i < m; i++)
    if (b[i])
      sum++, res = max(res, sum);
    else
      sum = 0;
  int sum = 0;
  for (int i = 0; i < m; i++)
    if (b[i])
      sum++;
    else
      break;
  for (int i = m - 1; i >= 0; i--)
    if (b[i])
      sum++;
    else
      break;
  res = max(res, sum);
  if (res > m)
    Ans = -1;
  else
    Ans = max(Ans, res);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    Ans = 0;
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n && ~Ans; i++)
      if (!used[i]) cal(i);
    printf("%d\n", Ans);
  }
  return 0;
}
