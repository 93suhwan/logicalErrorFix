#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  sort(v.begin(), v.end());
  c = v[2];
  b = v[1];
  a = v[0];
  if ((count(v.begin(), v.end(), a) == 2)) {
    if (c % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else if ((count(v.begin(), v.end(), c) == 2)) {
    if (a % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else {
    if (c == (a + b))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
