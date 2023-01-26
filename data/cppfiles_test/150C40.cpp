#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
char s[N];
int n, k, arr[N];
long long x;
inline bool check(int val, int o, int t) {
  if (val > o + t * 2) return false;
  return (o > 0 || (val % 2 == 0));
}
void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  int ans = 1000000010;
  for (int o = 0; o < 2; o++) {
    for (int mx, cur, t = 0; t < 3; t++) {
      mx = 0;
      for (int i = 0; i < n; i++) {
        cur = max(0, arr[i] / 3 - 10);
        while (cur * 3 < arr[i]) {
          if (check(arr[i] - cur * 3, o, t)) break;
          cur++;
        }
        if (cur * 3 > arr[i]) cur = 1000000010;
        mx = max(mx, cur);
      }
      ans = min(ans, mx + o + t);
    }
  }
  printf("%d\n", ans);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
