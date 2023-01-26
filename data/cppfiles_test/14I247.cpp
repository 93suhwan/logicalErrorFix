#include <bits/stdc++.h>
const int N = (int)1e6 + 5;
const int M = (int)1e9 + 5;
const int mod = (int)1000000007;
const int max_prime = (int)1e6 + 3;
struct out {
  int l, r, d;
};
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> inp(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &inp[i]);
    }
    vector<int> checker = inp;
    sort(checker.begin(), checker.end());
    vector<out> ans;
    for (int pos = 0; pos < n; pos++) {
      int cnt = 0;
      int L = pos, R;
      for (int i = L; i <= n - 1; i++) {
        if (inp[i] == checker[pos]) {
          R = i;
          break;
        }
      }
      if (R > L) {
        ans.push_back({L + 1, R + 1, R - L});
        swap(inp[L], inp[R]);
      }
    }
    printf("%d", ans.size());
    printf("\n");
    for (auto x : ans) {
      if (x.l > x.r) {
        swap(x.l, x.r);
      }
      printf("%d %d %d\n", x.l, x.r, x.d);
    }
  }
  return 0;
}
