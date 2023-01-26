#include <bits/stdc++.h>
using namespace std;
const int N = 110000;
int t, n, k, a[N];
struct node {
  int start, end;
} tmp[N];
bool cmp(node x, node y) { return x.start > y.end; }
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
      end = start + k;
      tmp[i].start = start, tmp[i].end = end;
    }
    sort(tmp, tmp + n, cmp);
    for (int i = 0; i < n; i++) {
      int start = tmp[i].start;
      int end = tmp[i].end;
      if (s == 0 && e == 0) {
        s = start, e = end;
      } else if (end < s) {
        s = start + s - end, e = e;
      } else if (start > e) {
        s = s + start - e, e = end;
      } else if (start <= s) {
        s = start, e = end + last;
      } else {
        s = s, e = e + k;
      }
      last = k;
    }
    cout << s << endl;
  }
}
