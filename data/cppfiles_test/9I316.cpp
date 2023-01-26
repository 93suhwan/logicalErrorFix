#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    map<char, long long int> mp;
    string s;
    cin >> s;
    long long int i = 0, e = 0, d = 0, c = 0, l = 0, p = 0, m = 0;
    for (i = 0; i < s.length(); i++) {
      mp[s[i]]++;
    }
    for (auto x : mp) {
      if (x.second == 1)
        e++;
      else if (x.second == 2)
        d++;
      else
        c++;
    }
    p = e / 2;
    c = c * 3;
    m = c / 2;
    l = d + p + m;
    cout << l << endl;
  }
}
