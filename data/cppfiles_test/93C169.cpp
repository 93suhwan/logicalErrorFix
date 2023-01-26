#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  long long t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long num = 1, cou = 0;
    while (num <= k && num < n) num *= 2, cou++;
    if (num >= n)
      cout << cou << '\n';
    else {
      long long d = n - num;
      cout << cou + (d + k - 1) / k << '\n';
    }
  }
  return 0;
}
