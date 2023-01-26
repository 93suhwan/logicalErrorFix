#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = (n * 5) / 2;
    if (ans <= 15)
      ans = 15;
    else if (ans % 5 != 0)
      ans = (ans / 5) * 5 + 5;
    cout << ans << endl;
  }
  return 0;
}
