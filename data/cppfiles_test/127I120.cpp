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
  bool ans = isSubsequence(s, t);
  if (!ans) {
    cout << s << "\n";
    return;
  }
  char c = t[1];
  int index1 = -1;
  int index2 = -1;
  bool flag = false;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == c && !flag) {
      index1 = i;
      flag = true;
    }
    if (s[i] != c && flag) {
      index2 = i;
      break;
    }
  }
  if (index1 != -1 && index2 != -1) swap(s[index1], s[index2]);
  cout << s << "\n";
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
