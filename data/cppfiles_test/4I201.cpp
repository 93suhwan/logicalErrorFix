#include <bits/stdc++.h>
int t, P;
std::vector<int> prime;
bool vis[100005];
int main() {
  for (int i = 2; i <= 100000; ++i) {
    if (!vis[i]) prime.emplace_back(i);
    for (int j = 0; j < prime.size() && i * prime[j] <= 100000; ++j) {
      vis[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &P);
    --P;
    int cnt[5] = {0};
    for (auto& i : prime) {
      if (cnt[0] == 2) break;
      while (P % i == 0 && cnt[0] < 2) {
        P /= i;
        cnt[++cnt[0]] = i;
      }
    }
    printf("%d %d\n", cnt[1], cnt[1] * cnt[2]);
  }
  return 0;
}
