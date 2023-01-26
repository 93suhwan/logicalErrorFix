#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    set<char> st;
    for (long long i = 0; i < s.length(); i++) {
      st.insert(s[i]);
    }
    cout << min(st.size(), s.size() / 2) << endl;
  }
}
