#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, s;
    cin >> n >> s;
    long long rem, quo;
    quo = s / n;
    rem = s % n;
    if (n > s) {
      cout << 0 << endl;
    } else if (rem > 0 and quo > 0) {
      cout << quo + rem - 1 << endl;
    } else if (quo == 0)
      cout << rem << endl;
    else
      cout << quo << endl;
  }
  return 0;
}
