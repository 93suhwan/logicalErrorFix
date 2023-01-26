#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 0;
    if (n % 10 == 9) ans++;
    ans += n / 10;
    cout << ans << "\n";
  }
  return 0;
}
