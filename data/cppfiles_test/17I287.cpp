#include <bits/stdc++.h>
using namespace std;
char getch() {
  static char buf[1 << 14], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
void read(int &x) {
  x = 0;
  char c = getch();
  while (c < '0' || c > '9') c = getch();
  while (c >= '0' && c <= '9') {
    x = x * 10 + (c - '0');
    c = getch();
  }
}
const int Maxn = 50000 + 10;
int T, n;
int b1[Maxn], b2[Maxn], b3[Maxn], b4[Maxn], b5[Maxn];
struct node {
  int loc, val;
} a1[Maxn], a2[Maxn], a3[Maxn], a4[Maxn], a5[Maxn];
int cmp(node a, node b) { return a.val < b.val; }
node sum[Maxn];
int main() {
  read(T);
  while (T--) {
    read(n);
    for (int i = 1; i <= n; ++i) sum[i].val = 0;
    for (int i = 1; i <= n; ++i) {
      a1[i].loc = i;
      read(a1[i].val);
      b1[i] = a1[i].val;
      a2[i].loc = i;
      read(a2[i].val);
      b2[i] = a2[i].val;
      a3[i].loc = i;
      read(a3[i].val);
      b3[i] = a3[i].val;
      a4[i].loc = i;
      read(a4[i].val);
      b4[i] = a4[i].val;
      a5[i].loc = i;
      read(a5[i].val);
      b5[i] = a5[i].val;
    }
    sort(a1 + 1, a1 + n + 1, cmp);
    sort(a2 + 1, a2 + n + 1, cmp);
    sort(a3 + 1, a3 + n + 1, cmp);
    sort(a4 + 1, a4 + n + 1, cmp);
    sort(a5 + 1, a5 + n + 1, cmp);
    for (int i = 1; i <= n; ++i) {
      sum[a1[i].loc].val += i;
      sum[a2[i].loc].val += i;
      sum[a3[i].loc].val += i;
      sum[a4[i].loc].val += i;
      sum[a5[i].loc].val += i;
      sum[i].loc = i;
    }
    sort(sum + 1, sum + n + 1, cmp);
    int s = min(n, 4 * (int)sqrt(n));
    int fflag = 0;
    for (int tt = 1; tt <= s; ++tt) {
      int flag = 0;
      int minn = sum[tt].loc;
      for (int i = 1; i <= n; ++i) {
        int tim = 0;
        if (i == minn) continue;
        if (b1[minn] < b1[i]) tim++;
        if (b2[minn] < b2[i]) tim++;
        if (b3[minn] < b3[i]) tim++;
        if (b4[minn] < b4[i]) tim++;
        if (b4[minn] < b5[i]) tim++;
        if (tim < 3) {
          flag = 1;
          break;
        }
      }
      if (!flag) {
        fflag = minn;
        break;
      }
    }
    if (fflag)
      printf("%d\n", fflag);
    else
      puts("-1");
  }
  return 0;
}
