#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  fastio();
  int T;
  cin >> T;
  while (T--) {
    string s;
    string q;
    cin >> s;
    cin >> q;
    int cur = 0;
    long long int res = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == q[0]) {
        cur = i;
        break;
      }
    }
    for (int i = 1; i < q.size(); i++) {
      for (int j = 0; j < s.size(); j++) {
        if (q[i] == s[j]) {
          res += abs(cur - j);
          cur = j;
        }
      }
    }
    cout << res << '\n';
  }
}
