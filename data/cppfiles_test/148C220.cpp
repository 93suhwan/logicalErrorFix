#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int w, h;
    cin >> w >> h;
    long long int ans = 0, max_diff = 0, max_diffy = 0;
    for (int i = 0; i < 2; i++) {
      long long int k;
      cin >> k;
      long long int a, b;
      cin >> a;
      k -= 2;
      while (k--) {
        long long int x;
        cin >> x;
      }
      cin >> b;
      max_diff = max(max_diff, b - a);
    }
    ans = h * max_diff;
    for (int i = 0; i < 2; i++) {
      long long int k;
      cin >> k;
      long long int a, b;
      cin >> a;
      k -= 2;
      while (k--) {
        long long int x;
        cin >> x;
      }
      cin >> b;
      max_diffy = max(max_diffy, b - a);
    }
    ans = max(ans, max_diffy * w);
    std::cout << ans << std::endl;
  }
  return 0;
}
