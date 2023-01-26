#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int let[30] = {};
    int cnt_red = 0, cnt_gr = 0, com = 0;
    for (auto u : s) {
      let[u - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (let[i] > 1)
        com++;
      else if (cnt_red <= cnt_gr and let[i] > 0)
        cnt_red++;
      else if (let[i] > 0)
        cnt_gr++;
    }
    cout << min(cnt_gr, cnt_red) + com << "\n";
  }
}
