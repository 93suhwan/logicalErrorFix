#include <bits/stdc++.h>
using namespace std;
pair<int, int> ch[200005];
int parent[20][200005], depth[200005];
int isDuped[200005];
string second, s1 = "";
int n, k, c = 0;
void nextChar(int u) {
  if (ch[u].first != -1) {
    nextChar(ch[u].first);
  }
  s1 += second[u];
  if (ch[u].second != -1) {
    nextChar(ch[u].second);
  }
}
void dfs(int u, bool canDupe) {
  if (ch[u].first != -1) {
    depth[ch[u].first] = depth[u] + 1;
    dfs(ch[u].first, canDupe);
  }
  if (isDuped[u] == -1 && canDupe) {
    int target = 0;
    if (s1[c] < s1[c + 1]) target = 1;
    if (s1[c] == s1[c + 1]) target = -1;
    int v = u;
    for (int i = 19; i >= 0; i--) {
      if (isDuped[parent[i][v]] == -1) {
        v = parent[i][v];
      }
    }
    if (depth[u] - depth[v] + 1 <= k && target == 1 &&
        isDuped[parent[0][v]] != 0) {
      v = u;
      while (isDuped[v] == -1) {
        isDuped[v] = 1;
        k--;
        v = parent[0][v];
      }
    }
    if (target == 0) {
      canDupe = 0;
    }
  }
  c++;
  if (ch[u].second != -1) {
    depth[ch[u].second] = depth[u] + 1;
    dfs(ch[u].second, canDupe);
  }
}
void print(int u) {
  if (ch[u].first != -1) {
    print(ch[u].first);
  }
  cout << second[u];
  if (isDuped[u] == 1) cout << second[u];
  if (ch[u].second != -1) {
    print(ch[u].second);
  }
}
int main() {
  cin >> n >> k >> second;
  for (int i = 0; i < n; i++) {
    isDuped[i] = -1;
    int a, b;
    cin >> a >> b;
    if (a != 0) parent[0][a - 1] = i;
    if (b != 0) parent[0][b - 1] = i;
    ch[i] = {a - 1, b - 1};
  }
  for (int i = 1; i < 20; i++) {
    for (int j = 0; j < n; j++) {
      parent[i][j] = parent[i - 1][parent[i - 1][j]];
    }
  }
  nextChar(0);
  s1 += 'A';
  dfs(0, 1);
  print(0);
}
