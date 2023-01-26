#include <bits/stdc++.h>
using namespace std;
const long long LINF = 1E18;
const int INF = 1E9;
const int MOD = 1E9 + 7;
const double pi = acos(-1);
const int N = 1;
int t = 1;
long long n;
string a, b, s;
void Input() { cin >> a >> s; }
void Solve() {
  reverse(a.begin(), a.end());
  reverse(s.begin(), s.end());
  int j = 0;
  string b = "";
  for (int i = 0; i < a.size(); i++) {
    if (j >= s.size()) {
      cout << -1 << endl;
      return;
    }
    if (a[i] <= s[j])
      b += (char)(s[j] - a[i] + '0');
    else {
      if (j + 1 == s.size() || s[j + 1] != '1') {
        cout << -1 << endl;
        return;
      }
      int tmp = s[j] - '0' + 10;
      tmp -= a[i] - '0';
      if (tmp <= 9)
        b += (char)(tmp + '0');
      else {
        cout << -1 << endl;
        return;
      }
      j++;
    }
    j++;
  }
  while (j < s.size()) {
    b += s[j++];
  }
  while (b.size() && b.back() == '0') b.pop_back();
  reverse(b.begin(), b.end());
  if (b.size())
    cout << b << endl;
  else
    cout << 0 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("test"
            ".inp",
            "r")) {
    freopen(
        "test"
        ".inp",
        "r", stdin);
    freopen(
        "test"
        ".out",
        "w", stdout);
  }
  cin >> t;
  while (t--) {
    Input();
    Solve();
  }
  return 0;
}
