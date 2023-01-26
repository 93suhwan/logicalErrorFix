#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5 + 5;
struct letter {
  int a, b, c, d, e, len;
} l[Maxn];
char ch[Maxn << 1];
bool cmp1(const letter &a, const letter &b) {
  return a.a * b.len > b.a * a.len;
}
bool cmp2(const letter &a, const letter &b) {
  return a.b * b.len > b.b * a.len;
}
bool cmp3(const letter &a, const letter &b) {
  return a.c * b.len > b.c * a.len;
}
bool cmp4(const letter &a, const letter &b) {
  return a.d * b.len > b.d * a.len;
}
bool cmp5(const letter &a, const letter &b) {
  return a.e * b.len > b.e * a.len;
}
int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int n, ans = 0, sum1, sum2;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%s", ch + 1);
      l[i].len = strlen(ch + 1);
      for (int j = 1; j <= l[i].len; j++) {
        l[i].a += (ch[j] == 'a');
        l[i].b += (ch[j] == 'b');
        l[i].c += (ch[j] == 'c');
        l[i].d += (ch[j] == 'd');
        l[i].e += (ch[j] == 'e');
      }
    }
    sort(l + 1, l + n + 1, cmp1);
    sum1 = sum2 = 0;
    for (int i = 1; i <= n; i++) {
      sum1 += l[i].a, sum2 += l[i].len;
      if (sum1 * 2 <= sum2) {
        ans = max(ans, i - 1);
        break;
      }
      if (i == n) ans = n;
    }
    sort(l + 1, l + n + 1, cmp2);
    sum1 = sum2 = 0;
    for (int i = 1; i <= n; i++) {
      sum1 += l[i].b, sum2 += l[i].len;
      if (sum1 * 2 <= sum2) {
        ans = max(ans, i - 1);
        break;
      }
      if (i == n) ans = n;
    }
    sort(l + 1, l + n + 1, cmp3);
    sum1 = sum2 = 0;
    for (int i = 1; i <= n; i++) {
      sum1 += l[i].c, sum2 += l[i].len;
      if (sum1 * 2 <= sum2) {
        ans = max(ans, i - 1);
        break;
      }
      if (i == n) ans = n;
    }
    sort(l + 1, l + n + 1, cmp4);
    sum1 = sum2 = 0;
    for (int i = 1; i <= n; i++) {
      sum1 += l[i].d, sum2 += l[i].len;
      if (sum1 * 2 <= sum2) {
        ans = max(ans, i - 1);
        break;
      }
      if (i == n) ans = n;
    }
    sort(l + 1, l + n + 1, cmp5);
    sum1 = sum2 = 0;
    for (int i = 1; i <= n; i++) {
      sum1 += l[i].e, sum2 += l[i].len;
      if (sum1 * 2 <= sum2) {
        ans = max(ans, i - 1);
        break;
      }
      if (i == n) ans = n;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) l[i] = (letter){0, 0, 0, 0, 0, 0};
  }
  return 0;
}
