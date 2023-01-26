#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  double n, s;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    long long ans = floor(s / ceil((n + 1) / 2));
    cout << ans << endl;
  }
  return 0;
}
