#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
const long long MOD = 1e9 + 7;
const long long inf = 1e8;
pair<int, int> f(int n, int m, int last) {
  int p1 = 0, p2 = 0;
  int cnt = 2;
  while (n > 0 && m > 0) {
    if (cnt % 2 == 0) {
      if (last == 1) {
        last = 2;
        p2++;
        m--;
      } else {
        last = 1;
        p2++;
        n--;
      }
    } else {
      if (last == 1) {
        last = 1;
        p1++;
        n--;
      } else {
        last = 2;
        p1++;
        m--;
      }
    }
    ++cnt;
  }
  if (n > 0) {
    if (last == 1)
      p1 += n;
    else {
      p1 += n - 1;
      p2++;
    }
  } else {
    if (last == 2)
      p1 += m;
    else {
      p1 += m - 1;
      p2++;
    }
  }
  return make_pair(p1, p2);
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long x, n;
    cin >> x >> n;
    if (n == 0) {
      cout << x << endl;
      continue;
    }
    long long d1 = (n - 1) / 4;
    if (n >= 1) ++d1;
    long long s1 = (2 + 4 * (d1 - 1)) * d1 / 2;
    long long d2 = (n - 2) / 4;
    if (n >= 2) ++d2;
    long long s2 = (2 * 2 + 4 * (d2 - 1)) * d2 / 2;
    long long d3 = (n - 3) / 4;
    if (n >= 3) ++d3;
    long long s3 = (2 * 3 + 4 * (d3 - 1)) * d3 / 2;
    long long d4 = (n) / 4;
    long long s4 = (2 * 4 + 4 * (d4 - 1)) * d4 / 2;
    long long sum = s1 + s4 - s2 - s3;
    if (x % 2 == 0) sum *= -1;
    cout << x + sum << endl;
  }
}
