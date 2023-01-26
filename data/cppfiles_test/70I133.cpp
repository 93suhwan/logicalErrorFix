#include <bits/stdc++.h>
using namespace std;
void solve() {
  int cnt[34], rcnt, v[30], et, etcnt, pt, ospt;
  string t, s, opt, oldd = "", neww;
  char curr;
  vector<char> post;
  cin >> t;
  for (int i = 0; i < 26; i++) cnt[i] = 0;
  for (int i = 0; i < 26; i++) v[i] = 0;
  rcnt = 0;
  for (char i : t) cnt[i - 'a']++;
  for (int i = 0; i < 26; i++) {
    if (cnt[i]) rcnt++;
  }
  pt = t.length() - 1;
  et = 0;
  for (int i = rcnt; i >= 1; i--) {
    etcnt = 1;
    curr = t[pt];
    ospt = oldd.length() - 1;
    neww = curr;
    pt--;
    while (v[curr - 'a'] && pt > 0) {
      if (ospt >= 0 && oldd[ospt] == curr) {
        etcnt++;
        ospt--;
        curr = t[pt];
        pt--;
        neww += curr;
      } else {
        cout << "-1\n";
        return;
      }
    }
    if (v[curr - 'a']) {
      cout << "-1\n";
      return;
    }
    post.push_back(curr);
    v[curr - 'a'] = 1;
    if (cnt[curr - 'a'] % i) {
      cout << "-1\n";
      return;
    }
    et += cnt[curr - 'a'] / i;
    while (etcnt < et && pt > 0) {
      etcnt++;
      if (curr == t[pt]) {
        neww += curr;
      } else {
        if (ospt >= 0 && t[pt] == oldd[ospt]) {
          neww += t[pt];
          ospt--;
        } else {
          cout << "-1\n";
          return;
        }
      }
      pt--;
    }
    reverse(neww.begin(), neww.end());
    oldd = neww;
    neww = "";
  }
  for (int i = 0; i < et; i++) cout << t[i];
  cout << " ";
  for (int i = rcnt - 1; i >= 0; i--) cout << post[i];
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) solve();
}
