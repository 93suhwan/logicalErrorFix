#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[1000000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
int read() {
  int pos = 1, num = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') pos = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    num = num * 10 + (int)(ch - '0');
    ch = getchar();
  }
  return pos * num;
}
void write(int x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
void writesp(int x) {
  write(x);
  putchar(' ');
}
void writeln(int x) {
  write(x);
  putchar('\n');
}
const int N = 3e5 + 10;
int n, a[N], b[N], dis[N], Dis, pre[N];
queue<int> q;
void print(int x) {
  if (x == n) return;
  print(pre[x]);
  writesp(x);
}
signed main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) b[i] = read();
  Dis = n;
  q.push(n);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u <= 0) {
      writeln(dis[u]);
      print(u);
      return 0;
    }
    int v = u + b[u];
    for (int i = min(v - 1, Dis - 1); i >= v - a[v]; i--) {
      dis[i] = dis[u] + 1;
      pre[i] = u;
      q.push(i);
    }
    Dis = min(Dis, v - a[v]);
  }
  puts("-1");
}
