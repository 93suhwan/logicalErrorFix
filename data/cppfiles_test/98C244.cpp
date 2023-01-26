#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string tt;
  getline(cin, tt);
  int t = stoi(tt);
  while (t--) {
    string txt;
    string query;
    getline(cin, txt);
    getline(cin, query);
    int chk[26];
    fill(chk, chk + 26, -1);
    for (int i = 0; i < 26; i++) {
      chk[txt[i] - 'a'] = i;
    }
    int ans = 0;
    for (int i = 1; i < query.length(); i++) {
      ans += abs(chk[query[i - 1] - 'a'] - chk[query[i] - 'a']);
    }
    cout << ans << endl;
  }
}
