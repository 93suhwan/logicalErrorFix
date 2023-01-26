#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, raz = 0;
  string a;
  cin >> t;
  for (int i = 0; i < t; i++) {
    map<char, int> otv;
    map<char, int>::iterator it;
    raz = 0;
    cin >> a;
    for (int j = 0; a[j] != '\0'; j++) {
      it = otv.find(a[j]);
      if (it == otv.end()) {
        otv.insert(pair<char, int>(a[j], 1));
      } else {
        it->second++;
      }
    }
    for (it = otv.begin(); it != otv.end(); it++) {
      if (it->second == 1) {
        raz++;
      } else {
        if (it->second >= 2) raz += 2;
      }
    }
    cout << raz / 2 << endl;
  }
}
