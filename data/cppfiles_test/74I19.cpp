#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7, inv6 = (mod + 1) / 6, W = 2;
int n, a[N], ns[N];
void work(int x, int y, int z) {
  int sum = (x + y + z) / 2, tp = 3;
  ns[1] = sum - x, ns[2] = sum - y, ns[3] = sum - z;
  for (int i = (1); i <= (n); ++i)
    if (i != x && i != y && i != z) ns[++tp] = a[i] - ns[1];
  cout << "YES\n";
  for (int i = (1); i <= (n); ++i) cout << ns[i] << ' ';
  cout << '\n';
}
int z;
short h[N * 10][11], s[N];
int arr[N];
bool vis[N * 11], vs[N];
void dfs(int x, int k, int sum) {
  if (k == z + 1) {
    if (vis[sum]) {
      int tot = 0;
      for (int i = (0); i <= (z - 1); ++i) vs[h[sum][i]] ^= 1;
      for (int i = (0); i <= (z - 1); ++i) vs[s[i]] ^= 1;
      vector<int> S1, S2;
      for (int i = (0); i <= (z - 1); ++i)
        if (vs[h[sum][i]]) S1.push_back(h[sum][i]);
      for (int i = (0); i <= (z - 1); ++i)
        if (vs[s[i]]) S2.push_back(s[i]);
      assert(((int)(S1).size()) == ((int)(S2).size()));
      for (int i = (0); i <= (((int)(S1).size()) - 1); ++i) {
        arr[++tot] = a[S1[i]];
        arr[++tot] = a[S2[i]];
      }
      cout << "YES\n";
      ns[1] = 0;
      for (int i = (2); i <= (tot); ++i) ns[i] = arr[i - 1] - ns[i - 1];
      assert(ns[tot] == arr[tot]);
      for (int i = (1); i <= (n); ++i)
        if (!vs[i]) ++tot, ns[tot] = a[i];
      for (int i = (1); i <= (n); ++i) cout << ns[i] << ' ';
      exit(0);
      return;
    }
    for (int i = (0); i <= (z - 1); ++i) h[sum][i] = s[i];
    vis[sum] = 1;
    return;
  }
  for (int i = (x + 1); i <= (n); ++i) s[k - 1] = i, dfs(i, k + 1, sum + a[i]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = (1); i <= (n); ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = (1); i <= (n - 1); ++i) {
    if (a[i] == a[i + 1]) {
      ns[1] = 0, ns[2] = a[i];
      int tp = 2;
      for (int j = (1); j <= (n); ++j)
        if (j != i && j != i + 1) ns[++tp] = a[j];
      cout << "YES\n";
      for (int j = (1); j <= (n); ++j) cout << ns[j] << ' ';
      cout << '\n';
      return 0;
    }
  }
  sort(a + 1, a + n + 1, [&](int x, int y) { return (x & 1) < (y & 1); });
  for (int i = (1); i <= (n); ++i)
    for (int j = (i + 1); j <= (n); ++j)
      for (int k = (j + 1); k <= (n); ++k)
        if (!((a[i] + a[j] + a[k]) & 1)) return work(i, j, k), 0;
  z = min(10, n / 2);
  dfs(0, 1, 0);
  cout << "NO\n";
  return 0;
}
