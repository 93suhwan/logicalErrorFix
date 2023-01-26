#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct p {
  int a, b, c, d, e;
} q[N];
int cmp(struct p a, struct p b) {
  int sum1 = 0, sum2 = 0;
  if (a.a > b.a)
    sum1++;
  else
    sum2++;
  if (a.b > b.b)
    sum1++;
  else
    sum2++;
  if (a.c > b.c)
    sum1++;
  else
    sum2++;
  if (a.d > b.d)
    sum1++;
  else
    sum2++;
  if (a.e > b.e)
    sum1++;
  else
    sum2++;
  if (sum1 > sum2)
    return 0;
  else
    return 1;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = 0;
    int cnt = n - 1;
    for (int i = 0; i < n; i++) {
      cin >> q[i].a >> q[i].b >> q[i].c >> q[i].d >> q[i].e;
      if (cmp(q[i], q[ans])) {
        ans = i;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (cmp(q[i], q[cnt])) {
        cnt = i;
      }
    }
    if (cnt == ans)
      cout << ans + 1 << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
