#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans;
    if (n <= 6)
      ans = 15;
    else if (n > 6 && n <= 8)
      ans = 20;
    else if (n > 8 && n <= 10)
      ans = 25;
    else {
      if (n % 2 == 0)
        ans = (n / 2) * 5;
      else
        ans = (n / 2) * 5 + 5;
    }
    cout << ans << endl;
  }
}
