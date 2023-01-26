#include <bits/stdc++.h>
using namespace std;
long long n, m;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TC;
  cin >> TC;
  while (TC--) {
    string s;
    cin >> s;
    map<int, int> mp;
    int mx = 0, o = 0, t = 1, co = 1, ct = 0;
    mp[0] = 1;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] != s[i - 1]) {
        if (o) {
          mp[i] = 2;
          ct++;
          mx = max(mx, ct);
          t = 1;
          o = 0;
        } else {
          mp[i] = 1;
          co++;
          mx = max(mx, co);
          t = 0;
          o = 1;
        }
      } else {
        if (mp[i - 1] == 0) {
          if (o) {
            mp[i] = 2;
            ct++;
            mx = max(mx, ct);
            t = 1;
            o = 0;
          } else {
            mp[i] = 1;
            co++;
            mx = max(mx, co);
            t = 0;
            o = 1;
          }
        }
      }
    }
    cout << max(0, mx - 1) << '\n';
  }
}
