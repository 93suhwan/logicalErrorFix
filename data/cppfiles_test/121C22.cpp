#include <bits/stdc++.h>
using namespace std;
long long t, n, i, j;
string A, B;
long long solve1(long long a, long long b, long long c, long long d) {
  long long res = 1000000000, temp, N = (10 * n);
  for (i = 0; i <= N; ++i) {
    if (b == 0 && d == 0) {
      res = i;
      break;
    }
    if (i & 1)
      swap(b, c), temp = a, a = (d + 1), d = (temp - 1);
    else
      swap(a, d), temp = b, b = (c + 1), c = (temp - 1);
  }
  return res;
}
long long solve2(long long a, long long b, long long c, long long d) {
  long long res = 1000000000, temp, N = (10 * n);
  for (i = 0; i <= N; ++i) {
    if (b == 0 && d == 0) {
      res = i;
      break;
    }
    if (i & 1)
      swap(a, d), temp = b, b = (c + 1), c = (temp - 1);
    else
      swap(b, c), temp = a, a = (d + 1), d = (temp - 1);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long a, b, c, d;
  for (cin >> t; t--; cout << j << "\n") {
    cin >> n >> A >> B;
    a = b = c = d = 0;
    for (i = 0; i < n; ++i) {
      if (A[i] == '1' && B[i] == '1')
        ++a;
      else if (A[i] == '1' && B[i] == '0')
        ++b;
      else if (A[i] == '0' && B[i] == '0')
        ++c;
      else
        ++d;
    }
    j = min(solve1(a, b, c, d), solve2(a, b, c, d));
    if (j == 1000000000) j = -1;
  }
  return 0;
}
