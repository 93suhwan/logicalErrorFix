#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string a;
    cin >> a;
    int n = a.length();
    if (n % 2 != 0)
      cout << "NO\n";
    else {
      string b, c;
      b = a.substr(0, (n / 2));
      c = a.substr((n / 2), (n / 2));
      if (b == c)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
