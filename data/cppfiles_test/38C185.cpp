#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 15;
    long long k = (n + 1) / 2 * 5;
    cout << max(ans, k) << endl;
  }
  return 0;
}
