#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int64_t> arr(n);
    for (auto &i : arr) cin >> i;
    for (;;) {
      bool erased = false;
      for (int i = arr.size() - 1; i >= 0; i--) {
        if (arr[i] % (i + 2) != 0) {
          arr.erase(arr.begin() + i);
          erased = true;
          break;
        }
      }
      if (arr.empty()) break;
      if (!erased) break;
    }
    cout << (arr.empty() ? "YES\n" : "NO\n");
  }
  return 0;
}
