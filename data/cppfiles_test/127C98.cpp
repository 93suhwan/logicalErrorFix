#include <bits/stdc++.h>
using namespace std;
const int xn = 2e5 + 10;
template <typename T>
T gcd(T a, T b) {
  if (a % b) return gcd(b, a % b);
  return b;
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
bool isSubsequence(string &s, string &t) {
  if (t.empty()) return true;
  int i = 0;
  int j = 0;
  while (i < s.size() && j < t.size()) {
    if (s[i] == t[j]) j++;
    i++;
  }
  return j == t.size();
}
void solve() {
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  vector<long long int> frequency(26, 0);
  for (char c : s) frequency[c - 'a']++;
  if (t != "abc" || !frequency[0] || !frequency[1] || !frequency[2]) {
    cout << s << "\n";
  } else {
    while (frequency[0]--) cout << 'a';
    while (frequency[2]--) cout << 'c';
    while (frequency[1]--) cout << 'b';
    for (int i = 3; i < frequency.size(); i++) {
      while (frequency[i]--) cout << char('a' + i);
    }
    cout << "\n";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
