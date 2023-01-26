#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, m, i, j, k, sum, cnt, temp, ans;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << " " << n / 3 << "\n";
    } else if (n % 3 == 1) {
      cout << n / 3 + 1 << " " << n / 3 << "\n";
    } else {
      cout << n / 3 << " " << n / 3 + 1 << "\n";
    }
  }
  return 0;
}
