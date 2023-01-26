#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using lld = long double;
template <typename T>
inline istream &operator>>(istream &CIN, vector<T> &a) {
  for (auto &first : a) CIN >> first;
  return CIN;
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  set<char> st;
  for (const auto &i : s) st.insert(i);
  if (n == 1) {
    if (s[0] == '?') s[0] = 'B';
  }
  if (st.size() == 1) {
    string temp;
    while (temp.size() <= s.size()) {
      temp.push_back('B');
      temp.push_back('R');
    }
    while (temp.size() > s.size()) {
      temp.pop_back();
    }
    cout << temp << '\n';
    return;
  }
  for (int j = 0; j < s.size(); j++) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != '?') {
        if (i - 1 >= 0 and s[i - 1] == '?') {
          if (s[i] == 'B')
            s[i - 1] = 'R';
          else
            s[i - 1] = 'B';
        }
        if (i + 1 < s.size() and s[i + 1] == '?') {
          if (s[i] == 'B')
            s[i + 1] = 'R';
          else
            s[i + 1] = 'B';
        }
      }
    }
  }
  cout << s << '\n';
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) solve();
}
