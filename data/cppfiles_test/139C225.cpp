#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, T;
  cin >> t;
  for (T = 0; T < t; T++) {
    long long l, i;
    string s, s1, s2;
    cin >> s;
    l = s.size();
    for (i = 0; i < l / 2; i++) {
      s1.push_back(s[i]);
    }
    for (i = l / 2; s[i] != '\0'; i++) {
      s2.push_back(s[i]);
    }
    if (s1 == s2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
