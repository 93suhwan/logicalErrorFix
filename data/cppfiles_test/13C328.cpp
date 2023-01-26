#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
void solve() {
  unordered_map<char, int> make_pair;
  string s;
  cin >> s;
  for (auto x : s) {
    make_pair[x]++;
  }
  if (make_pair.find('B') == make_pair.end()) {
    cout << "NO" << endl;
    return;
  }
  if (make_pair.find('A') == make_pair.end()) {
    make_pair['A'] = 0;
  }
  if (make_pair.find('C') == make_pair.end()) {
    make_pair['C'] = 0;
  }
  while (true) {
    if (make_pair['A'] > 0 && make_pair['B'] > 0) {
      make_pair['A']--;
      make_pair['B']--;
    }
    if (make_pair['B'] > 0 && make_pair['C'] > 0) {
      make_pair['C']--;
      make_pair['B']--;
    }
    if (make_pair['A'] == 0 && make_pair['B'] == 0 && make_pair['C'] == 0) {
      cout << "YES" << endl;
      return;
    } else if (make_pair['A'] == 0 && make_pair['B'] == 0 &&
               make_pair['C'] > 0) {
      cout << "NO" << endl;
      return;
    } else if (make_pair['B'] == 0 && make_pair['C'] == 0 &&
               make_pair['A'] > 0) {
      cout << "NO" << endl;
      return;
    } else if (make_pair['C'] == 0 && make_pair['A'] == 0 &&
               make_pair['B'] > 0) {
      cout << "NO" << endl;
      return;
    } else if (make_pair['A'] > 0 && make_pair['C'] > 0 &&
               make_pair['B'] == 0) {
      cout << "NO" << endl;
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
