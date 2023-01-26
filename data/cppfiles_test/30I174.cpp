#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100, inf = 0x3f3f3f3f, mod = 1e9 + 7, M = 1e6 + 1000;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long sp(long long a, long long b, long long d) {
  if (!b) return 1;
  return b % 2 ? sp(a * a, b / 2, d) * a % d : sp(a * a, b / 2, d);
}
long long sp1(long long a, long long b) {
  if (!b) return 1;
  return b % 2 ? sp1(a * a, b / 2) * a : sp1(a * a, b / 2);
}
long long lowbit(long long x) { return x & (-x); }
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  } else {
    long long d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
  }
}
long long t, n;
char str[N];
long long ck(char s) {
  long long l = 1, r = n, x = 0;
  while (l <= r) {
    if (str[l] == str[r]) {
      l++;
      r--;
    } else {
      if (str[l] == s) {
        l++;
        x++;
      } else if (str[r] == s) {
        r--;
        x++;
      } else {
        return -1;
      }
    }
  }
  return x;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    scanf("%s", str + 1);
    long long w = 0, ans;
    for (int i = 1; i <= n / 2; i++) {
      if (str[i] != str[n - i + 1]) {
        w = i;
        break;
      }
    }
    if (!w) {
      ans = 0;
    } else {
      ans = ck(str[w]);
      if (ans == -1) {
        ans = ck(str[n - w + 1]);
      }
    }
    cout << ans << endl;
  }
}
