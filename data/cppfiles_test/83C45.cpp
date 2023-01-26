#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline", "no-stack-protector", "unroll-loops")
using namespace std;
const int N = 5005;
char a[N];
int tax[N], rk[N], sa[N], tp[N], f[N], height[N], n, m;
void Sort() {
  for (int i = 0; i <= m; i++) tax[i] = 0;
  for (int i = 1; i <= n; i++) tax[rk[i]]++;
  for (int i = 1; i <= m; i++) tax[i] += tax[i - 1];
  for (int i = n; i >= 1; i--) sa[tax[rk[tp[i]]]--] = tp[i];
}
void build_SA() {
  m = 127;
  for (int i = 1; i <= n; i++) rk[i] = a[i], tp[i] = i;
  Sort();
  for (int w = 1, p = 0; p < n; w <<= 1) {
    p = 0;
    for (int i = n - w + 1; i <= n; i++) tp[++p] = i;
    for (int i = 1; i <= n; i++)
      if (sa[i] > w) tp[++p] = sa[i] - w;
    Sort();
    for (int i = 1; i <= n; i++) swap(tp[i], rk[i]);
    rk[sa[1]] = p = 1;
    for (int i = 2; i <= n; i++)
      rk[sa[i]] =
          (tp[sa[i]] == tp[sa[i - 1]] && tp[sa[i] + w] == tp[sa[i - 1] + w])
              ? p
              : ++p;
    m = p;
  }
}
void get_Height() {
  int h = 0;
  for (int i = 1; i <= n; i++) {
    if (rk[i] == 1)
      h = 0;
    else {
      int k = sa[rk[i] - 1];
      if (--h < 0) h = 0;
      while (a[i + h] == a[k + h]) h++;
    }
    height[rk[i]] = h;
  }
}
int LCP[N][N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    scanf("%s", a + 1);
    build_SA(), get_Height();
    for (int i = 1; i < n; i++) {
      LCP[i][i + 1] = height[i + 1];
      for (int j = i + 2; j <= n; j++)
        LCP[i][j] = min(LCP[i][j - 1], height[j]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      f[i] = n - i + 1;
      for (int j = 1; j < i; j++)
        if (rk[i] > rk[j])
          f[i] = max(f[i], f[j] + n - i + 1 - LCP[rk[j]][rk[i]]);
      ans = max(ans, f[i]);
    }
    printf("%d\n", ans);
    for (int i = 0; i <= n; i++)
      tax[i] = rk[i] = sa[i] = tp[i] = a[i] = f[i] = height[i] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++) LCP[i][j] = 0;
  }
  return 0;
}
