#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  double n, s;
  int ans;
  while (t--) {
    cin >> n >> s;
    int location = ceil(n / 2);
    int ans = s / (n - location + 1);
    cout << ans << "\n";
  }
}
