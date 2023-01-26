#include <bits/stdc++.h>
using namespace std;
const int N = 2000005;
int n, k;
int a[N];
int ch[N][2], siz[N], tot = 1;
int num[21];
int ans[N], nowans[N], now[N * 10];
int dongtot = 0;
bool Fa = false;
void Ins(int x) {
  for (int i = 20; i >= 1; i--) {
    num[i] = (x & 1);
    x >>= 1;
  }
  int now = 1;
  siz[now]++;
  for (int i = 1; i <= 20; i++) {
    if (!ch[now][num[i]]) ch[now][num[i]] = (++tot);
    now = ch[now][num[i]];
    siz[now]++;
  }
  if (siz[now] >= 2) {
    Fa = true;
  }
}
inline int Min(int A, int B) { return (A > B) ? B : A; }
int Qmin(int posi, int x, int qian) {
  if (!qian) return 0;
  int topos = ((x & qian) ? 1 : 0);
  if (ch[posi][topos])
    return Qmin(ch[posi][topos], x, qian >> 1);
  else
    return (qian) + Qmin(ch[posi][!topos], x, qian >> 1);
}
int Qmax(int posi, int x, int qian) {
  if (!qian) return 0;
  int topos = ((x & qian) ? 1 : 0);
  if (ch[posi][!topos])
    return (qian) + Qmax(ch[posi][!topos], x, qian >> 1);
  else
    return Qmax(ch[posi][topos], x, qian >> 1);
}
void Solve(int posi, int qian) {
  if (siz[posi] < 2) {
    for (int i = 0; i < qian; i++) nowans[i] = 2147483647;
    return;
  }
  int hahaha = (qian >> 1);
  int L = dongtot + 1;
  dongtot += qian;
  for (int i = 0; i < qian; i++) now[L + i] = 2147483647;
  Solve(ch[posi][0], hahaha);
  for (int i = 0; i < (hahaha); i++) {
    now[L + i] = Min(now[L + i], nowans[i]);
    now[L + i + (hahaha)] = Min(now[L + i + (hahaha)], nowans[i]);
  }
  Solve(ch[posi][1], hahaha);
  for (int i = 0; i < (hahaha); i++) {
    now[L + i] = Min(now[L + i], nowans[i]);
    now[L + i + (hahaha)] = Min(now[L + i + (hahaha)], nowans[i]);
  }
  if (!ch[posi][0] || !ch[posi][1]) return;
  for (int i = 0; i < (hahaha); i++) {
    int Md1 = Qmin(ch[posi][1], i, hahaha >> 1);
    int Md2 = Qmax(ch[posi][0], i, hahaha >> 1);
    now[L + i] = Min(now[L + i], Md1 - Md2 + (hahaha));
  }
  for (int i = (hahaha); i < qian; i++) {
    int Md1 = Qmin(ch[posi][0], i ^ (hahaha), hahaha >> 1);
    int Md2 = Qmax(ch[posi][1], i ^ (hahaha), hahaha >> 1);
    now[L + i] = Min(now[L + i], Md1 - Md2 + (hahaha));
  }
  for (int i = 0; i < qian; i++) {
    nowans[i] = now[L + i];
    ans[i] = Min(ans[i], nowans[i]);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    Ins(a[i]);
  }
  if (Fa) {
    for (int i = 0; i < (1 << k); i++) printf("0 ");
    return 0;
  }
  for (int i = 0; i < (1 << k); i++) ans[i] = 2147483647;
  Solve(1, (1 << 20));
  for (int i = 0; i < (1 << k); i++) printf("%d ", ans[i]);
}
