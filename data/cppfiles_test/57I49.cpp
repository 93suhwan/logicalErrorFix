#include <bits/stdc++.h>
namespace FastRead {
char __buff[5000];
int __lg = 0, __p = 0;
char nc() {
  if (__lg == __p) {
    __lg = fread(__buff, 1, 5000, stdin);
    __p = 0;
    if (!__lg) return EOF;
  }
  return __buff[__p++];
}
template <class T>
void read(T& __x) {
  T __sgn = 1;
  char __c;
  while (!isdigit(__c = nc()))
    if (__c == '-') __sgn = -1;
  __x = __c - '0';
  while (isdigit(__c = nc())) __x = __x * 10 + __c - '0';
  __x *= __sgn;
}
}  // namespace FastRead
using namespace FastRead;
using namespace std;
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const long double PI = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long n, s, k;
void Test() {
  cin >> s >> n >> k;
  if (s == k)
    cout << "YES\n";
  else if (s < k)
    cout << "NO\n";
  else {
    long long last = s / k * k;
    long long lastSize = s - last;
    long long lastGroupSize = last / k;
    long long befSize = k - (lastSize + 1);
    long long befGroupSize = lastGroupSize;
    long long valid = lastSize * (lastGroupSize + 1) / 2 +
                      befSize * (befGroupSize + 1) / 2 +
                      (lastGroupSize + 2) / 2;
    if (valid > n)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
signed main() {
  int q;
  cin >> q;
  while (q--) Test();
  return 0;
}
