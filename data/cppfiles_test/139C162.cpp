#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  string s, s2, s3;
  cin >> t;
  while (t--) {
    cin >> s;
    int l = s.size();
    if (l % 2 == 1)
      cout << "NO" << endl;
    else {
      int mid = l / 2;
      s2 = s.substr(0, mid);
      s3 = s.substr(mid, l - mid);
      if (s2 == s3)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}
