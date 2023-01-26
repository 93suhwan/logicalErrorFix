#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans1 = ceil(n * 1.0 / 3);
    long long ans2 = (n - ans1) / 2;
    if (ans1 + 2 * ans2 != n) {
      long long tmp;
      tmp = ans1;
      ans1 = ans2;
      ans2 = tmp;
    }
    cout << ans1 << " " << ans2 << endl;
  }
}
