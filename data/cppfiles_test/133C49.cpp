#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout << std::fixed << std::setprecision(10);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    n -= 2;
    string ans;
    for (int i = 0; i < n; i++) {
      string buf;
      cin >> buf;
      if (!ans.empty() && ans.back() == buf[0]) ans.pop_back();
      ans += buf;
    }
    if (ans.size() < n + 2) ans += 'b';
    cout << ans << "\n";
  }
  return 0;
}
