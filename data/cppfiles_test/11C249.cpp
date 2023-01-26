#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
struct word {
  int cnt[5], len;
} s[N + 5];
struct comp {
  int v;
  bool operator()(word a, word b) {
    return a.cnt[v] - (a.len - a.cnt[v]) > b.cnt[v] - (b.len - b.cnt[v]);
  }
} cmp;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      string str;
      cin >> str;
      s[i].len = str.size();
      for (int j = 0; j < 5; j++) s[i].cnt[j] = 0;
      for (int j : str) s[i].cnt[j - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < 5; i++) {
      cmp.v = i;
      sort(s + 1, s + 1 + n, cmp);
      int now = 0, fst = 0, snd = 0;
      for (int j = 1; j <= n; j++)
        if (fst + s[j].cnt[i] > snd + s[j].len - s[j].cnt[i]) {
          fst += s[j].cnt[i];
          snd += s[j].len - s[j].cnt[i];
          now++;
        }
      ans = max(ans, now);
    }
    cout << ans << endl;
  }
  return 0;
}
