#include <bits/stdc++.h>
using namespace std;
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
  long long ans = 1;
  for (; y > 0; y >>= 1) {
    if (y & 1) ans = ans * x % MOD;
    x = x * x % MOD;
  }
  return ans;
}
void exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  exgcd(b, a % b, x, y);
  int temp = y;
  y = x - (a / b) * y, x = temp;
  return;
}
int downcheck(int l, int r) {
  while (l < r) {
    int mid = l + r >> 1;
    if ("check(mid)")
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}
int upcheck(int l, int r) {
  while (l < r) {
    int mid = l + r + 1 >> 1;
    if ("check(mid)")
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}
int doublecheck(int l, int r) {
  while (r - l > 1e-8) {
    int mid = (l + r) >> 1;
    if ("check(mid)")
      l = mid;
    else
      r = mid;
  }
  return l;
}
const int N = 4e5 + 10, M = 20;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double pi = acos(-1.0);
int n, t, m, x;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    string s1, s2;
    cin >> s1 >> s2;
    string s[505];
    int len1 = s1.size();
    int len2 = s2.size();
    for (int i = 0; i < len1; i++) {
      for (int j = i; j < len1; j++) {
        s[i] += s1[j];
      }
      for (int j = len1 - 2; j >= 0; j--) {
        s[i] += s1[j];
      }
    }
    int flag;
    for (int i = 0; i < len1; i++) {
      flag = 0;
      int len = s[i].size();
      int cnt = 0;
      for (int j = 0; j < len; j++) {
        if (s[i][j] == s2[cnt]) {
          cnt++;
          if (cnt == len2) break;
        }
      }
      if (cnt == len2) {
        flag = 1;
        break;
      }
    }
    if (flag == 1)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
