#include <bits/stdc++.h>
using namespace std;
const float two = 2;
vector<string> w;
int n;
int count(char c, string word) {
  int cnt = 0;
  for (char &x : word)
    if (x == c) cnt++;
  return cnt;
}
int diff(char c, string word) { return word.size() - 2 * count(c, word); }
char cur;
bool comp(string a, string b) { return diff(cur, a) < diff(cur, b); }
int calc(char c) {
  cur = c;
  int main = 0;
  int other = 0;
  int cnt = 0;
  vector<bool> chosen(n, false);
  int i = 0;
  for (auto &word : w) {
    if (count(c, word) >= ceil(word.size() / two)) {
      cnt++;
      main += count(c, word);
      other += word.size() - count(c, word);
      chosen[i] = true;
    }
    i++;
  }
  if (main <= other) return 0;
  vector<string> rm;
  i = 0;
  for (auto &word : w)
    if (!chosen[i++]) rm.push_back(word);
  sort(rm.begin(), rm.end(), comp);
  for (auto &word : rm) {
    main += count(c, word);
    other += word.size() - count(c, word);
    if (main <= other) break;
    cnt++;
  }
  return cnt;
}
char ic(int i) { return "abcdefghijklmnopqrstuvwxyz"[i]; };
void solve() {
  w.clear();
  cin >> n;
  w.resize(n);
  for (int i = 0; i < n; i++) cin >> w[i];
  int ans = 0;
  for (int i = 0; i < 5; i++) ans = max(ans, calc(ic(i)));
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
