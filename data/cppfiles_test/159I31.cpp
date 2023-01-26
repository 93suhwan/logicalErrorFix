#include <bits/stdc++.h>
const int N = 1000005;
int n, lp[N], in[N];
std::vector<int> p;
std::vector<int> calc(int n) {
  std::vector<int> ans;
  ans.push_back(1);
  for (int i = n; i > 1; --i) {
    in[i] = in[i + 1];
    if (lp[i] != i) {
      ans.push_back(i);
      in[i] ^= 1;
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
  for (int j = std::max(1, n - 20); j <= n; ++j) {
    std::vector<int> cur = calc(j);
    if (ans.size() < cur.size()) ans = cur;
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); ++i) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
