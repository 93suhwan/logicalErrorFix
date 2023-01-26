#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  while (b) {
    long long int re = a % b;
    a = b;
    b = re;
  }
  return a;
}
vector<int> a[1000 + 10], b[1000 + 10];
vector<int> c1(1000 + 10, 0), c2(1000 + 10, 0);
void dfs(int i, int k, int p) {
  if (p)
    c1[i] = k;
  else
    c2[i] = k;
  if (p) {
    for (int j : a[i]) {
      if (c1[j] == 0) dfs(j, k, p);
    }
  } else {
    for (int j : b[i]) {
      if (c2[j] == 0) dfs(j, k, p);
    }
  }
}
int main() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  for (int i = 0; i < m1; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  for (int i = 0; i < m2; i++) {
    int u, v;
    cin >> u >> v;
    b[u].push_back(v);
    b[v].push_back(u);
  }
  int k = 1;
  for (int i = 1; i < n + 1; i++) {
    if (c1[i] == 0) {
      dfs(i, k, 1);
      k++;
    }
  }
  k = 1;
  vector<pair<long long int, long long int> > ans;
  for (int i = 1; i < n + 1; i++) {
    if (c2[i] == 0) {
      dfs(i, k, 0);
      k++;
    }
  }
  map<int, int> mp1, mp2;
  for (int i = 0; i < n + 1; i++) {
    mp1[i] = i;
    mp2[i] = i;
  }
  for (int i = 1; i < n + 1; i++) {
    if (mp1[c1[i]] == -1) continue;
    for (int j = 1; j < n + 1; j++) {
      int cai = mp1[c1[i]], caj = mp1[c1[j]], cbi = mp2[c2[i]],
          cbj = mp2[c2[j]];
      if (cai != caj && cbi != cbj) {
        ans.push_back({i, j});
        mp1[c1[j]] = mp1[c1[i]] = -1;
        mp2[c2[j]] = mp2[c2[i]] = -1;
      }
    }
  }
  cout << ans.size() << endl;
  for (auto it : ans) cout << it.first << " " << it.second << endl;
}
