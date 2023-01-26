#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long f[200001] = {0};
  f[0] = 1;
  f[1] = 1;
  f[2] = 1;
  int t;
  cin >> t;
  int j = 0;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      continue;
    }
    for (int i = j + 1; i <= 2 * n; i++) {
      long long k = f[i - 1] * i;
      k %= M;
      f[i] = k;
      f[2] = 1;
    }
    j = max(j, 2 * n);
    long long k = f[2 * n];
    k %= M;
    cout << k << endl;
  }
  return 0;
}
