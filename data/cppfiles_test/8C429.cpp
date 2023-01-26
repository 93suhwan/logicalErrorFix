#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int k = n / 3;
    int j = n % 3;
    int ans1 = k;
    int ans2 = k;
    if (j == 1) ans1++;
    if (j == 2) ans2++;
    cout << ans1 << " " << ans2 << endl;
  }
  return 0;
}
