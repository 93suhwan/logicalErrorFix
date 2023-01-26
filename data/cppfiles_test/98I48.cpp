#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  int p;
  for (p = 0; p < T; p++) {
    string str;
    cin >> str;
    string s;
    cin >> s;
    int k = s.length();
    int t = 0;
    int i;
    for (i = 0; i < k - 1; i++) {
      int y = str.find(s[i]);
      int z = str.find(s[i + 1]);
      t = t + abs(y - z);
    }
    cout << t << endl;
  }
  return 0;
}
