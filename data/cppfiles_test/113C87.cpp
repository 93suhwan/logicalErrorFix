#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, sum = 0;
  cin >> n;
  std::vector<long long> h(n);
  for (long long i = 0; i < n; i++) {
    cin >> h[i];
    sum += h[i];
  }
  sort(h.begin(), h.end());
  cin >> m;
  while (m--) {
    long long x, y;
    cin >> x >> y;
    long long cost = 0;
    auto idx = lower_bound(h.begin(), h.end(), x);
    if (idx == h.end()) {
      cost = x - h[n - 1];
      if (sum - h[n - 1] - y < 0) cost += y - sum + h[n - 1];
      cout << cost << endl;
      continue;
    }
    if (*idx == x) {
      cost = max((long long)0, y - sum + *idx);
      std::cout << cost << std::endl;
      continue;
    }
    cost = max((long long)0, y - sum + *idx);
    if (idx == h.begin()) {
      std::cout << cost << std::endl;
      continue;
    }
    long long cost2 = 0;
    --idx;
    cost2 = x - *idx;
    cost2 += max((long long)0, y - sum + *idx);
    cost = min(cost, cost2);
    cout << cost << endl;
  }
}
