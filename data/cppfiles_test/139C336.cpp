#include <bits/stdc++.h>
using namespace std;
int main() {
  int asda;
  cin >> asda;
  while (asda--) {
    string qwe, www, wwe;
    cin >> qwe;
    if (qwe.size() % 2 == 1)
      cout << "NO";
    else {
      for (unsigned int i = 0; i < qwe.size() / 2; i++) {
        wwe += qwe.at(i);
      }
      for (unsigned int i = qwe.size() / 2; i < qwe.size(); i++) {
        www += qwe.at(i);
      }
      if (wwe == www)
        cout << "YES";
      else
        cout << "NO";
    }
    cout << endl;
  }
}
