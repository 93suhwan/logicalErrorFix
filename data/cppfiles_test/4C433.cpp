#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << "=" << a << " ! ";
  err(++it, args...);
}
const long long N = 5e6 + 7, M = 1e9 + 7, inf = 2e18;
long long tt, p;
void sex() {
  if (p % 4 == 1) {
    cout << 2 << " " << 4 << "\n";
  } else {
    cout << 2 << " " << (p - 1) / 2 << "\n";
  }
}
int main() {
  cin >> tt;
  while (tt--) {
    cin >> p;
    sex();
  }
}
