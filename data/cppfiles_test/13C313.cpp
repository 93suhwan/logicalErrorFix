#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    int countA = 0, countB = 0, countC = 0;
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == 'A') {
        countA++;
      } else if (str[i] == 'B') {
        countB++;
      } else if (str[i] == 'C') {
        countC++;
      }
    }
    if (countB == countA + countC) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}
