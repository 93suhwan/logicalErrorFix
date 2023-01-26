#include <bits/stdc++.h>
using namespace std;
void reverse(string& s) {
  int i = 0, j = s.length() - 1;
  while (i < j) {
    swap(s[i], s[j]);
    i++;
    j--;
  }
}
void solve();
int main() {
  ios::sync_with_stdio(0);
  solve();
}
int l(int b, int a) { return log(a) / log(b); }
void solve() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s[0] == s[s.size() - 1])
      cout << s << endl;
    else {
      s[s.size() - 1] = s[0];
      cout << s << endl;
    }
  }
}
