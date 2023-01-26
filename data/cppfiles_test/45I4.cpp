#include <bits/stdc++.h>
const int MAX_N = 1e6;
const int INF = 1e9;
void fast_io() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cerr.tie(NULL);
}
bool a[MAX_N];
int main() {
  fast_io();
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    long long ans = 1;
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < n; i++) {
      if (i == 0) continue;
      if (!a[i] and !a[i - 1]) {
        ans = -1;
        break;
      }
      if (a[i])
        if (a[i - 1])
          ans += 5;
        else
          ans++;
    }
    std::cout << ans << "\n";
  }
  return 0;
}
