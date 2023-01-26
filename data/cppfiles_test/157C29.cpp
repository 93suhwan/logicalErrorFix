#include <bits/stdc++.h>
using namespace std;
int c[5001][5001];
int main() {
  for (int i = 0; i <= 5000; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0)
        c[i][j] = 1;
      else
        c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
      c[i][j] %= 998244353LL;
    }
  }
  int n, k;
  string s;
  cin >> n >> k >> s;
  if (k == 0) {
    cout << "1\n";
    return 0;
  }
  long long int ans = 1LL, cnt = 0, pos = 0;
  bool first = 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') cnt++;
    if (cnt < k) continue;
    while (cnt != k && pos <= i) {
      pos++;
      if (s[pos - 1] == '1') cnt--;
    }
    int len = i - pos + 1;
    if (first) {
      ans += c[len][cnt] - 1;
    } else if (s[i] == '1') {
      ans += c[len - 1][cnt];
    } else {
      ans += c[len - 1][cnt - 1];
    }
    first = 0;
    ans %= 998244353LL;
  }
  cout << ans << '\n';
}
