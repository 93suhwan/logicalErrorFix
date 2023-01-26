#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 1;
int n, m, p[maxn];
string s[maxn];
bool cmp(int x, int y) {
  for (int i = 0; i < m; i++) {
    if (s[x][i] == s[y][i]) continue;
    if (i % 2 == 0)
      return s[x][i] < s[y][i];
    else
      return s[x][i] > s[y][i];
  }
  return false;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    p[i] = i;
  }
  sort(p, p + n, cmp);
  for (int i = 0; i < n; i++) cout << p[i] + 1 << " ";
  cout << "\n";
  return 0;
}
