#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int head[1000005];
struct edge {
  int to, next;
};
edge e[1000005 << 1];
int cmt = 0;
int T;
void add(int u, int v) {
  e[++cmt].to = v;
  e[cmt].next = head[u];
  head[u] = cmt;
}
template <typename Tp>
inline void read(Tp &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
int buf[42];
template <typename Tp>
inline void write(Tp x) {
  int p = 0;
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x == 0) {
    putchar('0');
    return;
  }
  while (x) {
    buf[++p] = x % 10;
    x /= 10;
  }
  for (int i = p; i; i--) putchar('0' + buf[i]);
}
map<int, int> mp;
long long s, n, k;
int main() {
  cin >> T;
  while (T--) {
    read(s);
    read(n);
    read(k);
    if (s == k) {
      printf("YES\n");
    } else if (s < k) {
      printf("NO\n");
    } else {
      if (s >= n + (n / k) * k)
        printf("NO\n");
      else
        printf("YES\n");
    }
  }
  return 0;
}
