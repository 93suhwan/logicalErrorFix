#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const int N = 1e5 + 10;
int n, cnt[6][N];
string s[N];
void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < (int)s[i].size(); j++) cnt[s[i][j] - 'a'][i]++;
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    int mx = 0;
    int hav = 0;
    for (int j = 0; j < n; j++)
      if (cnt[i][j] > (int)s[j].size() / 2)
        mx++, hav += cnt[i][j] - ((int)s[j].size() - cnt[i][j]);
    vector<pair<int, int>> dif;
    for (int j = 0; j < n; j++) {
      if (cnt[i][j] <= (int)s[j].size() / 2) {
        dif.push_back({(int)s[j].size() - cnt[i][j], cnt[i][j]});
      }
    }
    sort(dif.begin(), dif.end());
    for (int i = 0; i < (int)dif.size(); i++) {
      hav -= dif[i].first;
      hav += dif[i].second;
      if (hav <= 0) {
        hav += dif[i].first;
        hav -= dif[i].second;
        continue;
      }
      mx++;
    }
    ans = max(ans, mx);
  }
  printf("%d\n", ans);
  for (int i = 0; i < 5; i++) memset(cnt[i], 0, sizeof(int) * (n + 1));
}
int main() {
  int tc;
  for (scanf("%d", &tc); tc--;) solve();
  return 0;
}
