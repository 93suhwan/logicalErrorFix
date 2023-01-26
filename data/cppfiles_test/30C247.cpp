#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
bool isPalindrome(string& s) {
  int n = (int)s.size();
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - i - 1]) return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, n, m;
  string s;
  char d;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    bool good = false;
    int ans = n + 1;
    for (int i = (0); i < (26); ++i) {
      m = 0;
      d = i + 'a';
      int l = 0, r = n - 1;
      while (l <= r) {
        if (s[l] == s[r]) {
          l++;
          r--;
        } else if (s[l] == d) {
          l++;
          m++;
        } else if (s[r] == d) {
          r--;
          m++;
        } else {
          m = n + 1;
          break;
        }
      }
      ans = min(ans, m);
    }
    if (ans == n + 1)
      cout << "-1\n";
    else
      cout << ans << "\n";
  }
}
