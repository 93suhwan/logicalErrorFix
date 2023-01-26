#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)((1e5) + 100);
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
void prl(int x) { cout << x << "\n"; }
const int N = (int)(1 * 1e6 + 10);
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == '1') {
      int i = 1;
      for (; i < n; i++) {
        if (s[i] == '0') break;
      }
      if (i == n) {
        cout << 1 << " " << n / 2 << " " << 2 << " " << n / 2 + 1 << "\n";
      } else {
        if (i >= n / 2)
          cout << 1 << " " << i + 1 << " " << 1 << " " << i << "\n";
        else
          cout << i + 1 << " " << n << " " << i + 2 << " " << n << "\n";
      }
    } else {
      cout << 1 << " " << n / 2 + 1 << " " << 2 << " " << n / 2 + 1 << "\n";
    }
  }
}
