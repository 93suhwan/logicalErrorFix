#include <bits/stdc++.h>
using namespace std;
struct node {
  int a0, a1, a2, a3, a4;
  int sum, id;
  bool vis;
} a[50005];
bool cmp(node a, node b) {
  if (a.sum == b.sum) return a.id < b.id;
  return a.sum < b.sum;
}
bool check(int i, int j) {
  int n = 0;
  if (a[i].a0 < a[j].a0) n++;
  if (a[i].a1 < a[j].a1) n++;
  if (a[i].a2 < a[j].a2) n++;
  if (a[i].a3 < a[j].a3) n++;
  if (a[i].a4 < a[j].a4) n++;
  if (n >= 3)
    return 1;
  else
    return 0;
}
int main() {
  int t, n, flag, tag;
  cin >> t;
  while (t--) {
    flag = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i].a0 >> a[i].a1 >> a[i].a2 >> a[i].a3 >> a[i].a4;
      a[i].vis = 1;
      a[i].sum = a[i].a0 + a[i].a1 + a[i].a2 + a[i].a3 + a[i].a4;
      a[i].id = i + 1;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
      if (a[i].vis == 0)
        continue;
      else {
        if (n > 25001) break;
        tag = 0;
        for (int j = 0; j < n; j++) {
          if (i == j)
            continue;
          else {
            if (check(i, j)) {
              a[j].vis = 0;
            } else {
              a[i].vis = 0;
              tag = 1;
              break;
            }
          }
        }
        if (tag == 0) {
          cout << a[i].id << endl;
          flag = 1;
          break;
        }
      }
    }
    if (flag == 0) cout << -1 << endl;
  }
  return 0;
}
