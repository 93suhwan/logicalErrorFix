#include <bits/stdc++.h>
using namespace std;
constexpr long long int mod = 1e9 + 7;
template <typename T, typename U>
void operator%=(T& a, const U& m) {
  if (abs(a) >= m) a %= m;
  if (a < 0) a += m;
}
template <typename T, typename U>
T operator%(T& a, const U& m) {
  T b = a;
  b %= m;
  return b;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& a) {
  for (int i = int(0); i < int((int)a.size()); i++) out << a[i] << " ";
  out << "\n";
  return out;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
  for (int i = int(0); i < int((int)a.size()); i++) in >> a[i];
  return in;
}
template <typename T, typename U>
T pow2(const T& x, const U& y) {
  T res = 1, X = x;
  U Y = y;
  while (Y > 0) {
    if (Y & 1) res *= X;
    Y >>= 1;
    X *= X;
    X %= mod;
    res %= mod;
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  char c;
  cin >> c;
  string second;
  cin >> second;
  long long int C = count(second.begin(), second.end(), c);
  if (C == n) {
    cout << "0\n";
    return;
  }
  if (C == n - 1 || second.back() == c) {
    cout << "1\n" << n << "\n";
    return;
  }
  bool ar[n + 1];
  for (int i = 1; i <= n; i++)
    if (second[i - 1] == c)
      ar[i] = 0;
    else
      ar[i] = 1;
  for (int i = 1; i <= n; i++) {
    if (n % i != 0) {
      int res = 0;
      for (int j = i; j <= n; j += i) {
        if (ar[j]) res++;
      }
      if (res == 0) {
        cout << 1 << "\n" << i << "\n";
        return;
      }
    }
  }
  cout << 2 << "\n" << n << " " << n - 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
