#include <bits/stdc++.h>
using namespace std;
void hanuman_dada_ki_jay() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    bool cond = false;
    for (int i = 0; i < s.length() / 2; i++) {
      if (s[i] == s[i + (s.length() / 2)]) {
        cond = true;
      } else {
        cond = false;
        break;
      }
    }
    if (cond) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
int main() { hanuman_dada_ki_jay(); }
