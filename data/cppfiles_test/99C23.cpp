#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int x, n;
    cin >> x >> n;
    if (n == 0)
      cout << x << endl;
    else if (n > 0) {
      long long int nums = (n / 4) * 4;
      n = n % 4;
      long long int cnt = 0;
      nums++;
      while (cnt < n) {
        if (x % 2 == 0)
          x -= nums;
        else
          x += nums;
        cnt++;
        nums++;
      }
      cout << x << endl;
    }
  }
  return 0;
}
