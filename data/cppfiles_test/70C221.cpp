#include <bits/stdc++.h>
using namespace std;
vector<int> pattern;
unordered_map<int, int> um;
bool can(vector<int> kiri, vector<int> kanan) {
  int maxct = -1;
  um.clear();
  for (int i = 0; i < 26; i++) {
    if (kiri[i] == 0 && kanan[i] == 0) continue;
    if (kiri[i] == 0 && kanan[i] != 0) return false;
    if (kanan[i] % kiri[i] != 0) return false;
    int ct = kanan[i] / kiri[i];
    if (um[ct] != 0) return false;
    um[ct] = i + 1;
    maxct = max(maxct, ct);
  }
  for (int i = 0; i <= maxct; i++) {
    if (um[i] == 0) return false;
  }
  pattern.resize(maxct + 1);
  for (int i = 0; i <= maxct; i++) {
    pattern[i] = um[i] - 1;
  }
  return true;
}
bool test(string s, int n) {
  string t = "";
  string tp = "";
  for (int i = 0; i < n; i++) tp += s[i];
  for (int k = 0; k < pattern.size(); k++) {
    for (auto x : tp) {
      if (x != '$') t += x;
    }
    for (int i = 0; i < tp.size(); i++) {
      if (tp[i] - 'a' == pattern[k]) tp[i] = '$';
    }
  }
  if (t == s)
    return true;
  else
    return false;
}
bool solve() {
  string s;
  cin >> s;
  vector<int> kiri(26, 0);
  vector<int> kanan(26, 0);
  for (auto x : s) kanan[x - 'a']++;
  for (int k = 0; k < s.size(); k++) {
    kiri[s[k] - 'a']++;
    kanan[s[k] - 'a']--;
    if (can(kiri, kanan)) {
      if (test(s, k + 1)) {
        for (int i = 0; i <= k; i++) cout << s[i];
        cout << " ";
        for (auto x : pattern) cout << (char)(x + 'a');
        cout << "\n";
        return true;
      } else
        return false;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    if (!solve()) cout << -1 << "\n";
  }
  return 0;
}
