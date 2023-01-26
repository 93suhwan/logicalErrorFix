#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    int n, m, k;
    cin >> n >> m >> k;
    int minP = (m / 2) * (n % 2), maxP = (m / 2) * n;
    bool flag = k >= minP && k <= maxP && (maxP - k) % 2 == 0;
    printf("%s\n", flag ? "YES" : "NO");
  }
  return 0;
}
