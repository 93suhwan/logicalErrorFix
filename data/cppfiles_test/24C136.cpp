#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int64_t n;
    cin >> n;
    if (n % 10 == 9) {
      cout << (n / 10) + 1 << '\n';
      continue;
    }
    cout << n / 10 << '\n';
  }
  return 0;
}
