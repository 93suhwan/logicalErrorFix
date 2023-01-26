#include <bits/stdc++.h>
using namespace std;
int ar[505];
char ch[505], ch1[505], tem[505 + 505];
int n, m, ii, k;
short int dp[505][505][505], dp1[505][2];
bool vis[505][505][505], vis1[505][2];
int Prefix_func(int id, int add) {
  if (vis1[id][add]) return dp1[id][add];
  vis1[id][add] = 1;
  int sz = m + id + 2;
  tem[sz] = '\0';
  for (int i = 0; i < m; i++) tem[i] = ch1[i];
  tem[m] = '#';
  for (int i = m + 1, j = 0; j < id; j++, i++) tem[i] = ch1[j];
  tem[sz - 1] = add + '0';
  vector<int> pi(sz);
  for (int i = 1; i < sz; i++) {
    int j = pi[i - 1];
    while (j > 0 && tem[i] != tem[j]) j = pi[j - 1];
    if (tem[j] == tem[i]) j++;
    pi[i] = j;
  }
  return dp1[id][add] = pi[sz - 1];
}
int func(int id1, int id2, int have) {
  if (id1 == n) {
    if (have == 0) return 0;
    return 505;
  }
  if (have < 0) return 505;
  if (vis[id1][id2][have]) return dp[id1][id2][have];
  vis[id1][id2][have] = 1;
  int re = 505;
  if (ch[id1] == '0') {
    int got = 0;
    if (id2 == m - 1 && ch1[id2] == ch[id1]) got++;
    int nxt = Prefix_func(id2, 0);
    re = min(re, func(id1 + 1, nxt, have - got));
  } else {
    int got = 0;
    if (id2 == m - 1 && ch1[id2] == '0') got++;
    int nxt = Prefix_func(id2, 0);
    re = min(re, 1 + func(id1 + 1, nxt, have - got));
  }
  if (ch[id1] == '1') {
    int got = 0;
    if (id2 == m - 1 && ch1[id2] == ch[id1]) got++;
    int nxt = Prefix_func(id2, 1);
    re = min(re, func(id1 + 1, nxt, have - got));
  } else {
    int got = 0;
    if (id2 == m - 1 && ch1[id2] == '1') got++;
    int nxt = Prefix_func(id2, 1);
    re = min(re, 1 + func(id1 + 1, nxt, have - got));
  }
  return dp[id1][id2][have] = re;
}
void solve() {
  scanf("%d%d%s%s", &n, &m, ch, ch1);
  for (int i = 0; i <= n - m + 1; i++) {
    int re = func(0, 0, i);
    if (re > n) {
      printf("-1");
    } else
      printf("%d", re);
    if (i == n - m + 1)
      printf("\n");
    else
      printf(" ");
  }
}
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
