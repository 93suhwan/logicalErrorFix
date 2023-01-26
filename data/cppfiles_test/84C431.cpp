#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10, mod = 1e9 + 9;
const int maxn = 500010;
const long double eps = 1e-5;
const int EPS = 500 * 500;
template <typename T>
void read(T &x) {
  x = 0;
  char ch = getchar();
  long long first = 1;
  while (!isdigit(ch)) {
    if (ch == '-') first *= -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= first;
}
template <typename T, typename... Args>
void read(T &first, Args &...args) {
  read(first);
  read(args...);
}
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    int n, second;
    cin >> n >> second;
    cout << second / (n / 2 + 1) << '\n';
  }
}
