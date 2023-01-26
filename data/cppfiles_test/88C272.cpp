#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target( \
    "fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
template <class T>
string to_string(vector<T> &vec) {
  std::ostringstream vts;
  if (!vec.empty()) {
    std::copy(vec.begin(), vec.end() - 1,
              std::ostream_iterator<int>(vts, ", "));
    vts << vec.back();
  }
  return "[" + vts.str() + "]";
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> people(n * m);
  for (long long int i = 0; i < n * m; i++) {
    cin >> people[i];
  }
  vector<int> sp(people.begin(), people.end());
  sort(sp.begin(), sp.end());
  int ans = 0;
  for (long long int i = n * m - 1; i >= 0; i--) {
    auto b = sp.begin() +
             ceil((sp.rend() - find(sp.rbegin(), sp.rend(), people[i])) /
                  (long double)m) *
                 m;
    auto loc = find(b - m, b, people[i]);
    for (auto it = b - m; it != loc; it++) {
      if (*it != 0) ans++;
    }
    *loc = 0;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(20);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
