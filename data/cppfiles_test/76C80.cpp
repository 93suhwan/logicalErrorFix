#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T& x) {
  char c;
  int sign = 1;
  x = 0;
  do {
    c = getchar();
    if (c == '-') c = getchar();
  } while (!isdigit(c));
  do {
    x = x * 10 + c - '0';
    c = getchar();
  } while (isdigit(c));
  x *= sign;
}
const int N = 2e5 + 50;
int n, m, a[6];
set<int> s[N];
int main() {
  read(n);
  read(m);
  for (register int i = 1; i <= m; ++i) {
    int u, v;
    read(u);
    read(v);
    s[u].insert(v);
    s[v].insert(u);
  }
  for (register int qqqq = 1; qqqq <= 1000000; ++qqqq) {
    for (register int i = 1; i <= 5; ++i) a[i] = rand() % n + 1;
    bool flag = 1;
    int k = s[a[1]].count(a[2]);
    for (register int i = 1; i <= 5; ++i)
      for (register int j = i + 1; j <= 5; ++j)
        if (a[i] == a[j] || k != s[a[i]].count(a[j])) {
          flag = 0;
          break;
        }
    if (flag) {
      sort(a + 1, a + 1 + 5);
      for (register int i = 1; i <= 5; ++i) printf("%d ", a[i]);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
