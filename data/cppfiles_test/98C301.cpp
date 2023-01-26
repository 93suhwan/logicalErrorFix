#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, s2;
    cin >> s >> s2;
    int sum = 0;
    for (int i = 1; i < s2.size(); i++) {
      int x = s.find(s2[i]);
      int y = s.find(s2[i - 1]);
      sum += abs(x - y);
    }
    cout << sum << endl;
  }
  return 0;
}
