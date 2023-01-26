#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int t, n;
struct node {
  string s;
  int num[5];
} a[maxn];
bool cmpA(const node &a, const node &b) {
  if (a.num[0] * (b.s.size() - b.num[0]) == b.num[0] * (a.s.size() - a.num[0]))
    if (b.s.size() - b.num[0] == 0)
      return a.s.size() > b.s.size();
    else
      return a.s.size() < b.s.size();
  else
    return a.num[0] * (b.s.size() - b.num[0]) >
           b.num[0] * (a.s.size() - a.num[0]);
}
bool cmpB(const node &a, const node &b) {
  if (a.num[1] * (b.s.size() - b.num[1]) == b.num[1] * (a.s.size() - a.num[1]))
    if (b.s.size() - b.num[1] == 0)
      return a.s.size() > b.s.size();
    else
      return a.s.size() < b.s.size();
  else
    return a.num[1] * (b.s.size() - b.num[1]) >
           b.num[1] * (a.s.size() - a.num[1]);
}
bool cmpC(const node &a, const node &b) {
  if (a.num[2] * (b.s.size() - b.num[2]) == b.num[2] * (a.s.size() - a.num[2]))
    if (b.s.size() - b.num[2] == 0)
      return a.s.size() > b.s.size();
    else
      return a.s.size() < b.s.size();
  else
    return a.num[2] * (b.s.size() - b.num[2]) >
           b.num[2] * (a.s.size() - a.num[2]);
}
bool cmpD(const node &a, const node &b) {
  if (a.num[3] * (b.s.size() - b.num[3]) == b.num[3] * (a.s.size() - a.num[3]))
    if (b.s.size() - b.num[3] == 0)
      return a.s.size() > b.s.size();
    else
      return a.s.size() < b.s.size();
  else
    return a.num[3] * (b.s.size() - b.num[3]) >
           b.num[3] * (a.s.size() - a.num[3]);
}
bool cmpE(const node &a, const node &b) {
  if (a.num[4] * (b.s.size() - b.num[4]) == b.num[4] * (a.s.size() - a.num[4]))
    if (b.s.size() - b.num[4] == 0)
      return a.s.size() > b.s.size();
    else
      return a.s.size() < b.s.size();
  else
    return a.num[4] * (b.s.size() - b.num[4]) >
           b.num[4] * (a.s.size() - a.num[4]);
}
int main() {
  for (scanf("%d", &t); t--;) {
    scanf("%d", &n);
    int num1, num2, now, ans = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].s;
      for (auto j : a[i].s) a[i].num[j - 'a']++;
    }
    sort(a + 1, a + n + 1, cmpA);
    now = 1, num1 = 0, num2 = 0;
    while (now <= n &&
           num1 + a[now].num[0] > num1 - a[now].num[0] + a[now].s.size()) {
      num1 += a[now].num[0];
      num1 += a[now].s.size() - a[now].num[0];
      ++now;
    }
    ans = max(ans, now - 1);
    sort(a + 1, a + n + 1, cmpB);
    now = 1, num1 = 0, num2 = 0;
    while (now <= n &&
           num1 + a[now].num[1] > num1 - a[now].num[1] + a[now].s.size()) {
      num1 += a[now].num[1];
      num1 += a[now].s.size() - a[now].num[1];
      ++now;
    }
    ans = max(ans, now - 1);
    sort(a + 1, a + n + 1, cmpC);
    now = 1, num1 = 0, num2 = 0;
    while (now <= n &&
           num1 + a[now].num[2] > num1 - a[now].num[2] + a[now].s.size()) {
      num1 += a[now].num[2];
      num1 += a[now].s.size() - a[now].num[2];
      ++now;
    }
    ans = max(ans, now - 1);
    sort(a + 1, a + n + 1, cmpD);
    now = 1, num1 = 0, num2 = 0;
    while (now <= n &&
           num1 + a[now].num[3] > num1 - a[now].num[3] + a[now].s.size()) {
      num1 += a[now].num[3];
      num1 += a[now].s.size() - a[now].num[3];
      ++now;
    }
    ans = max(ans, now - 1);
    sort(a + 1, a + n + 1, cmpE);
    now = 1, num1 = 0, num2 = 0;
    while (now <= n &&
           num1 + a[now].num[4] > num1 - a[now].num[4] + a[now].s.size()) {
      num1 += a[now].num[4];
      num1 += a[now].s.size() - a[now].num[4];
      ++now;
    }
    ans = max(ans, now - 1);
    printf("%d\n", ans);
  }
  return 0;
}
