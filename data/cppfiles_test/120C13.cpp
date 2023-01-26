#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<vector<long long>> precomp(200000 + 1, vector<long long>(32, 0));
  for (long long i = 0; i <= 200000; i++) {
    for (long long j = 0; j < 32; j++) {
      if (i != 0) precomp[i][j] = precomp[i - 1][j];
      if (i & 1 << j) precomp[i][j]++;
    }
  }
  long long t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    long long ans = LLONG_MIN;
    for (long long i = 0; i < 32; i++)
      ans = max(ans, precomp[r][i] - precomp[l - 1][i]);
    cout << (r - l + 1) - ans << endl;
  }
  return 0;
}
