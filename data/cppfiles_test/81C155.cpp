#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <class T, class S>
ostream& operator<<(ostream& o, pair<T, S> p) {
  return o << '(' << p.first << ", " << p.second << ')';
}
template <template <class, class...> class T, class... A>
typename enable_if<!is_same<T<A...>, string>(), ostream&>::type operator<<(
    ostream& o, T<A...> V) {
  o << '[';
  for (auto a : V) o << a << ", ";
  return o << ']';
}
template <long long int i, class... T>
typename enable_if<i == sizeof...(T)>::type _p(ostream& o, tuple<T...> t) {}
template <long long int i, class... T>
    typename enable_if < i<sizeof...(T)>::type _p(ostream& o, tuple<T...> t) {
  _p<i + 1>(o << get<i>(t) << ", ", t);
}
template <class... T>
ostream& operator<<(ostream& o, tuple<T...> t) {
  _p<0>(o << '(', t);
  return o << ')';
}
long long int M = 1000000007;
long long int inv(long long int a, long long int b) {
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}
long long int gcd(long long int x, long long int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
pair<long long int, long long int> neigh[4] = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int _t;
  cin >> _t;
  for (long long int _t1 = 0; _t1 < (_t); _t1++) {
    long long int n;
    cin >> n;
    long long int q;
    cin >> q;
    string s;
    cin >> s;
    long long int ar[n + 1];
    ar[0] = 0;
    for (long long int i = 0; i < (n); i++)
      ar[i + 1] = ((i % 2) ^ (s[i] == '+') ? 1 : -1) + ar[i];
    for (long long int i = 0; i < (q); i++) {
      long long int l;
      cin >> l;
      long long int r;
      cin >> r;
      if (ar[r] == ar[l - 1])
        cout << 0 << endl;
      else if ((ar[r] + ar[l - 1]) % 2)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    }
  }
}
