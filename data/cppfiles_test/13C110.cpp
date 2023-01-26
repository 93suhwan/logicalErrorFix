#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, count_B, count_AC;
  cin >> t;
  for (int i = 0; i < t; i++) {
    count_B = 0;
    count_AC = 0;
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == 'B') {
        count_B++;
      } else {
        count_AC++;
      }
    }
    if (count_B == count_AC) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
