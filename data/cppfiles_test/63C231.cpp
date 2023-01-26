#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const long long INF = -9999999999999;
const int maxn = 1000006;
const int maxm = 1000006;
const int ox3f = 1061109567;
const int fox3f = -2139062144;
const long long ox3fll = 4557430888798830399;
int n, m, t, T;
int qpow(int a, int n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 1)
    return qpow(a, n - 1) * a;
  else {
    int temp = qpow(a, n / 2);
    return temp * temp;
  }
}
int gcd(int x, int y) {
  if (y)
    return gcd(y, x % y);
  else
    return x;
}
struct Node {
  int first, second;
};
int f[2][100005];
int cnt[100005];
int find(int x, int i) { return f[i][x] == x ? x : f[i][x] = find(f[i][x], i); }
void merge(int x, int y, int i) {
  int u = find(x, i);
  int v = find(y, i);
  if (u == v) return;
  cnt[i]--;
  if (u == 1)
    f[i][v] = 1;
  else if (v == 1)
    f[i][u] = 1;
  else
    f[i][u] = v;
}
queue<int> l, r;
vector<Node> ans;
int main() {
  int m1, m2;
  cin >> n >> m1 >> m2;
  for (int i = 1; i <= n; i++) {
    l.push(i), r.push(i);
    f[0][i] = i, f[1][i] = i;
  }
  for (int i = 1; i <= m1; i++) {
    int u, v;
    cin >> u >> v;
    merge(u, v, 0);
  }
  for (int i = 1; i <= m2; i++) {
    int u, v;
    cin >> u >> v;
    merge(u, v, 1);
  }
  while (ans.size() + max(m1, m2) < n - 1) {
    int u = 0, v = 0;
    while (!l.empty()) {
      u = l.front();
      l.pop();
      if (find(u, 0) != 1) break;
    }
    while (!r.empty()) {
      v = r.front();
      r.pop();
      if (find(v, 1) != 1) break;
    }
    int ff1 = find(u, 0), ff2 = find(v, 1);
    int ff3 = find(u, 1), ff4 = find(v, 0);
    if (u == v) {
      f[0][ff1] = 1;
      f[1][ff2] = 1;
      ans.push_back({u, 1});
      continue;
    }
    if (ff1 == ff4) {
      f[0][ff1] = 1;
      f[1][ff2] = 1;
      ans.push_back({v, 1});
      continue;
    }
    if (ff2 == ff3) {
      f[0][ff1] = 1;
      f[1][ff3] = 1;
      ans.push_back({u, 1});
      continue;
    }
    f[0][ff1] = ff4;
    f[1][ff2] = ff3;
    ans.push_back({u, v});
    l.push(u), r.push(v);
  }
  cout << ans.size() << endl;
  for (auto& an : ans) {
    cout << an.first << " " << an.second << endl;
  }
}
