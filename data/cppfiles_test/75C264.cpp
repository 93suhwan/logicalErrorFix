#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(T a) {
  return a * a;
}
template <class T>
T abs(T x) {
  if (x < 0) return -x;
  return x;
}
const double eps = 1e-8;
const double pi = acos(-1.0);
struct node {
  int start, finish, sz;
};
node ar[100010];
bool compare(node a, node b) {
  if (a.start == b.start) return a.finish > b.finish;
  return a.start < b.start;
}
int main() {
  int tks, ks = 1;
  scanf("%d", &tks);
  while (tks--) {
    int i, j, n, m, x, mx;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%d", &m);
      mx = -1000;
      for (j = 0; j < m; j++) {
        scanf("%d", &x);
        mx = max(mx, x - j);
      }
      ar[i].sz = m;
      ar[i].start = mx + 1;
      ar[i].finish = ar[i].start + m;
    }
    sort(&ar[0], &ar[n], compare);
    int left = 1;
    int right = 1e9 + 100;
    while (left <= right) {
      int mid = (left + right) / 2;
      x = mid;
      for (i = 0; i < n; i++) {
        if (x >= ar[i].start)
          x = x + ar[i].sz;
        else
          break;
      }
      if (i == n)
        right = mid - 1;
      else
        left = mid + 1;
    }
    printf("%d\n", right + 1);
  }
  return 0;
}
