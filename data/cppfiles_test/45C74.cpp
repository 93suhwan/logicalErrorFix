#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 9;
const int INF = 1e9;
void prereq() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
bool compare(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
signed main() {
  prereq();
  int t, n, c, d, c1, d1;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    c = d = c1 = d1 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == 0) {
        c1 += abs(c - d);
        c++;
      } else {
        d1 += abs(d - c);
        d++;
      }
    }
    if (abs(c - d) > 1)
      printf("-1\n");
    else {
      if (c > d)
        printf("%d\n", c1);
      else if (d > c)
        printf("%d\n", d1);
      else
        printf("%d\n", min(c1, d1));
    }
  }
  return 0;
}
