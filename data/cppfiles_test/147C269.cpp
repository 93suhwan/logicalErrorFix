#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string word;
    cin >> word;
    int cnte = 0;
    int cntn = 0;
    for (int i = 0; i < word.length(); i++) {
      if (word[i] == 'E') {
        cnte++;
      } else if (word[i] == 'N') {
        cntn++;
      }
    }
    if (cntn == 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
