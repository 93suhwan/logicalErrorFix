#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  float n, s;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    int ans = floor(s / ceil((n + 1) / 2));
    cout << ans << endl;
  }
  return 0;
}
