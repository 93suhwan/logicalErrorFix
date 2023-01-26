#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100, M = 1 << 13;
int n, a[N], MIN[M], f[M];
vector<int> p[M];
inline void ckmin(int &a, int b) { a = ((a < b) ? a : b); }
inline void ckmax(int &a, int b) { a = ((a > b) ? a : b); }
inline int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
signed main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read(), p[a[i]].push_back(i);
  memset(MIN, 0x3f, sizeof(MIN));
  MIN[0] = 0;
  for (int i = 1; i <= 5000; i++)
    if (!p[i].empty()) {
      vector<int> b = p[i];
      memset(f, 0x3f, sizeof(f));
      for (int j = 0; j < M; j++)
        if (MIN[j] != 0x3f3f3f3f) {
          int pos = lower_bound(b.begin(), b.end(), MIN[j]) - b.begin();
          if (pos == (int)b.size())
            f[j ^ i] = 0x3f3f3f3f;
          else
            f[j ^ i] = b[pos];
        }
      for (int j = 0; j < M; j++) ckmin(MIN[j], f[j]);
    }
  vector<int> ans;
  for (int i = 0; i < M; i++)
    if (MIN[i] != 0x3f3f3f3f) ans.push_back(i);
  printf("%d\n", (int)ans.size());
  for (int i : ans) printf("%d ", i);
  printf("\n");
}
