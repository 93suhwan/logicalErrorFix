#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, flag = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') flag = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * flag;
}
struct node {
  long long l, r, num;
  long long ans1, ans2;
} b[300005];
long long belong[300005];
deque<char> q;
char a[300005];
long long res = 0;
void add(long long x) {
  if (q.empty())
    q.push_back(a[x]), res++;
  else {
    if (q.back() == a[x])
      q.pop_back(), res--;
    else
      q.push_back(a[x]), res++;
  }
  return;
}
void sub(long long x) {
  if (q.empty())
    q.push_front(a[x]), res++;
  else {
    if (q.front() == a[x])
      q.pop_front(), res--;
    else
      q.push_front(a[x]), res++;
  }
  return;
}
bool cmp(node xx, node yy) {
  if (belong[xx.l] == belong[yy.l]) {
    if (belong[xx.l] % 2) return xx.r < yy.r;
    return xx.r > yy.r;
  }
  return belong[xx.l] < belong[yy.l];
}
bool cmp1(node xx, node yy) { return xx.num < yy.num; }
int main() {
  long long t = read();
  while (t--) {
    res = 0;
    q.clear();
    long long n = read(), m = read();
    scanf("%s", a + 1);
    int len = sqrt(n);
    long long num = 1;
    for (int i = 1; i <= n; i = i + len, num++) {
      for (int j = i; j <= i + len - 1; j++) {
        belong[j] = num;
      }
    }
    for (int i = 1; i <= m; i++) {
      b[i].l = read();
      b[i].r = read();
      b[i].num = i;
    }
    sort(b + 1, b + m + 1, cmp);
    long long l = 1, r = 0;
    for (int i = 1; i <= m; i++) {
      while (l > b[i].l) sub(--l);
      while (r < b[i].r) add(++r);
      while (l < b[i].l) sub(l++);
      while (r > b[i].r) add(r--);
      b[i].ans1 = res;
    }
    sort(b + 1, b + m + 1, cmp1);
    for (int i = 1; i <= m; i++) {
      if (b[i].ans1 == 0)
        printf("0\n");
      else if (b[i].ans1 % 2)
        printf("1\n");
      else
        printf("2\n");
    }
  }
  return 0;
}
