#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto element : v) {
    os << element << ' ';
  }
  return os;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  ;
  if (n % 2 == 0) {
    cout << "YES" << '\n';
    return;
  }
  long long flag = 0;
  for (long long i = 0; i < n; i++) {
    flag = 1;
    if (v[i] >= v[i + 1]) {
      flag = 0;
      break;
    }
  }
  if (flag)
    cout << "NO" << '\n';
  else
    cout << "YES" << '\n';
}
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
