#include <bits/stdc++.h>
using namespace std;
long long cnt[2][2];
int main() {
  long long n;
  cin >> n;
  for (long long i = 0, a, b; i < n; ++i) {
    cin >> a >> b;
    a /= 2;
    b /= 2;
    ++cnt[a % 2][b % 2];
  }
  long long res = 0;
  for (long long i = 0; i < 2; ++i) {
    for (long long j = 0; j < 2; ++j) {
      long long t = cnt[i][j];
      res += (t * (t - 1) * (n - 2)) / 2 - (t * (t - 1) * (t - 2)) / 3;
    }
  }
  cout << res << endl;
  return 0;
}
