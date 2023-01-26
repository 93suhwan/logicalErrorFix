#include <bits/stdc++.h>
using namespace std;
long long int t, n, m, k, yatsay, diksay;
string str;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m >> yatsay;
    diksay = (n * m) / 2 - yatsay;
    long long int vert[n + 1][m + 1];
    bool anadurum = true;
    for (long long int i = 0; i < n; i++) {
      long long int satkal = n - i;
      if (satkal > 1) {
        bool isKul = false;
        bool durum = false;
        for (long long int j = 0; j < m; j++) {
          long long int sutkal = m - j;
          if ((diksay == 1 && sutkal % 2 == 0) || (diksay == 0)) {
            j++;
            if (isKul) {
              if (yatsay >= 2) {
                yatsay -= 2;
              } else {
                durum = true;
              }
            } else {
              if (yatsay >= 1) {
                yatsay--;
              } else {
                durum = false;
              }
            }
          } else {
            diksay--;
            isKul = true;
          }
        }
        if (durum) {
          anadurum = false;
          break;
        }
        if (isKul) i++;
      } else if (satkal == 1) {
        if (!((yatsay >= (m / 2)) && m % 2 == 0)) {
          anadurum = false;
          break;
        }
      }
    }
    if (anadurum)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
