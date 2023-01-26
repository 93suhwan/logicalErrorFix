#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int k;
    cin >> k;
    long long int b;
    for (long long int i = 1; i <= 100000; ++i) {
      long long h = i * i;
      if ((h) >= k) {
        b = i;
        break;
      }
    }
    long long int d = k - (b - 1) * (b - 1);
    if (d <= b) {
      cout << d << " " << b << endl;
      continue;
    } else {
      cout << b << " " << b * b - k + 1 << endl;
    }
  }
  return 0;
}
