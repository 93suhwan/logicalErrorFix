#include <bits/stdc++.h>
using namespace std;
template <class Iter, class Value>
struct StreamRange {
  Iter it;
  unsigned int n;
  StreamRange(Iter it, unsigned int n) : it(it), n(n) {}
  friend ostream& operator<<(ostream& os, StreamRange const& r) {
    copy_n(r.it, r.n, ostream_iterator<Value>(os, " "));
    return os;
  }
  friend istream& operator>>(istream& is, StreamRange const& r) {
    copy_n(istream_iterator<Value>(is), r.n, r.it);
    return is;
  }
};
template <class Value, class Iter>
StreamRange<Iter, Value> range(Iter it, unsigned int n) {
  return StreamRange<Iter, Value>(it, n);
}
void assume(int expr) {
  if (!expr) __builtin_unreachable();
}
constexpr unsigned int N = 2e5 + 10;
unsigned int n, A[N], B[N];
unsigned long long Sl, Sr;
string s;
void apply(unsigned int x, char c) {
  cout << x << ' ' << c << '\n';
  (c == 'L' ? Sl : Sr) += x;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> range<unsigned int>(A, n) >> s;
  sort(A, A + n);
  unsigned int p = n;
  for (unsigned int i = n; i-- > 0;) {
    if (i == 0 || s[i - 1] != s[i]) {
      B[i] = A[--p];
    }
  }
  for (unsigned int i = 0; i < n; i++) {
    if (B[i]) {
      apply(B[i], s[i]);
    } else {
      unsigned int x = A[--p];
      if (s[i] == 'L') {
        if (Sr + x < Sl)
          apply(x, 'R');
        else
          apply(x, 'L');
      } else {
        if (Sl + x < Sr)
          apply(x, 'L');
        else
          apply(x, 'R');
      }
    }
  }
  return 0;
}
