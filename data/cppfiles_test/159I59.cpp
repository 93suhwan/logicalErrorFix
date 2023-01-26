#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
const int N = 1e6 + 5;
mt19937 rnd(time(0));
int n, K, flag[N], pr[N], cnt;
uint H[N], sum;
unordered_map<uint, int> pos;
int main() {
  scanf("%d", &n);
  K = n >> 1;
  flag[0] = flag[1] = 1, H[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (!flag[i]) pr[++cnt] = i, H[i] = rnd();
    for (int j = 1; j <= cnt && i * pr[j] <= n; j++) {
      flag[i * pr[j]] = 1;
      if (i % pr[j] == 0) break;
      H[i * pr[j]] = H[i] ^ H[pr[j]];
    }
  }
  for (int i = 2; i <= n; i++) H[i] ^= H[i - 1], sum ^= H[i];
  if (sum == 0) {
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) printf("%d ", i);
    return 0;
  }
  for (int i = 1; i <= n; i++)
    if (H[i] == sum) {
      printf("%d\n", n - 1);
      for (int j = 1; j <= n; j++)
        if (j != i) printf("%d ", j);
      return 0;
    }
  for (int i = 1; i <= n; i++) {
    if (pos.count(sum ^ H[i])) {
      int p = pos[sum ^ H[i]];
      printf("%d\n", n - 2);
      for (int j = 1; j <= n; j++)
        if (j != i && j != p) printf("%d ", j);
      return 0;
    }
    pos[H[i]] = i;
  }
  printf("%d\n", n - 3);
  for (int i = 1; i <= n; i++)
    if (i != 2 && i != K && i != n) printf("%d ", i);
  return 0;
}
