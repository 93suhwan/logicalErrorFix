#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
vector<pair<long long, long long>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
long long mod = 1e9 + 7;
void solve() {
  long long x, y;
  cin >> x >> y;
  string ans, a = to_string(x), s = to_string(y);
  reverse(a.begin(), a.end()), reverse(s.begin(), s.end());
  long long j = 0;
  for (long long i = 0; i < a.size(); i++) {
    if (a[i] > s[j]) {
      long long c = a[i] - '0';
      string temp;
      if (j + 1 < s.size())
        temp = s.substr(j, 2);
      else {
        cout << -1 << endl;
        return;
      }
      reverse(temp.begin(), temp.end());
      long long d = stoll(temp);
      if (d - c > 9 || d - c < 0) {
        cout << -1 << endl;
        return;
      }
      ans.push_back(d - c + '0');
      j += 2;
    } else {
      ans.push_back(s[j] - a[i] + '0');
      j++;
    }
  }
  if (j < s.size()) ans += s.substr(j);
  reverse(ans.begin(), ans.end());
  cout << stoll(ans) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long test = 1;
  cin >> test;
  while (test--) solve();
}
