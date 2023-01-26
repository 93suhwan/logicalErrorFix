#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6;
const int oo = 1e9;
const int smax = 4e5;
int n, m, num, d[21], c[21], pow2[21], f[1048580][2], sum[1048580];
bool kt;
string s;
pair<int, int> goes[21][400001], temp, tam;
vector<int> v[smax];
pair<int, int> go(int i, int flag, int vaule) {
  if (flag) return {0, 1};
  return goes[i][vaule];
}
void maximize(int *x, int y) {
  if (*x < y) *x = y;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(f, -1, sizeof(f));
  pow2[0] = 1;
  for (int i = 1; i <= 20; i++) pow2[i] = pow2[i - 1] * 2;
  cin >> n;
  for (int j = 1; j < pow2[n]; j++) f[j][0] = f[j][1] = -oo;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= smax; j++) v[j].clear();
    cin >> s;
    m = s.size();
    c[i] = d[i] = 0;
    kt = true;
    for (int j = 0; j < m; j++) {
      if (s[j] == '(')
        d[i]++;
      else
        d[i]--;
      if (d[i] < c[i]) c[i] = d[i];
      if (d[i] <= 0) v[-d[i]].push_back(j);
    }
    for (int j = 0; j <= smax; j++) {
      if (v[j].empty())
        num = 0;
      else {
        if (!v[j + 1].empty())
          num =
              upper_bound(v[j].begin(), v[j].end(), v[j + 1][0]) - v[j].begin();
        else
          num = v[j].size();
      }
      if (c[i] + j < 0)
        goes[i][j] = {num, 1};
      else
        goes[i][j] = {num, 0};
    }
    for (int j = 1; j < pow2[n]; j++)
      if ((j >> (i - 1)) & 1) sum[j] += d[i];
  }
  f[0][0] = sum[0] = 0;
  f[0][1] = -oo;
  for (int i = 0; i < pow2[n]; i++) {
    for (int j = 1; j <= n; j++)
      if (!((i >> (j - 1)) & 1)) {
        if (f[i][1] != -oo) maximize(&f[i ^ pow2[j - 1]][1], f[i][1]);
        if (f[i][0] == -oo) continue;
        temp = go(j, 0, sum[i]);
        maximize(&f[i ^ pow2[j - 1]][temp.second], f[i][0] + temp.first);
      }
  }
  cout << max(f[pow2[n] - 1][0], f[pow2[n] - 1][1]);
  return 0;
}
