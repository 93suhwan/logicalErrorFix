#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;
const int MX = 2e5 + 5;
vector<int> vorder;
int dup[MX], lc[MX], rc[MX], good[MX], seek[MX];
string labels, corder;
void ino(int curr) {
  if (curr == -1) return;
  ino(lc[curr]);
  vorder.push_back(curr);
  corder += labels[curr];
  ino(rc[curr]);
}
void dfs1(int curr) {
  if (curr == -1) return;
  seek[curr] = INF;
  dfs1(lc[curr]);
  dfs1(rc[curr]);
  if (lc[curr] != -1) seek[curr] = 1 + seek[lc[curr]];
  if (good[curr]) seek[curr] = 1;
}
int dfs2(int curr, int k) {
  if (curr == -1) return k;
  if (seek[curr] <= k) {
    k--;
    dup[curr] = 1;
    k = dfs2(lc[curr], k);
    return dfs2(rc[curr], k);
  }
  return k;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  cin >> labels;
  for (int i = 0; i < n; i++) {
    cin >> lc[i] >> rc[i];
    lc[i]--;
    rc[i]--;
  }
  ino(0);
  corder += '@';
  char last;
  for (int i = n - 1; i >= 0; i--) {
    if (corder[i] != corder[i + 1]) last = corder[i + 1];
    good[vorder[i]] = corder[i] < last;
  }
  memset(dup, 0, sizeof dup);
  dfs1(0);
  dfs2(0, k);
  for (int v : vorder) {
    if (dup[v])
      cout << labels[v] << labels[v];
    else
      cout << labels[v];
  }
  cout << '\n';
}
