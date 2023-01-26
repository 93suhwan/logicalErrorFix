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
    if (n == 1) {
      cout << s << endl;
      continue;
    }
    if (n == 2 || (s == 1 && n > 1)) {
      cout << s / 2 << endl;
      continue;
    }
    cout << s / (n / 2 + 1) << endl;
  }
  return 0;
}
