#include <bits/stdc++.h>
using namespace std;
template <typename T>
void get_vector(T &a) {
  for (auto &e : a) cin >> e;
}
template <typename T>
void put_vector(T a) {
  for (auto e : a) cout << e << " ";
  cout << endl;
}
void solve() {
  string s;
  int k;
  cin >> s >> k;
  while (1) {
    set<char> cnt;
    for (auto e : s) cnt.insert(e);
    if (cnt.size() <= k) {
      cout << s << endl;
      return;
    }
    cnt.clear();
    int ptr = 0;
    while (1) {
      cnt.insert(s[ptr]);
      if (cnt.size() > k) {
        while (s[ptr] == '9') ptr--;
        s[ptr]++;
        for (int i = ptr + 1; i < s.size(); i++) s[i] = '0';
        break;
      }
      ptr++;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
