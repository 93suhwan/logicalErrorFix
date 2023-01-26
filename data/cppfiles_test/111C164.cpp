#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) s += '(';
    for (int i = 0; i < n; i++) s += ')';
    int l = n, r = n - 1;
    for (int i = 0; i < n; i++) {
      cout << s << endl;
      swap(s[l], s[l - 1]);
      l--;
      r++;
    }
  }
}
