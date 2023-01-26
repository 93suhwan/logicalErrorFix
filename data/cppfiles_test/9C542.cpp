#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    map<char, int> m;
    long long cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < s.length(); ++i) {
      m[s[i]]++;
    }
    for (auto c : m) {
      if (c.second == 1)
        cnt1++;
      else if (c.second > 1)
        cnt2 += 2;
    }
    cout << cnt1 / 2 + cnt2 / 2 << endl;
  }
  return 0;
}
