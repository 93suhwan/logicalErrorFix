#include <bits/stdc++.h>
using namespace std;
const int64_t N = 1e6 + 6, M = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int64_t n, k, x, c = 0;
    cin >> n >> k >> x;
    x--;
    string s;
    cin >> s;
    vector<int64_t> v, a;
    for (int64_t i = 0; i < n; i++)
      if (s[i] == '*')
        c++;
      else if (c)
        v.push_back(k * c), c = 0;
    if (c) v.push_back(k * c);
    reverse(v.begin(), v.end());
    for (int64_t e : v) {
      a.push_back(x % (e + 1));
      x /= (e + 1);
    }
    reverse(a.begin(), a.end());
    for (int64_t i = 0, j = 0; i < n; i++)
      if (s[i] == '*') {
        if (!i || s[i - 1] != '*') {
          while (a[j]--) cout << 'b';
          j++;
        }
      } else
        cout << 'a';
    cout << '\n';
  }
}
