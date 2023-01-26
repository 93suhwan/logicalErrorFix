#include <bits/stdc++.h>
using namespace std;
template <typename T>
std::ostream &print(std::ostream &out, T const &val) {
  return (out << val << " ");
}
template <typename T1, typename T2>
std::ostream &print(std::ostream &out, std::pair<T1, T2> const &val) {
  return (out << "{" << val.first << " " << val.second << "} ");
}
template <template <typename, typename...> class TT, typename... Args>
std::ostream &operator<<(std::ostream &out, TT<Args...> const &cont) {
  cout << "{";
  for (auto elem : cont) print(out, elem);
  cout << "}";
  return out;
}
void solve() {
  long long x, n;
  cin >> x >> n;
  if (n % 4 == 0) {
    cout << x << "\n";
    return;
  }
  if (n % 4 == 2) {
    cout << x + 1 << "\n";
    return;
  }
  long long times = n / 4;
  if (n % 4 == 1) {
    long long ans;
    if (x % 2 == 0) {
      ans = x - n;
    } else {
      ans = x + n;
    }
    cout << ans << "\n";
    return;
  }
  long long minus = 4 * (times + 1);
  if (x % 2 == 0) {
    cout << (x + minus) << "\n";
  } else {
    cout << (x - minus) << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
