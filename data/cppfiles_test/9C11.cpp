#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void amin(T &a, U b) {
  a = (a > b ? b : a);
}
template <typename T, typename U>
inline void amax(T &a, U b) {
  a = (a > b ? a : b);
}
void solve() {
  string s;
  cin >> s;
  int n = ((int)s.size());
  vector<int> freq(26, 0);
  for (char c : s) freq[c - 'a']++;
  int ones = 0;
  int ans = 0;
  for (int i = 0; i < 26; ++i) {
    if (freq[i] > 1) ++ans;
    if (freq[i] == 1) {
      ++ones;
      if (ones == 2) ones = 0, ++ans;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tests = 1;
  cin >> tests;
  while (tests--) {
    solve();
  }
}
