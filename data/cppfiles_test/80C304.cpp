#include <bits/stdc++.h>
using namespace std;
string s;
int pos;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    pos = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0') pos = i + 1;
    }
    if (pos == 0)
      cout << 1 << " " << n / 2 << " " << 2 << " " << n / 2 + 1 << endl;
    else if (pos > n / 2)
      cout << 1 << " " << pos << " " << 1 << " " << pos - 1 << endl;
    else
      cout << pos << " " << n << " " << pos + 1 << " " << n << endl;
  }
}
