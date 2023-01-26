#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
const long long INF = 1e18;
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, max = 0;
    cin >> n;
    long long a[n];
    for (int i = (int)0; i < (int)n; ++i) {
      cin >> a[i];
      if (a[i] > max) max = a[i];
    }
    if (max == a[n - 1])
      cout << 0 << endl;
    else if (max == a[n - 2])
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
}
