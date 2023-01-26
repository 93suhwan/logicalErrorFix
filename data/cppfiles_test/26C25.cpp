#include <bits/stdc++.h>
using namespace std;
long long work(long long x) {
  long long ans = 1;
  for (long long i = x; i >= 3; i--) {
    ans *= i;
    ans %= 1000000007;
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  long long x;
  while (t--) {
    cin >> x;
    cout << work(2 * x) << endl;
  }
  return 0;
}
