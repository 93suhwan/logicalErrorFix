#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, y = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') y = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * y;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline long long getweishu(long long n) {
  long long ans = 0;
  while (n) {
    ans++;
    n /= 10;
  }
  return ans;
}
string int_to_string(long long x) {
  string ans = "";
  while (x) {
    ans += char('0' + x % 10);
    x /= 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
long long string_to_int(string s) {
  long long res = 0;
  for (auto it : s) {
    res *= 10, res += it - '0';
  }
  return res;
}
long long gcd(long long a, long long b) {
  long long d;
  while (b) {
    d = b;
    b = a % b;
    a = d;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long qpow(long long x, long long y) {
  long long ans = 1;
  for (; y > 0; y >>= 1) {
    if (y & 1) ans *= x;
    x *= x;
  }
  return ans;
}
long long qpow(long long x, long long y, int MOD) {
  long long ans = 1 % MOD;
  for (; y > 0; y >>= 1) {
    if (y & 1) ans = ans * x % MOD;
    x = x * x % MOD;
  }
  return ans;
}
int exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int d = exgcd(b, a % b, x, y);
  int temp = y;
  y = x - (a / b) * y, x = temp;
  return d;
}
const int N = 4e5 + 10, M = 20;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double pi = acos(-1.0);
long long n, t, m, x;
char ch[100][100];
int check[100][100];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    memset(check, 0, sizeof check);
    cin >> n >> m >> x;
    for (int i = (1); i <= (n); ++i) {
      for (int j = (1); j <= (m); ++j) {
        cin >> ch[i][j];
      }
    }
    bool flag = true;
    for (int i = n; i >= 1; i--) {
      for (int j = (1); j <= (m); ++j) {
        if (ch[i][j] != '*') continue;
        int cnt = 0;
        while (ch[i - cnt][j - cnt] == '*' && ch[i - cnt][j + cnt] == '*')
          cnt++;
        if (cnt - 1 < x) flag = false;
        if (flag == 0 && check[i][j] == 1) {
          flag = true;
          continue;
        }
        if (flag == false) break;
        for (int k = 0; k < cnt; k++) {
          check[i - k][j - k] = 1, check[i - k][j + k] = 1;
        }
      }
      if (flag == false) break;
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
