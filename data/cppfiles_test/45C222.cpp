#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int TestCases;
  std::cin >> TestCases;
  while (TestCases--) {
    int n;
    std::cin >> n;
    std::vector<int> V(n);
    for (auto& v : V) {
      std::cin >> v;
      v &= 1;
    }
    int S = std::accumulate(V.begin(), V.end(), 0);
    if (!(S == n / 2 || (n - S) == n / 2)) {
      std::cout << "-1\n";
      continue;
    }
    auto cnt = [&](std::vector<int> X) {
      std::vector<int> need, pos;
      for (int i = 0; i < n; i++) {
        if (X[i] == 1) {
          if (V[i] == 1)
            continue;
          else
            need.push_back(i);
        } else if (V[i] == 1)
          pos.push_back(i);
      }
      int o = 0;
      for (int i = 0; i < (int)need.size(); i++) o += abs(need[i] - pos[i]);
      return o;
    };
    if (n & 1) {
      std::vector<int> P(n);
      if ((n / 2) + 1 == S) P[0] = 1;
      for (int i = 1; i < n; i++) {
        P[i] = P[i - 1] ^ 1;
      }
      std::cout << cnt(P) << '\n';
    } else {
      std::vector<int> A(n), B(n);
      A[0] = 1;
      for (int i = 1; i < n; i++) {
        A[i] = A[i - 1] ^ 1;
        B[i] = B[i - 1] ^ 1;
      }
      std::cout << std::min(cnt(A), cnt(B)) << '\n';
    }
  }
}
