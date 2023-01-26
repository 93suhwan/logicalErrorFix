#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long temp = power(a, b / 2);
  if (b % 2 == 0)
    return temp * temp;
  else
    return temp * temp * a;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k, ans = 0, i;
    cin >> n >> k;
    if (n == 1) {
      cout << "0\n";
      continue;
    }
    if (power(2, k) >= n) {
      cout << (int)(log2(n) + 1) << endl;
    } else {
      cout << (n - pow(2, k) + k - 1) / k + k << endl;
    }
  }
  return 0;
}
