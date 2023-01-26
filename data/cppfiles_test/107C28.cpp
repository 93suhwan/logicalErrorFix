#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e7;
const int N = 1e5 + 10;
long long T = 1;
long long s[N];
void init(long long n) {
  for (long long i = 0; i <= n; i++) s[i] = i;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    long long n, a, b;
    std::ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    init(n);
    long long mid = (n / 2) - 1;
    if (n % 2 == 1) mid++;
    long long x = abs(a - b);
    if (x <= 1 && (a + b) <= (n - 2) && a <= mid && b <= mid) {
      if (a == b) {
        for (long long i = 2, j = a; j > 0; i += 2, j--) {
          swap(s[i], s[i + 1]);
        }
      }
      if (a > b) {
        swap(s[n], s[n - 1]);
        for (long long i = 2, j = b; j > 0; j--, i += 2) swap(s[i], s[i + 1]);
      }
      if (b > a) {
        swap(s[1], s[2]);
        for (long long i = n - 1, j = a; j > 0; j--, i -= 2)
          swap(s[i], s[i - 1]);
      }
      for (long long i = 1; i <= n; i++) cout << s[i] << " ";
      cout << '\n';
    } else {
      cout << "-1" << '\n';
    }
  }
  return 0;
}
