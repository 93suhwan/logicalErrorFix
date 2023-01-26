#include <bits/stdc++.h>
using namespace std;
bool isComposite[10000];
string brute(string s) {
  int n = s.size(), ans = 1000000;
  for (long long i = 1; i < (1 << n); i++) {
    int tot = 0;
    int j = i;
    for (auto c : s) {
      if (j & 1) {
        tot *= 10;
        tot += (c - '0');
      }
      j >>= 1;
    }
    if (isComposite[tot]) ans = min(ans, tot);
  }
  return to_string(ans);
}
void solve() {
  int k;
  cin >> k;
  string s;
  cin >> s;
  if (k < 5) {
    string ans = brute(s);
    cout << ans.size() << endl << ans << endl;
  } else {
    vector<int> cnt(10, 0);
    for (auto c : s) cnt[c - '0']++;
    int lenOne[5] = {1, 4, 6, 8, 9};
    for (long long i = 0; i < 5; i++) {
      if (cnt[lenOne[i]]) {
        cout << 1 << endl << (char)('0' + lenOne[i]) << endl;
        return;
      }
    }
    for (long long i = 0; i < 10; i++) {
      if (cnt[i] > 1) {
        cout << 2 << endl << (char)('0' + i) << (char)('0' + i) << endl;
      }
    }
  }
}
int main() {
  for (long long i = 0; i < 10000; i++) isComposite[i] = false;
  isComposite[1] = true;
  for (long long i = 2; i < 10000; i++) {
    for (int j = 2; i * j < 10000; j++) isComposite[i * j] = true;
  }
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  for (long long t = 0; t < T; t++) {
    solve();
  }
}
