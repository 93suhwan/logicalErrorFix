#include <bits/stdc++.h>
using namespace std;
vector<int> nei[1000003];
bool vis[1000003];
int gr[1003][1003];
int u = 8, r = 4, d = 2, l = 1, cnt = 0;
int ceck(int i, int j, int s, int k) {
  int g;
  if (s == u) g = gr[i - 1][j];
  if (s == r) g = gr[i][j + 1];
  if (s == d) g = gr[i + 1][j];
  if (s == l) g = gr[i][j - 1];
  if ((g & k) == 0)
    return 1;
  else
    return 0;
}
void dfs(int s) {
  vis[s] = 1;
  cnt++;
  for (int i = 0; i < nei[s].size(); i++) {
    int next = nei[s][i];
    if (vis[next] == 0) dfs(next);
  }
}
int main() {
  int n, m, i, j;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> gr[i][j];
    }
  }
  vector<int> v;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      int h = gr[i][j];
      if ((h & u) == 0) {
        if (ceck(i, j, u, d)) {
          int p = m * i + j;
          int q = p - m;
          nei[p].push_back(q);
          nei[q].push_back(p);
        }
      }
      if ((h & r) == 0) {
        if (ceck(i, j, r, l)) {
          int p = m * i + j;
          int q = p + 1;
          nei[p].push_back(q);
          nei[q].push_back(p);
        }
      }
      if ((h & d) == 0) {
        if (ceck(i, j, d, u)) {
          int p = m * i + j;
          int q = p + m;
          nei[p].push_back(q);
          nei[q].push_back(p);
        }
      }
      if ((h & l) == 0) {
        if (ceck(i, j, l, r)) {
          int p = m * i + j;
          int q = p - 1;
          nei[p].push_back(q);
          nei[q].push_back(p);
        }
      }
    }
  }
  for (i = 0; i < n * m; i++) {
    if (vis[i] == 0) {
      dfs(i);
      v.push_back(cnt);
      cnt = 0;
    }
  }
  int w = v.size();
  sort(v.begin(), v.end(), greater<int>());
  for (i = 0; i < w; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
  return 0;
}
