#include <bits/stdc++.h>
long long T, U;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  srand(time(NULL));
  cin >> T;
  while (T--) {
    long long n, a = 0, b = 0, ok = 1, ans;
    string s;
    cin >> s;
    long long len = s.length();
    for (long long i = 0; i <= len - 1; i++) {
      if (i % 2 == 0)
        a = 10 * a + (s[i] - '0');
      else
        b = 10 * b + (s[i] - '0');
    }
    if (!a)
      ans = b - 1;
    else if (!b)
      ans = a - 1;
    else
      ans = 2 * a * b;
    cout << ans << "\n";
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms";
  return 0;
}
