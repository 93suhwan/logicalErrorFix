#include <bits/stdc++.h>
using namespace std;
int id(string s, int b, int x) {
  if (x <= b) return x;
  return (b << 1) - x;
}
bool kmpSearch(string s, string t, vector<int>& v, int slen, int tlen, int b) {
  int ptr = 0;
  for (int j = 0; j < slen; j++) {
    int i = id(s, b, j);
    if (ptr == tlen) break;
    while (s[i] != t[ptr]) {
      if (!ptr) break;
      ptr = v[ptr - 1];
    }
    if (s[i] == t[ptr]) ptr++;
  }
  return (ptr == tlen);
}
void kmpBuild(string s, vector<int>& v, int si) {
  int j = 0;
  for (int i = 1; i < si; i++) {
    while (s[i] != s[j]) {
      if (!j) break;
      j = v[j - 1];
    }
    if (s[i] == s[j]) v[i] = ++j;
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
