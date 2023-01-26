#include <bits/stdc++.h>
std::vector<int> V2, W[5];
int main() {
  long long int a, b;
  scanf("%lld%lld", &a, &b);
  if (a == b) {
    printf("YES");
    return 0;
  }
  if (b % 2 == 0) {
    printf("NO");
    return 0;
  }
  while (b) {
    V2.push_back(b % 2);
    b /= 2;
  }
  while (!V2.empty() && V2.back() == 1) V2.pop_back();
  std::reverse(V2.begin(), V2.end());
  while (!V2.empty() && V2.back() == 1) V2.pop_back();
  while (a) {
    W[1].push_back(a % 2);
    a /= 2;
  }
  std::reverse(W[1].begin(), W[1].end());
  for (int i = 0; i < W[1].size(); i++) W[2].push_back(W[1][i]);
  while (W[2].back() == 0) W[2].pop_back();
  W[1].push_back(1);
  for (int i = 0; i < W[1].size(); i++) W[3].push_back(W[1][i]);
  for (int i = 0; i < W[2].size(); i++) W[4].push_back(W[2][i]);
  std::reverse(W[3].begin(), W[3].end());
  std::reverse(W[4].begin(), W[4].end());
  for (int i = 1; i <= 4; i++) {
    while (!W[i].empty() && W[i].back() == 1) W[i].pop_back();
    std::reverse(W[i].begin(), W[i].end());
    while (!W[i].empty() && W[i].back() == 1) W[i].pop_back();
    if (W[i].size() == V2.size()) {
      int control = 1;
      for (int j = 0; j < V2.size(); j++)
        if (W[i][j] != V2[j]) control = 0;
      if (control == 1) {
        printf("YES");
        return 0;
      }
    }
  }
  printf("NO");
}
