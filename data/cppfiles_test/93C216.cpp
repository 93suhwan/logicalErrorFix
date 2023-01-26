#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int64_t n, k;
    cin >> n >> k;
    int64_t comp = 1, hours = 0;
    while (comp < k) {
      comp *= 2;
      ++hours;
    }
    if (comp < n) hours += (n - comp + k - 1) / k;
    cout << hours << "\n";
  }
  return 0;
}
