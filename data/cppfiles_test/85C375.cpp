#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int zero = count(s.begin(), s.end(), '0');
    if (zero == 0) {
      cout << 0 << endl;
      continue;
    }
    int first = s.find('0');
    int last = s.rfind('0');
    if (last - first + 1 == zero)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
}
