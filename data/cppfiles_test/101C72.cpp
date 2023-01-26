#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
template <class T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
T lcm(T a, T b) {
  return (b / gcd(a, b)) * a;
}
void solve() {
  int n;
  cin >> n;
  vector<pair<char, int>> vec;
  vector<int> a(n);
  for (int i = 0; i < (n); i++) {
    cin >> a[i];
  }
  char x;
  for (int i = 0; i < (n); i++) {
    cin >> x;
    vec.push_back(make_pair(x, a[i]));
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < (n); i++) {
    if (vec[i].first == 'B') {
      if (vec[i].second < (i + 1)) {
        cout << "NO" << endl;
        return;
      }
    } else {
      if (vec[i].second > (i + 1)) {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
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
