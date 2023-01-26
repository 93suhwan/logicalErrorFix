#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0;
  bool f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
const int N = 2e5 + 10;
int c[11], a[11][N], n, m;
vector<int> al[N];
int main() {
  n = read();
  for (int i = (0); i <= (n - 1); i++) {
    c[i] = read();
    for (int j = (0); j <= (c[i] - 1); j++) a[i][j] = read();
  }
  m = read();
  for (int i = (1); i <= (m); i++)
    for (int j = (1); j <= (n); j++) al[i].push_back(read() - 1);
  sort(al + 1, al + m + 1);
  vector<int> cur;
  for (int i = (0); i <= (n - 1); i++) cur.push_back(c[i] - 1);
  if (!binary_search(al + 1, al + m + 1, cur)) {
    for (auto x : cur) printf("%d ", x + 1);
    return 0;
  }
  vector<int> ans;
  long long tans = 0;
  for (int i = (1); i <= (m); i++) {
    long long s = 0;
    for (int j = (0); j <= (n - 1); j++) s += a[j][al[i][j]];
    vector<int> d = al[i];
    for (int j = (0); j <= (n - 1); j++)
      if (d[j]) {
        s -= a[j][d[j]];
        d[j]--;
        s += a[j][d[j]];
        if (!binary_search(al + 1, al + m + 1, d) && s > tans)
          tans = s, ans = d;
        s -= a[j][d[j]];
        d[j]++;
        s += a[j][d[j]];
      }
  }
  for (auto x : ans) printf("%d ", x + 1);
  return 0;
}
