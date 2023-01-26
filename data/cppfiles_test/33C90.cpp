#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int ret = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  for (; ch >= '0' && ch <= '9'; ch = getchar()) ret = ret * 10 + ch - '0';
  return ret * f;
}
int n, a[200020], f[513];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(f, 0x3f, sizeof f);
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 512; j++) {
      if (f[j] < a[i]) f[j ^ a[i]] = min(f[j ^ a[i]], a[i]);
    }
  }
  vector<int> ans;
  for (int i = 0; i <= 512; i++) {
    if (f[i] != 0x3f3f3f3f) ans.push_back(i);
  }
  cout << ans.size() << endl;
  for (int i : ans) cout << i << " ";
  return 0;
}
