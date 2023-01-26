#include <bits/stdc++.h>
using namespace std;
long long res = 0, n;
void solve(long long s1, long long s2, vector<char> v) {
  if (res == n) return;
  if (s1 == 0 && s2 == 0) {
    if (res == n) return;
    for (auto el : v) {
      cout << el;
    }
    cout << endl;
    ++res;
    return;
  }
  if (s1 != 0) {
    v.push_back('(');
    solve(s1 - 1, s2, v);
    v.pop_back();
  }
  if (s2 > s1) {
    v.push_back(')');
    solve(s1, s2 - 1, v);
  }
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    res = 0;
    cin >> n;
    solve(n, n, {});
  }
}
