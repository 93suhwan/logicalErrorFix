#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    int time = 0;
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
      time += abs((int)s[i - 1] - (int)s[i]);
    }
    cout << time << endl;
  }
  return 0;
}
