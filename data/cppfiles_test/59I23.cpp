#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int studentai[1001][5];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        int a;
        cin >> a;
        studentai[i][j] = a;
      }
    }
    bool gali = false;
    for (int i = 0; i < 5; i++) {
      for (int j = i + 1; j < 5; j++) {
        int kiekP = 0;
        int kiekA = 0;
        int kiekPA = 0;
        for (int k = 0; k < n; k++) {
          if (studentai[k][j] == studentai[k][i] and studentai[k][i] == 1) {
            kiekPA++;
          }
          kiekP += studentai[k][i];
          kiekA += studentai[k][j];
        }
        if (kiekA + kiekPA - kiekPA >= n / 2 and
            kiekP + (kiekA + kiekPA - n / 2) - kiekPA >= n / 2 and
            kiekA != 0 and kiekP != 0) {
          gali = true;
          break;
        }
      }
      if (gali) {
        break;
      }
    }
    if (gali) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
