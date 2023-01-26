#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
const int maxn = 2e5 + 100;
const int mod = 1e9 + 7;
const int N = 1010;
long long ksm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long temp;
  cin >> temp;
  while (temp--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long num = n / 2;
    if (s.find('0', 0) == -1) {
      cout << 1 << ' ' << num << ' ' << 2 << ' ' << num + 1 << '\n';
    } else {
      long long pos = s.find('0', 0) + 1;
      if (pos == num) {
        long long ppp = s.find('0', pos);
        if (ppp == -1)
          cout << 1 << ' ' << num << ' ' << num << ' ' << num + num - 1 << '\n';
        else {
          ppp++;
          cout << 1 << ' ' << ppp - 1 << ' ' << 1 << ' ' << ppp << '\n';
        }
      } else if (pos > num) {
        cout << 1 << ' ' << pos - 1 << ' ' << 1 << ' ' << pos << '\n';
      } else if (pos < num) {
        cout << pos << ' ' << n << ' ' << pos + 1 << ' ' << n << '\n';
      }
    }
  }
  return 0;
}
