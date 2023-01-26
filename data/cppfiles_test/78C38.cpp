#include <bits/stdc++.h>
using namespace std;
const long long N = 2e3 + 10;
const long long M = 1e5 + 1;
const long long mod = 1e9 + 7;
const long long inf = 0x3f3f3f3f;
inline void run() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
inline void ReIO() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}
inline long long read() {
  long long x = 0, f = 0;
  char c = 0;
  while (c < '0' || c > '9') {
    f |= c == '-';
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return f ? -x : x;
}
void write(long long num) {
  if (num < 0) putchar('-'), num = -num;
  if (num > 9) write(num / 10);
  putchar(num % 10 + '0');
}
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
int bit[40];
int main() {
  run();
  int _;
  cin >> _;
  while (_--) {
    memset(bit, 0, sizeof bit);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      for (int j = 0; j < 31; j++) {
        if (x & (1 << j)) {
          bit[j]++;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < 31; i++) {
      ans = gcd(ans, bit[i]);
    }
    for (int i = 1; i <= n; i++) {
      if (ans % i == 0) {
        cout << i << ' ';
      }
    }
    cout << endl;
  }
  return 0;
}
