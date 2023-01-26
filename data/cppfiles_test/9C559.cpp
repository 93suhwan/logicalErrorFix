#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    unordered_map<char, int> m;
    for (int i = 0; i < s.length(); i++) m[s[i]]++;
    int a = 0;
    int b = 0;
    set<char> st;
    for (int i = 0; i < s.length(); i++) {
      if (!st.count(s[i]) && m[s[i]] == 1)
        a++;
      else if (!st.count(s[i]) && m[s[i]] > 1)
        b++;
      st.insert(s[i]);
    }
    cout << (a / 2 + b) << '\n';
  }
  return 0;
}
