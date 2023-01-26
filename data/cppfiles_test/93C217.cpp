#include <bits/stdc++.h>
using namespace std;
using lld = signed long long int;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << ' ';
  err(++it, args...);
}
lld solve() {
  lld n, k;
  cin >> n >> k;
  lld pathedComputers = 1, hours = 0;
  while (pathedComputers < n) {
    if (pathedComputers < k) {
      pathedComputers *= 2;
      hours++;
    } else {
      hours += (n - pathedComputers + k - 1) / k;
      break;
    }
  }
  return hours;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << "\n";
  }
  return 0;
}
