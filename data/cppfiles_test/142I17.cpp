#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
bool st[N];
int n, m;
vector<int> p[N];
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
bool check(int k) {
  int flag = 0;
  for (int i = 0; i < m; ++i) {
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      if (p[i][j] >= k) {
        st[j] = true;
        if (cnt++) flag = 1;
      }
    }
  }
  int f = 1;
  for (int i = 0; i < n; i++)
    if (!st[i]) {
      f = 0;
      break;
    }
  return f && flag;
}
int main() {
  int t = read();
  while (t--) {
    m = read(), n = read();
    for (int i = 0; i < m; i++) {
      p[i].clear();
      for (int j = 0; j < n; j++) {
        int x = read();
        p[i].push_back(x);
      }
    }
    memset(st, 0, sizeof st);
    int l = 1, r = 1e9;
    while (l < r) {
      int mid = l + r + 1 >> 1;
      if (check(mid))
        l = mid;
      else
        r = mid - 1;
    }
    cout << l << endl;
  }
  return 0;
}
