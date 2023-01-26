#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    set<char> st;
    for (int i = 0; i < s.length(); i++) st.insert(s[i]);
    int tot = s.length();
    int unq = st.size();
    int k = 0;
    int ans = 0;
    if (tot % 2 == 0)
      k = tot / 2;
    else
      k = (tot - 1) / 2;
    if (unq > k)
      ans = tot / 2;
    else
      ans = unq;
    if (tot == 1) ans = 0;
    cout << ans << '\n';
  }
  return 0;
}
