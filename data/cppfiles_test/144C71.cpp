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
int n, m, k, p[N], w[N];
vector<int> b[N];
int main() {
  int T;
  read(T);
  while (T--) {
    read(n), read(m), read(k);
    int t = n % m;
    for (int i = 0; i < n; i++) p[i] = i;
    int A = n / m, B = (n + m - 1) / m;
    for (int i = 0; i < k; i++) {
      int id = 0, now = 0;
      for (int i = 0; i < t; i++) {
        for (int j = 0; j < B; j++) {
          b[now].push_back(p[id++]);
        }
        now++;
      }
      for (int i = 0; i < m - t; i++) {
        for (int j = 0; j < A; j++) {
          b[now].push_back(p[id++]);
        }
        now++;
      }
      for (int j = 0; j < m; j++) {
        printf("%lu", b[j].size());
        for (int v : b[j]) {
          printf(" %d", v + 1);
        }
        puts("");
      }
      for (int j = 0; j < m; j++) b[j].clear();
      for (int u = 0; u < n; u++) w[u] = p[u];
      for (int u = 0; u < n; u++) p[u] = w[(u + B * t) % n];
    }
    puts("");
  }
  return 0;
}
