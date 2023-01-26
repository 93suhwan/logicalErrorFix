#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 10;
const int mx = 40;
const int mod = 1e9 + 7;
const long long inf = 34359738370;
const int INF = 1e9 + 7;
const double pi = acos(-1.0);
int n;
char s[maxn];
struct node {
  int num[7];
} q[maxn];
bool cmp0(const node &a, const node &b) {
  int a1 = a.num[0], b1 = a.num[5] - a1;
  int a2 = b.num[0], b2 = b.num[5] - a2;
  int d1 = a1 - b1, d2 = a2 - b2;
  if (d1 != d2)
    return d1 > d2;
  else
    return a1 > a2;
}
bool cmp1(const node &a, const node &b) {
  int a1 = a.num[1], b1 = a.num[5] - a1;
  int a2 = b.num[1], b2 = b.num[5] - a2;
  int d1 = a1 - b1, d2 = a2 - b2;
  if (d1 != d2)
    return d1 > d2;
  else
    return a1 > a2;
}
bool cmp2(const node &a, const node &b) {
  int a1 = a.num[2], b1 = a.num[5] - a1;
  int a2 = b.num[2], b2 = b.num[5] - a2;
  int d1 = a1 - b1, d2 = a2 - b2;
  if (d1 != d2)
    return d1 > d2;
  else
    return a1 > a2;
}
bool cmp3(const node &a, const node &b) {
  int a1 = a.num[3], b1 = a.num[5] - a1;
  int a2 = b.num[3], b2 = b.num[5] - a2;
  int d1 = a1 - b1, d2 = a2 - b2;
  if (d1 != d2)
    return d1 > d2;
  else
    return a1 > a2;
}
bool cmp4(const node &a, const node &b) {
  int a1 = a.num[4], b1 = a.num[5] - a1;
  int a2 = b.num[4], b2 = b.num[5] - a2;
  int d1 = a1 - b1, d2 = a2 - b2;
  if (d1 != d2)
    return d1 > d2;
  else
    return a1 > a2;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (register int i = 1; i <= n; i++) {
      memset(q[i].num, 0, sizeof q[i].num);
      scanf("%s", s + 1);
      int l = strlen(s + 1);
      q[i].num[5] = l;
      for (register int j = 1; j <= l; j++) q[i].num[s[j] - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < 5; i++) {
      int sum = 0, mmax = 0;
      if (i == 0)
        sort(q + 1, q + n + 1, cmp0);
      else if (i == 1)
        sort(q + 1, q + n + 1, cmp1);
      else if (i == 2)
        sort(q + 1, q + n + 1, cmp2);
      else if (i == 3)
        sort(q + 1, q + n + 1, cmp3);
      else if (i == 4)
        sort(q + 1, q + n + 1, cmp4);
      int t = 0;
      for (int j = 1; j <= n; j++) {
        if (mmax + q[j].num[i] <= (sum + q[j].num[5] - q[j].num[i])) {
          break;
        }
        t++;
        mmax += q[j].num[i];
        sum += q[j].num[5] - q[j].num[i];
      }
      ans = max(ans, t);
    }
    printf("%d\n", ans);
  }
  return 0;
}
