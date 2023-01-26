#include <bits/stdc++.h>
const int N = 1000005;
int n, lp[N], in[N];
std::vector<int> p;
std::vector<int> calc(int n, int l, int k) {
  std::vector<int> ans;
  ans.push_back(1);
  int t = 0;
  for (int i = n; i > 1; --i) {
    in[i] = in[i + 1];
    if (lp[i] != i) {
      if (t >= l || k >> t & 1) {
        ans.push_back(i);
        in[i] ^= 1;
      }
      ++t;
    } else {
      int k = 1, par = 0, sum = 0;
      for (int j = i; j <= n; j += i) {
        int cur = 0;
        for (int t = j; !(t % i); t /= i) cur ^= 1;
        sum ^= cur;
        par ^= (in[j] ^ in[std::min(n + 1, j + i)]) * sum;
      }
      par &= 1;
      if (par) {
        ans.push_back(i);
        in[i] ^= 1;
      }
    }
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    if (!lp[i]) {
      lp[i] = i;
      p.push_back(i);
    }
    for (int j = 0; j < (int)p.size() && p[j] <= lp[i] && p[j] * i < N; ++j)
      lp[p[j] * i] = p[j];
  }
  std::vector<int> ans;
  for (int j = std::max(1, n - 10); j <= n; ++j) {
    for (int k = 0; k < 16; ++k) {
      std::vector<int> cur = calc(j, 4, k);
      if (ans.size() < cur.size()) ans = cur;
    }
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); ++i) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
