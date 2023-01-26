#include <bits/stdc++.h>
using namespace std;
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first + a.second >= b.second + b.first) {
    return false;
  }
  return true;
}
int main() {
  cin.tie(nullptr);
  cout.tie(NULL);
  cin.sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long i, c1 = 0, c2 = 0;
    for (i = 0; i < s.size() - 1; i++) {
      if (s[i] == 'a' and s[i + 1] == 'b') {
        c1++;
      }
      if (s[i] == 'b' and s[i + 1] == 'a') {
        c2++;
      }
    }
    if (c1 == c2) {
      cout << s << "\n";
    } else {
      if (s[s.size() - 1] == 'a') {
        s[s.size() - 1] = 'b';
      } else {
        s[s.size() - 1] = 'a';
      }
      cout << s << "\n";
    }
  }
  return 0;
}
