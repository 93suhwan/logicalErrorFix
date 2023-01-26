#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 20;
inline int read() {
  int ans = 0;
  char last = ' ', ch = getchar();
  while (ch<'0' | ch> '9') last = ch, ch = getchar();
  while (ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
  if (last == '-') ans = -ans;
  return ans;
}
int n, k;
vector<int> save[maxn];
int a[maxn], color[maxn], cnt[maxn], ls[maxn];
void solve() {
  n = read(), k = read();
  for (int i = 0; i <= n; i++) save[i].clear(), color[i] = 0;
  for (int i = 0; i <= n - 1; i++) a[i] = read(), save[a[i]].push_back(i);
  int kd = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= min(k, (int)(save[i].size())) - 1; j++) {
      color[save[i][j]] = kd + 1;
      ls[kd + 1] = save[i][j];
      kd++;
      kd %= k;
    }
  }
  for (int i = 1; i <= kd; i++) color[ls[i]] = 0;
  for (int i = 0; i <= n - 1; i++) cout << color[i] << " ";
  cout << "\n";
}
int main() {
  int _t;
  _t = read();
  while (_t--) solve();
  return 0;
}
