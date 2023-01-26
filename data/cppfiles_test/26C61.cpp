#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool compare(pair<long long int, long long int> a,
             pair<long long int, long long int> b) {
  if (a.first > b.first) return true;
  if (a.first == b.first) return a.second < b.second;
  return false;
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
void solve() {
  string s;
  cin >> s;
  int mi = 10;
  int n = s.size();
  int goal1 = 0, goal2 = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 1) {
      if (s[i - 1] == '1' || s[i - 1] == '?') goal1++;
      int left = (n - i + 1) / 2;
      if (goal1 > left + goal2) {
        mi = i;
        break;
      }
    } else {
      if (s[i - 1] == '1') goal2++;
      int left = (n - i) / 2;
      if (goal1 > goal2 + left) {
        mi = i;
        break;
      }
    }
  }
  goal1 = 0;
  goal2 = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 1) {
      if (s[i - 1] == '1') goal1++;
      int left = (n - i - 1) / 2;
      if (goal1 + left < goal2) {
        mi = min(mi, i);
        break;
      }
    } else {
      if (s[i - 1] == '1' || s[i - 1] == '?') goal2++;
      int left = (n - i) / 2;
      if (goal1 + left < goal2) {
        mi = min(mi, i);
        break;
      }
    }
  }
  cout << mi << "\n";
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
