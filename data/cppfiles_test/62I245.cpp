#include <bits/stdc++.h>
using namespace std;
bool check(string s) {
  long long int count = 0;
  for (int i = 1; i < s.length(); i++) {
    if (s[i] == s[i - 1]) count++;
  }
  return count;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t1, i, j;
  cin >> t1;
  while (t1--) {
    long long int n;
    cin >> n;
    string s, s1, s2;
    cin >> s;
    s1 = s;
    s2 = s;
    if (s[0] == '?') s1[0] = 'B';
    for (i = 1; i < n; i++) {
      if (s1[i] == '?') {
        if (s1[i - 1] == 'B')
          s1[i] = 'R';
        else
          s1[i] = 'B';
      }
    }
    if (s[0] == '?') s2[0] = 'R';
    for (i = 1; i < n; i++) {
      if (s2[i] == '?') {
        if (s2[i - 1] == 'B')
          s2[i] = 'R';
        else
          s2[i] = 'B';
      }
    }
    if (check(s1) <= check(s2))
      cout << s1 << "\n";
    else
      cout << s2 << "\n";
  }
  return (0);
}
