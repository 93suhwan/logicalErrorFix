#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf("%c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const unsigned int &x) { printf("%u", x); }
void _W(const int &x) { printf("%d", x); }
void _W(const long long &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
void E() {}
template <class T, class... U>
void E(const T &head, const U &...tail) {
  cerr << head << (sizeof...(tail) ? ' ' : '\n');
  E(tail...);
}
long long s, n, k;
void RunCase(int __Case = 0) {
  R(s, n, k);
  if (s < k || s < n) {
    W("NO");
    return;
  }
  if (s == k) {
    W("YES");
    return;
  }
  if (n == 1) {
    if (s == k)
      W("YES");
    else
      W("NO");
    return;
  }
  long long t = n - 1;
  int f = 0;
  t = s / t;
  for (long long b = 1; b <= min(t, 500ll); ++b) {
    long long a = s - b * (n - 1);
    if (a <= 0) break;
    if (k % b != 0 || b * (n - 1) < k) {
      if ((a > k) || (a < k && (k - a) % b != 0)) f = 1;
    }
  }
  if (f)
    W("NO");
  else
    W("YES");
}
int main() {
  int T = 1;
  R(T);
  for (int _i = 1; _i <= T; ++_i) RunCase(_i);
  return 0;
}
