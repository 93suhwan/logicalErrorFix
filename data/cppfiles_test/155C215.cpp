#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 2e5 + 10;
void test_case() {
  long long n;
  cin >> n;
  vector<long long> v(n), pos(n + 1), res(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    pos[v[i]] = i;
  }
  string s;
  cin >> s;
  vector<int> a, b;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      a.push_back(v[i]);
    } else {
      b.push_back(v[i]);
    }
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  int x = 0, y = 0;
  for (int i = n; i > 0; i--) {
    if (x < a.size()) {
      res[pos[a[x++]]] = i;
    } else {
      res[pos[b[y++]]] = i;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << res[i] << ' ';
  }
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    test_case();
  }
  return 0;
}
