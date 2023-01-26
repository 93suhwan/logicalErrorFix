#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 1;
long long nums[maxn];
int main() {
  long long t, n, k;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    cin >> n >> k;
    long long p = 0;
    long long last = 0;
    for (long long j = 0; j < n; j++) {
      cin >> nums[j];
      if (p != 0) {
        if (nums[j] < nums[j - 1]) p++;
      } else
        p = 1;
    }
    if (p <= k)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
