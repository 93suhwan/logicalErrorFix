#include <bits/stdc++.h>
using namespace std;
char _;
int t, n, loc, hLength;
string str;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    loc = -1;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == '0') {
        loc = i;
        break;
      }
    }
    if (loc == -1) {
      cout << "1 " << str.length() - 1 << " 2 " << str.length() << "\n";
      continue;
    } else {
      hLength = str.length() / 2;
      ++loc;
      if (loc <= hLength) {
        cout << loc << " " << str.length() << " " << loc + 1 << " "
             << str.length() << "\n";
      } else {
        cout << "1 " << loc << " 1 " << loc - 1 << "\n";
      }
    }
  }
  return 0;
}
