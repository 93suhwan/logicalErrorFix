#include <bits/stdc++.h>
using namespace std;
const int siz = 1e3;
int n, arr[siz + 5];
map<int, long long> nb;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &arr[i]);
  }
  long long open = 0, ans = 0, lb = 0;
  for (int i = 1; i <= n; ++i) {
    if (i & 1) {
      nb[open] = lb;
      open += arr[i];
    } else {
      int cur = arr[i];
      lb = 0;
      while (!nb.empty()) {
        auto it = nb.rbegin();
        if (open - it->first <= cur) {
          long long sub = open - it->first;
          ans += it->second + sub;
          cur -= sub;
          open -= sub;
          lb = it->second + 1;
          nb.erase(it->first);
        } else {
          break;
        }
      }
      if (cur) {
        long long sub = min(open, (long long)cur);
        ans += sub;
        open -= sub;
        cur -= sub;
        lb = !cur;
      }
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
