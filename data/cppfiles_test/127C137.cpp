#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}
int abs(int a) {
  if (a > 0)
    return a;
  else
    return -a;
}
void solve() {
  string a, b;
  cin >> a >> b;
  vector<int> co(26, 0);
  for (auto it : a) co[it - 'a']++;
  string ans;
  int aa = 0, bb = 0, cc = 0;
  for (auto it : b) {
    if (it == 'a')
      aa++;
    else if (it == 'b')
      bb++;
    else
      cc++;
  }
  if ((aa && co[0] == 0) || (bb && co[1] == 0) || (cc && co[2] == 0)) {
    sort(a.begin(), a.end());
    ans = a;
    cout << ans << endl;
    return;
  }
  if (aa && bb && cc) {
    if (b[0] == 'a') {
      if (b[1] == 'b') {
        for (int i = (0); i < (co[0]); i++) ans.push_back('a');
        for (int i = (0); i < (co[2]); i++) ans.push_back('c');
        for (int i = (0); i < (co[1]); i++) ans.push_back('b');
      } else {
        for (int i = (0); i < (co[0]); i++) ans.push_back('a');
        for (int i = (0); i < (co[1]); i++) ans.push_back('b');
        for (int i = (0); i < (co[2]); i++) ans.push_back('c');
      }
      for (int i = 3; i < 26; i++) {
        for (int j = (0); j < (co[i]); j++) ans.push_back('a' + i);
      }
    } else {
      sort(a.begin(), a.end());
      ans = a;
    }
    cout << ans << endl;
  } else {
    if (b[0] != b[1]) {
      sort(a.begin(), a.end());
      ans = a;
    } else if (aa == 0) {
      if (b[0] == 'b') {
        for (int i = (0); i < (co[2]); i++) ans.push_back('c');
        for (int i = (0); i < (co[1]); i++) ans.push_back('b');
      } else {
        for (int i = (0); i < (co[1]); i++) ans.push_back('b');
        for (int i = (0); i < (co[2]); i++) ans.push_back('c');
      }
    } else if (bb == 0) {
      if (b[0] == 'a') {
        for (int i = (0); i < (co[2]); i++) ans.push_back('c');
        for (int i = (0); i < (co[1]); i++) ans.push_back('a');
      } else {
        for (int i = (0); i < (co[1]); i++) ans.push_back('a');
        for (int i = (0); i < (co[2]); i++) ans.push_back('c');
      }
    } else if (cc == 0) {
      if (b[0] == 'a') {
        for (int i = (0); i < (co[2]); i++) ans.push_back('b');
        for (int i = (0); i < (co[1]); i++) ans.push_back('a');
      } else {
        for (int i = (0); i < (co[1]); i++) ans.push_back('a');
        for (int i = (0); i < (co[2]); i++) ans.push_back('b');
      }
    }
    for (int i = 3; i < 26; i++) {
      for (int j = (0); j < (co[i]); j++) ans.push_back('a' + i);
    }
    cout << ans << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
