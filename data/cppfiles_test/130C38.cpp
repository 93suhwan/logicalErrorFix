#include <bits/stdc++.h>
using namespace std;
const int maxdouble = 0x7f;
const int mindouble = 0xfe;
const long long mod = 998244353;
double jz(int n) {
  double ans = 1;
  for (int i = 1; i <= n; i++) {
    ans *= i;
  }
  return ans;
}
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
    if (ch == -1) return 0;
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
inline long long check(long long x) {
  long long s = sqrt(x * 2) + (1e-12);
  if ((s * (s + 1) / 2) == x) return s;
  return -1;
}
long long int ksm(long long int a, long long int b) {
  long long int ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
inline long long mul(long long a, long long b, long long mod) {
  return (a * b - (long long)((long double)a / mod * b) * mod + mod) % mod;
}
const int maxn = 1e4 + 500;
long long num[maxn];
long long solve(long long t1, long long t2, long long t3) {
  printf("? %lld %lld %lld\n", t1, t2, t3);
  fflush(stdout);
  long long a;
  scanf("%lld", &a);
  fflush(stdout);
  return a;
}
int main(void) {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int cnt = n / 3;
    for (int i = 0; i < cnt; i++) {
      num[i] = solve(i * 3 + 1, i * 3 + 2, i * 3 + 3);
    }
    int z1 = 0, z2 = 0;
    for (int i = 1; i < cnt; i++)
      if ((num[i] ^ num[i - 1]) == 1) {
        long long flag = num[i - 1];
        long long t = solve((i - 1) * 3 + 2, (i - 1) * 3 + 3, i * 3 + 1);
        if (t != flag) {
          if (flag == 1) {
            z1 = (i - 1) * 3 + 1;
            z2 = i * 3 + 1;
          } else {
            z2 = (i - 1) * 3 + 1;
            z1 = i * 3 + 1;
          }
          break;
        } else
          flag = t;
        t = solve((i - 1) * 3 + 3, i * 3 + 1, i * 3 + 2);
        if (t != flag) {
          if (flag == 1) {
            z1 = (i - 1) * 3 + 2;
            z2 = i * 3 + 2;
          } else {
            z2 = (i - 1) * 3 + 2;
            z1 = i * 3 + 2;
          }
          break;
        } else
          flag = t;
        t = num[i];
        if (t != flag) {
          if (flag == 1) {
            z1 = (i - 1) * 3 + 3;
            z2 = i * 3 + 3;
          } else {
            z2 = (i - 1) * 3 + 3;
            z1 = i * 3 + 3;
          }
          break;
        }
      }
    vector<long long> q;
    for (int i = 0; i < cnt; i++) {
      if (num[i] == 1) {
        long long a, b;
        a = solve(z2, i * 3 + 1, i * 3 + 2);
        b = solve(z2, i * 3 + 2, i * 3 + 3);
        if (a == 1 && b == 0)
          q.push_back(i * 3 + 3);
        else if (a == 0 && b == 0)
          q.push_back(i * 3 + 2);
        else if (a == 0 && b == 1)
          q.push_back(i * 3 + 1);
      } else {
        long long a, b;
        a = solve(z1, i * 3 + 1, i * 3 + 2);
        b = solve(z1, i * 3 + 2, i * 3 + 3);
        if (a == 1 && b == 0) {
          q.push_back(i * 3 + 2);
          q.push_back(i * 3 + 3);
        } else if (a == 1 && b == 1) {
          q.push_back(i * 3 + 1);
          q.push_back(i * 3 + 3);
        } else if (a == 0 && b == 1) {
          q.push_back(i * 3 + 1);
          q.push_back(i * 3 + 2);
        } else {
          q.push_back(i * 3 + 1);
          q.push_back(i * 3 + 2);
          q.push_back(i * 3 + 3);
        }
      }
    }
    printf("! %d", q.size());
    for (int i = 0; i < q.size(); i++) printf(" %lld", q[i]);
    printf("\n");
    fflush(stdout);
  }
  return 0;
}
