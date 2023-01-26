#include <bits/stdc++.h>
using namespace std;
namespace input {
template <class T>
void re(complex<T>& x);
template <class T1, class T2>
void re(pair<T1, T2>& p);
template <class T>
void re(vector<T>& a);
template <class T, size_t SZ>
void re(array<T, SZ>& a);
template <class T>
void re(T& x) {
  cin >> x;
}
void re(double& x) {
  string t;
  re(t);
  x = stod(t);
}
void re(long double& x) {
  string t;
  re(t);
  x = stold(t);
}
template <class Arg, class... Args>
void re(Arg& first, Args&... rest) {
  re(first);
  re(rest...);
}
template <class T>
void re(complex<T>& x) {
  T a, b;
  re(a, b);
  x = complex<long double>(a, b);
}
template <class T1, class T2>
void re(pair<T1, T2>& p) {
  re(p.first, p.second);
}
template <class T>
void re(vector<T>& a) {
  for (auto& i : a) re(i);
}
template <class T, size_t SZ>
void re(array<T, SZ>& a) {
  for (int i = 0; i < SZ; ++i) re(a[i]);
}
}  // namespace input
using namespace input;
using ll = long long;
using u64 = unsigned long long;
using u32 = unsigned;
namespace io {
void setIn(string s) { ifstream cin(s); }
void setOut(string s) { ofstream cout(s); }
void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  if (s.size()) setIn(s + ".inp"), setOut(s + ".out");
}
}  // namespace io
using namespace io;
constexpr int mod = 1e9 + 7;
int main() {
  setIO();
  srand(time(NULL));
  int n, m, k;
  cin >> n >> m >> k;
  int a[n][m];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  while (k--) {
    int x;
    cin >> x, --x;
    for (int i = 0; i < n; ++i) {
      if (a[i][x] == 1) {
        a[i][x] = 2;
        if (i == n - 1) break;
        x++;
        i--;
      } else if (a[i][x] == 3) {
        a[i][x] = 2;
        if (i == n - 1) break;
        x--;
        i--;
      }
    }
    cout << x + 1 << ' ';
  }
  return 0;
}
