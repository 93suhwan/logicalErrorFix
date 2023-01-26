#include <bits/stdc++.h>
using namespace std;
int id(string s, int b, int x) {
  if (x <= b) return x;
  return (b << 1) - x;
}
bool kmpSearch(string s, string t, vector<int>& v, int slen, int tlen, int b) {
  for (int i = 0; i < slen; i++) {
    int j = 0;
    for (; j < tlen; j++) {
      if (t[j] != s[id(s, b, i + j)]) break;
    }
    if (j == tlen) return true;
  }
  return false;
}
void kmpBuild(string s, vector<int>& v, int si) {
  int j = 0;
  for (int i = 1; i < si; i++) {
    while (s[j] != s[i]) {
      if (!j) break;
      j = v[j - 1];
    }
    (!j) ? v[i] = 0 : v[i] = j + 1;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test;
  cin >> test;
  while (test--) {
    string s, t;
    cin >> s >> t;
    int slen = s.length(), tlen = t.length();
    vector<int> v(tlen);
    kmpBuild(t, v, tlen);
    bool ans = 0;
    for (int i = 0; i < slen; i++) {
      int tmp = i * 2 + 1;
      if (tmp < tlen) continue;
      if (kmpSearch(s, t, v, tmp, tlen, i)) {
        ans = 1;
        break;
      }
    }
    (ans) ? (cout << "YES\n") : (cout << "NO\n");
  }
  return 0;
}
