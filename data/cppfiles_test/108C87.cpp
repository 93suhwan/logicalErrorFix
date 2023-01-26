#include <bits/stdc++.h>
using namespace std;
struct yuansu {
  int x, y, bianhao, ans;
} a[100005], qujian[100005];
bool cmp1(yuansu a, yuansu b) { return a.x >= b.x; }
bool cmp2(yuansu a, yuansu b) { return a.y >= b.y; }
bool cmp3(yuansu a, yuansu b) { return a.bianhao <= b.bianhao; }
int t, n, cnt;
int main() {
  for (cin >> t; t--;) {
    cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].x;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].y;
      a[i].bianhao = i;
    }
    sort(a + 1, a + n + 1, cmp1);
    for (int i = 1; i <= n; i++) a[i].x = n - i + 1;
    sort(a + 1, a + n + 1, cmp2);
    for (int i = 1; i < n; i++)
      if (a[i].x < a[i + 1].x) {
        qujian[++cnt].x = a[i].x;
        qujian[cnt].y = a[i + 1].x;
      }
    int head = 1, minx = n;
    sort(qujian + 1, qujian + cnt + 1, cmp2);
    while (qujian[head].y >= minx && head <= cnt) {
      minx = min(minx, qujian[head].x);
      ++head;
    }
    for (int i = 1; i <= n; i++) {
      if (a[i].x < minx) {
        a[i].ans = 0;
      } else {
        a[i].ans = 1;
      }
    }
    sort(a + 1, a + n + 1, cmp3);
    for (int i = 1; i <= n; i++) {
      cout << a[i].ans;
    }
    puts("");
  }
  return 0;
}
