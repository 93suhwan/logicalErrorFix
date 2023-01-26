#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    string s;
    cin >> s;
    int n = s.length();
    if (n % 2 != 0) {
      cout << "NO" << endl;
    } else if (n % 2 == 0) {
      string k = "";
      string l = "";
      for (int i = 0; i < n / 2; i++) k = k + s[i];
      for (int i = n / 2; i < n; i++) l = l + s[i];
      if (l == k)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
    t--;
  }
}
