#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<int> v(26, 0), cnt(26, 0);
    vector<pair<int, int> > u;
    string ans = "", tmp = "";
    int sum = 0;
    bool b = 1;
    for (int i = 0; i < s.size(); i++) {
      v[s[i] - 'a'] = i + 1;
      cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (v[i]) {
        u.push_back({v[i], i});
      }
    }
    sort(u.begin(), u.end());
    int j = 1;
    for (auto e : u) {
      v[e.second] = j;
      j++;
    }
    for (int i = 0; i < 26; i++) {
      if (v[i]) {
        if (cnt[i] % v[i]) b = 0;
        cnt[i] = cnt[i] / v[i];
        sum += cnt[i];
      }
    }
    for (int i = 0; i < sum; i++) ans += s[i];
    for (auto e : u) tmp += char('a' + e.second);
    string aa = ans, bb = "";
    int k = sum, m = 0;
    for (int i = 0; i < u.size() - 1; i++) {
      for (int j = 0; j < aa.size(); j++) {
        if (aa[j] != tmp[m]) bb += aa[j];
      }
      if (k + bb.size() > s.size()) {
        b = 0;
        break;
      }
      for (int j = k; j < k + bb.size(); j++) {
        if (s[j] != bb[j - k]) b = 0;
      }
      k += bb.size();
      m++;
      aa = bb;
      bb = "";
    }
    if (b) {
      cout << ans << ' ' << tmp << '\n';
    } else
      cout << -1 << '\n';
  }
}
