#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> s;
  n = stoi(s);
  while (n-- > 0) {
    cin >> s;
    int t = stoi(s);
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    int cnt = 0;
    for (int i = 0; i < t; i++) {
      if (s2[i] == '1' && s1[i] == '0') {
        cnt++;
        continue;
      }
      if (s2[i] == '1' && i != t - 1 && s1[i] == '1' && s1[i + 1] == '1' &&
          s2[i + 1] == '1') {
        cnt += 2;
        i++;
      }
    }
    cout << cnt << endl;
  }
}
