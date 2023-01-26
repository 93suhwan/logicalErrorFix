#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int mod = 1e9 + 7;
bool chk(unordered_map<char, int> a, unordered_map<char, int> b) {
  for (auto p : a)
    if (p.second < b[p.first]) return 0;
  return 1;
}
bool chk(string a, string b, char o) {
  string x;
  for (char c : a)
    if (c != o) x += c;
  return x == b;
}
void solve() {
  string s;
  cin >> s;
  unordered_map<char, int> cnt, tot;
  for (char c : s) ++tot[c];
  vector<string> a;
  vector<unordered_map<char, int>> d;
  vector<pair<int, int>> idx;
  string ord;
  unordered_set<char> vis;
  int R = s.length() - 1, lv = 1;
  for (int L = s.length() - 1; ~L; --L) {
    if (!vis.count(s[L])) {
      vis.insert(s[L]);
      ord += s[L];
    }
    ++cnt[s[L]];
    if (cnt.size() == lv) {
      ++lv;
      d.push_back(cnt);
      idx.emplace_back(L, R);
      cnt.clear();
      R = L - 1;
    }
  }
  reverse(ord.begin(), ord.end());
  for (int i = 0; i < idx.back().first; ++i) ++d.back()[s[i]];
  idx.back().first = 0;
  for (int i = 1; i < d.size(); ++i) {
    auto &up = d[i - 1], &down = d[i];
    int &p = idx[i - 1].first;
    while (!chk(up, down) && p >= 0) {
      --p;
      if (p < 0) {
        break;
      }
      ++up[s[p]];
      --down[s[p]];
    }
    if (chk(up, down) and p > 0) idx[i].second = p - 1;
  }
  for (auto p : idx) a.emplace_back(s.substr(p.first, p.second - p.first + 1));
  reverse(a.begin(), a.end());
  for (int i = 1; i < a.size(); ++i) {
    if (!chk(a[i - 1], a[i], ord[i - 1])) {
      cout << "-1\n";
      return;
    }
  }
  cout << a.front() << ' ' << ord << '\n';
}
signed main() {
  int T;
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) solve();
  return 0;
}
