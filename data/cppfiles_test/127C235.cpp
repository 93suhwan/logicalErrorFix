#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
void solve() {
  string s1, p;
  cin >> s1 >> p;
  map<char, int> m;
  for (char x : s1) {
    m[x] += 1;
  }
  if (p != "abc") {
    sort(s1.begin(), s1.end());
    cout << s1 << "\n";
  } else {
    string ans = "";
    if (m.find('a') != m.end()) {
      for (int i = 0; i < m['a']; i++) {
        ans.append("a");
      }
    } else {
      sort(s1.begin(), s1.end());
      cout << s1 << "\n";
      return;
    }
    if (m.find('c') != m.end()) {
      for (int i = 0; i < m['c']; i++) {
        ans.append("c");
      }
    }
    if (m.find('b') != m.end()) {
      for (int i = 0; i < m['b']; i++) {
        ans.append("b");
      }
    }
    auto it = m.upper_bound('c');
    while (it != m.end()) {
      for (auto i = 0; i < (it->second); i++) {
        string po(1, it->first);
        ans.append(po);
      }
      it++;
    }
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
