#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    char arr[10];
    int sc1 = 0, sc2 = 0, m1 = 5, m2 = 5, si1 = 0, si2 = 0, moves = 0;
    cin >> arr;
    for (int i = 0; i < 10; i++) {
      if (i % 2 == 0) {
        if (arr[i] == '1') {
          sc1 += 1;
        } else if (arr[i] == '?') {
          si1 += 1;
        }
        m1 -= 1;
      } else {
        if (arr[i] == '1') {
          sc2 += 1;
        } else if (arr[i] == '?') {
          si2 += 1;
        }
        m2 -= 1;
      }
      moves += 1;
      if (sc1 + si1 > sc2 + m2 or sc2 + si2 > sc1 + m1) {
        cout << moves << endl;
        break;
      }
      if (sc1 == sc2 and moves == 10) {
        cout << 10 << endl;
      }
    }
  }
}
