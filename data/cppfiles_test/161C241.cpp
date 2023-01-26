#include <bits/stdc++.h>
using namespace std;
struct line {
  int l, r;
  int sum = 0;
} test[1010], test1[1010];
int ans[1010];
bool cmp(line a, line b) { return a.sum < b.sum; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    memset(ans, 0, sizeof(ans));
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> test1[i].l >> test1[i].r;
      test[i].l = test1[i].l;
      test[i].r = test1[i].r;
      test[i].sum = test[i].r - test[i].l;
    }
    sort(test, test + n, cmp);
    for (int i = 0; i < n; i++)
      for (int j = test[i].l; j <= test[i].r; j++)
        if (!ans[j]) {
          ans[j] = 1;
          test[i].sum = j;
          break;
        }
    for (int i = 0; i < n; i++) {
      int tl = test1[i].l;
      int tr = test1[i].r;
      for (int j = 0; j < n; j++) {
        if (test[j].l == tl && test[j].r == tr)
          cout << test[j].l << ' ' << test[j].r << ' ' << test[j].sum << endl;
      }
    }
  }
  return 0;
}
