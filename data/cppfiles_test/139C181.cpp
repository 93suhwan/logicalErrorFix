#include <bits/stdc++.h>
using namespace std;
int main() {
  int nb;
  cin >> nb;
  for (int i = 0; i < nb; i++) {
    string nom;
    cin >> nom;
    bool verify = true;
    int t = nom.length();
    if (t % 2 != 0)
      verify = false;
    else
      for (int k = 0; k < (t / 2); k++) {
        if (nom[k] != nom[(t / 2) + k]) {
          verify = false;
          break;
        }
      }
    if (verify) {
      cout << "yes" << endl;
    } else
      cout << "no" << endl;
  }
}
