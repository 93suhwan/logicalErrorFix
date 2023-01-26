#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 3;
int a[maxn], c[maxn];
long long b[maxn][2];
string t;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < i; j++) {
      if (i + j - 10 >= 0)
        a[(i + j) % 10] += 2;
      else
        c[i + j] += 2;
    }
  }
  for (int i = 0; i < 10; i++) {
    if (i * 2 - 10 >= 0)
      a[(i * 2) % 10]++;
    else
      c[i * 2]++;
  }
  int test;
  cin >> test;
  while (test--) {
    cin >> t;
    reverse(t.begin(), t.end());
    b[0][0] = c[t[0] - '0'];
    b[0][1] = a[t[0] - '0'];
    if (t.size() >= 2) {
      b[1][0] = c[(int)t[1] - '0'];
      b[1][1] = a[(int)t[1] - '0'];
    }
    for (int i = 2; i <= t.size() - 1; i++) {
      if (t[i] == '0') {
        b[i][0] = c[0] * b[i - 2][0];
        b[i][1] = c[9] * b[i - 2][1] + a[0] * b[i - 2][0];
      } else {
        int k = t[i] - '0';
        b[i][0] = c[(k + 9) % 10] * b[i - 2][1] + c[k] * b[i - 2][0];
        b[i][1] = a[(k + 9) % 10] * b[i - 2][1] + a[k] * b[i - 2][0];
      }
    }
    long long ans = b[t.size() - 1][0];
    if (t.size() >= 2) ans *= b[t.size() - 2][0];
    ans -= 2;
    cout << ans << '\n';
  }
}
