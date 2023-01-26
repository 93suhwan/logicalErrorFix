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
  set<char> s1, s2;
  for (int i = 0; i < n; ++i) {
    if (((int)s1.size()) == ((int)s2.size())) {
      if (s1.find(s[i]) == s1.end())
        s1.insert(s[i]);
      else
        s2.insert(s[i]);
    } else {
      if (s2.find(s[i]) == s2.end())
        s2.insert(s[i]);
      else
        s1.insert(s[i]);
    }
  }
  cout << min(((int)s1.size()), ((int)s2.size())) << '\n';
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
