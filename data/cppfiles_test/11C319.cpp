#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
struct node {
  int sz;
  int cnt[5];
  int tar;
};
int n;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<node> words(n);
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      words[i].sz = s.length();
      for (char c : s) words[i].cnt[c - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < n; j++) {
        words[j].tar = words[j].cnt[i] * 2 - words[j].sz;
      }
      sort(words.begin(), words.end(),
           [](node a, node b) -> bool { return a.tar > b.tar; });
      int most = 0, rest = 0;
      for (int j = 0; j < n; j++) {
        most += words[j].cnt[i];
        rest += words[j].sz - words[j].cnt[i];
        if (most <= rest) {
          ans = max(ans, j);
          break;
        }
        if (j == n - 1) {
          ans = n;
        }
      }
      if (ans == n) break;
    }
    cout << ans << endl;
  }
  return 0;
}
