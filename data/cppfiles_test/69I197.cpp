#include <bits/stdc++.h>
using namespace std;
int inf = 1e9, mod = 1e9 + 7;
inline int mn(int x, int y) { return (x > y) ? y : x; }
int main() {
  srand(time(nullptr));
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int st2 = 1;
  vector<string> stt;
  while (st2 <= 1e9) {
    stt.push_back(to_string(st2));
    st2 *= 2;
  }
  int test;
  cin >> test;
  while (test--) {
    int i, j, k;
    string n;
    cin >> n;
    int ans = inf;
    for (i = 0; i < stt.size(); i++) {
      string st = stt[i];
      for (j = 0; j <= min(st.length(), n.length()); j++) {
        int it = 0;
        for (k = 0; it < j && k < n.length(); k++)
          if (n[k] == st[it]) it++;
        if (it < j) break;
      }
      j--;
      ans = mn(ans, n.length() - j + st.length() - j);
    }
    cout << ans << '\n';
  }
}
