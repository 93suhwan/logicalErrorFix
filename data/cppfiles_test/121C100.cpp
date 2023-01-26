#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline namespace {}
void solve(const int __test__ = -1) {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  int cnt = INT_MAX;
  {
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        if (a[i] == '1')
          c1++;
        else
          c2++;
      }
    }
    if (c1 == c2 + 1) cnt = min(cnt, c1 + c2);
  }
  {
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        if (a[i] == '1')
          c1++;
        else
          c2++;
      }
    }
    if (c1 == c2) cnt = min(cnt, c1 + c2);
  }
  cout << (cnt != INT_MAX ? cnt : -1) << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int __T = 1;
  cin >> __T;
  for (int __t = 0; __t < __T; __t++) solve(__t);
  return 0;
}
