#include <bits/stdc++.h>
using namespace std;
const int Inf = 0x3f3f3f3f;
int N, K;
int gc[1005];
vector<int> ans;
int main() {
  scanf("%d%d", &N, &K);
  int d = (N + K - 1) / K;
  for (int i = 1; i < d; ++i) gc[i] = (i - 1) / (K - 1) + 1;
  printf("%d\n", gc[d - 1] + 1);
  for (int i = 0; i < N; ++i)
    for (int j = i + 1; j < N; ++j) {
      if (i / K == j / K)
        ans.push_back(1);
      else
        ans.push_back(gc[j / K] + 1);
    }
  for (int i : ans) printf("%d ", i);
  puts("");
  return 0;
}
