#include <bits/stdc++.h>
using namespace std;
long long check(long long n, long long m, long long x, long long y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}
void pr() { cout << '\n'; }
template <class A, class... B>
void pr(const A &a, const B &...b) {
  cout << a << (sizeof...(b) ? " " : "");
  pr(b...);
}
template <class A>
void PR(A a, long long n) {
  for (long long i = (long long)(0); i < (long long)(n); i++)
    cout << (i ? " " : "") << a[i];
  cout << '\n';
}
const long long MAX = 1e9 + 7, MAXL = 1LL << 61,
                dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1},
                dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
void Main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n = 7;
    long long a[n];
    for (long long i = (long long)(0); i < (long long)(n); i++) cin >> a[i];
    for (long long i = (long long)(0); i < (long long)(n); i++) {
      for (long long j = (long long)(i + 1); j < (long long)(n); j++) {
        for (long long k = (long long)(j + 1); k < (long long)(n); k++) {
          if (a[i] + a[j] + a[k] == a[n - 1]) {
            pr(a[i], a[j], a[k]);
            goto end;
          }
        }
      }
    }
  end:;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  Main();
  return 0;
}
