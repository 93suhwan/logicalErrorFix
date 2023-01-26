#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const double PI = acos(-1.0);
const int mod = 998244353;
char s1[10005];
char s2[1005];
int book[200];
void solve() {
  cin >> s1 + 1;
  cin >> s2 + 1;
  int len1 = strlen(s1 + 1);
  for (int i = 1; i <= len1; i++) {
    book[s1[i]]++;
  }
  if (s2[1] == 'a' && s2[2] == 'b' && s2[3] == 'c' && book['a'] && book['b'] &&
      book['c']) {
    while (book['a']) {
      cout << 'a';
      book['a']--;
    }
    while (book['c']) {
      cout << 'c';
      book['c']--;
    }
    while (book['b']) {
      cout << 'b';
      book['b']--;
    }
    for (int i = 'd'; i <= 'z'; i++) {
      while (book[i]) {
        cout << (char)i;
        book[i]--;
      }
    }
  } else {
    for (int i = 'a'; i <= 'z'; i++) {
      while (book[i]) {
        cout << (char)i;
        book[i]--;
      }
    }
  }
  cout << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
