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
int p1, p2;
string x1;
string x2;
void Test() {
  cin >> x1 >> p1;
  cin >> x2 >> p2;
  if (x1.size() + p1 < x2.size() + p2)
    cout << '<';
  else if (x1.size() + p1 > x2.size() + p2)
    cout << '>';
  else {
    int mn = max(x1.size(), x2.size());
    while (x1.size() != mn) x1 += '0';
    while (x2.size() != mn) x2 += '0';
    bool found = 0;
    for (int i = 0; i < mn; i++) {
      if (x1[i] < x2[i]) {
        cout << '<';
        found = 1;
        break;
      } else if (x1[i] > x2[i]) {
        cout << '>';
        found = 1;
        break;
      }
    }
    if (!found) {
      cout << '=';
    }
  }
  cout << '\n';
}
signed main() {
  int q;
  cin >> q;
  while (q--) Test();
  return 0;
}
