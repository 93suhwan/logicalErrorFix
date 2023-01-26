#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string a;
    cin >> a;
    int i = 1, count = 0;
    char fc = a[0];
    while (i < a.length()) {
      if (a[i] == fc)
        i++;
      else {
        int prepos = 0;
        int postpos = 0;
        for (int j = 0; j < 26; j++) {
          if (s[j] == fc) {
            prepos = j;
            break;
          }
        }
        for (int j = 0; j < 26; j++) {
          if (s[j] == a[i]) {
            postpos = j;
            break;
          }
        }
        count += abs(postpos - prepos);
        fc = a[i];
        i++;
      }
    }
    cout << count << "\n";
  }
}
