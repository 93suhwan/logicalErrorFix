#include <bits/stdc++.h>
using namespace std;
vector<string> vec;
int cmp(string a, string b) {
  int i = 0, j = 0, cnt = 0;
  for (; i < a.size(); i++) {
    if (a[i] == b[j])
      j++;
    else
      cnt++;
  }
  return (b.size() - j) + cnt;
}
void solve() {
  string s;
  cin >> s;
  int mins = 1e6;
  for (int i = 0; i < 64; i++) {
    mins = min(mins, cmp(s, vec[i]));
  }
  cout << mins << endl;
}
int main() {
  for (int i = 0; i <= 63; i++) vec.push_back(to_string(1ll << i));
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
