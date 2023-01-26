#include <bits/stdc++.h>
using namespace std;
const int N = 110000;
int t, n, k, a[N];
struct node {
  int start, time;
} tmp[N];
bool cmp(node x, node y) {
  if (x.start == y.start) return x.time < y.time;
  return x.start < y.start;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int s = 0, e = 0, last = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &k);
      int start = 0, end = 0;
      for (int j = 0; j < k; j++) {
        scanf("%d", &a[j]);
        start = max(a[j] + 1 - j, start);
      }
      tmp[i].start = start;
      tmp[i].time = k;
    }
    sort(tmp, tmp + n, cmp);
    for (int i = 0; i < n; i++) {
      tmp[i].start -= s;
      s += tmp[i].time;
    }
    sort(tmp, tmp + n, cmp);
    cout << tmp[n - 1].start << endl;
  }
}
