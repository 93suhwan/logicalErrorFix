#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test;
  cin >> test;
  while (test--) {
    string s;
    cin >> s;
    if (s.length() % 2 == 0) {
      bool check = true;
      int i = 0;
      int j = s.length() / 2;
      int n = s.length() / 2;
      while (n) {
        if (s[i] != s[j]) {
          check = false;
        }
        i++;
        j++;
        n--;
      }
      if (check) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
