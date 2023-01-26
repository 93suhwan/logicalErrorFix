#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 123;
string s;
int good(int i, vector<char> &charaters) {
  int cnt[1000] = {0};
  for (int j = 0; j <= i; j++) {
    cnt[s[j]]++;
  }
  int len = i + 1;
  int sz = i + 1;
  for (int i = charaters.size() - 1; i >= 0; i--) {
    len += (sz - cnt[charaters[i]]);
    sz -= cnt[charaters[i]];
  }
  if (len == s.size()) return 1;
  if (len > s.size()) return 2;
  return 3;
}
bool check(int i, vector<char> &charaters) {
  string ans;
  for (int j = 0; j <= i; j++) {
    ans += s[j];
  }
  string parttern = ans;
  int cnt[1000] = {0};
  for (int j = charaters.size() - 1; j >= 0; j--) {
    cnt[charaters[j]] = 1;
    for (int k = 0; k < parttern.size(); k++) {
      if (cnt[parttern[k]] == 0) ans += parttern[k];
    }
  }
  return ans == s;
}
void TestCase() {
  cin >> s;
  vector<char> charaters;
  int cnt[1000] = {0};
  for (int i = s.size() - 1; i >= 0; i--) {
    if (cnt[s[i]] == 0) charaters.push_back(s[i]), cnt[s[i]] = 1;
  }
  int c[1000] = {0};
  int count = 0;
  int index;
  for (int i = 0; i < s.size(); i++) {
    if (c[s[i]] == 0) {
      c[s[i]] = 1;
      count++;
    }
    if (count == charaters.size()) {
      index = i;
      break;
    }
  }
  int l = index, r = s.size() - 1;
  int answer = -1;
  while (l <= r) {
    int m = (l + r) >> 1;
    int x = good(m, charaters);
    if (x == 1) {
      answer = m;
      break;
    } else if (x == 2) {
      r = m - 1;
    } else
      l = m + 1;
  }
  if (answer == -1) {
    cout << -1 << '\n';
    return;
  }
  if (!check(answer, charaters)) {
    cout << -1 << '\n';
    return;
  }
  for (int i = 0; i <= answer; i++) {
    cout << s[i];
  }
  cout << ' ';
  for (int i = charaters.size() - 1; i >= 0; i--) cout << charaters[i];
  cout << '\n';
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie();
  int T = 1;
  cin >> T;
  cin.ignore();
  while (T--) {
    TestCase();
  }
}
