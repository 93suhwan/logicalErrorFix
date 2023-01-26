#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool inline chkMin(T &x, T y) {
  return (y < x) ? x = y, 1 : 0;
}
template <typename T>
bool inline chkMax(T &x, T y) {
  return (y > x) ? x = y, 1 : 0;
}
template <typename T>
void inline read(T &x) {
  x = 0;
  int f = 1;
  char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s <= '9' && s >= '0') x = x * 10 + s - '0', s = getchar();
  x *= f;
}
const int N = 2e5 + 5;
int n, m, k;
vector<int> b[N];
int main() {
  int T;
  read(T);
  while (T--) {
    read(n), read(m), read(k);
    int t = n % m;
    int o = 0;
    for (int i = 0; i < k; i++) {
      for (int u = 0; u < n; u++) {
        int q = ((u - o) % m + m) % m;
        b[q].push_back(u);
      }
      for (int j = 0; j < m; j++) {
        printf("%lu", b[j].size());
        for (int v : b[j]) printf(" %d", v + 1);
        puts("");
      }
      for (int j = 0; j < m; j++) b[j].clear();
      o += t;
    }
    puts("");
  }
  return 0;
}
