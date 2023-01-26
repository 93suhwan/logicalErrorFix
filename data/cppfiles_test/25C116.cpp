#include <bits/stdc++.h>
using namespace std;
int t;
string s, str;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> s >> str;
    deque<pair<int, int> > Q;
    for (int i = 0; i < s.length(); ++i) {
      if (str[0] == s[i]) Q.push_back(make_pair(i, 0));
    }
    int len = str.length();
    bool yes = 0;
    while (!Q.empty()) {
      pair<int, int> cur = Q.front();
      Q.pop_front();
      int idx = cur.first, cnt = (cur.second < 0 ? -cur.second : cur.second);
      char nxt = str[cnt + 1];
      if (cnt == len - 1) {
        yes = 1;
        break;
      }
      if (idx > 0 && nxt == s[idx - 1])
        Q.push_back(make_pair(idx - 1, -(cnt + 1)));
      if (cur.second >= 0 && idx < s.length() - 1 && nxt == s[idx + 1])
        Q.push_back(make_pair(idx + 1, cnt + 1));
    }
    cout << (yes ? "YES\n" : "NO\n");
  }
}
