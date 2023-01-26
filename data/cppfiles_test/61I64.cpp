#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count1 = 0, count2 = 0;
    string s1 = s, s2 = s;
    for (int i = 0; i < n; i++) {
      if (s1[i] == '?' && i % 2 == 1) {
        s1[i] = 'R';
        if ((i - 1) >= 0 && s1[i - 1] == 'R') {
          count1++;
        }
      }
      if (s1[i] == '?' && i % 2 == 0) {
        s1[i] = 'B';
        if ((i - 1) >= 0 && s1[i - 1] == 'B') {
          count1++;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (s2[i] == '?' && i % 2 == 0) {
        s2[i] = 'R';
        if ((i - 1) >= 0 && s2[i - 1] == 'R') {
          count2++;
        }
      }
      if (s2[i] == '?' && i % 2 == 1) {
        s2[i] = 'B';
        if ((i - 1) >= 0 && s2[i - 1] == 'B') {
          count2++;
        }
      }
    }
    if (count1 > count2) {
      cout << s2 << endl;
    } else {
      cout << s1 << endl;
    }
  }
}
