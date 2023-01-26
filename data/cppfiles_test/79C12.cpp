#include <bits/stdc++.h>
int masyvasL[11];
int masyvasR[11];
int masyvasP[21];
using namespace std;
void resetM() {
  for (int i = 1; i <= 10; i++) {
    masyvasL[i] = -1;
    masyvasR[i] = -1;
  }
}
bool checkP(int x) {
  for (int i = 0; i < 21; i++) {
    if (masyvasP[i] == x) {
      return false;
    }
  }
  return true;
}
int charToNum(char x) {
  if (x == '1') {
    return 1;
  } else if (x == '2') {
    return 2;
  } else if (x == '3') {
    return 3;
  } else if (x == '4') {
    return 4;
  } else if (x == '5') {
    return 5;
  } else if (x == '6') {
    return 6;
  } else if (x == '7') {
    return 7;
  } else if (x == '8') {
    return 8;
  } else {
    return 9;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int mas[] = {11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
               53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
  for (int i = 0; i < 21; i++) {
    masyvasP[i] = mas[i];
  }
  resetM();
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int k;
    cin >> k;
    string s;
    cin >> s;
    for (int j = 0; j < k; j++) {
      int a;
      a = charToNum(s[j]);
      if (masyvasR[a] == -1) {
        masyvasR[a] = j;
      }
      if (masyvasL[a] < j) {
        masyvasL[a] = j;
      }
    }
    bool defJam = false;
    for (int a = 1; a <= 10; a++) {
      if (masyvasL[a] != -1) {
        if (a == 1 || a == 4 || a == 6 || a == 8 || a == 9) {
          cout << 1 << "\n";
          cout << a << "\n";
          defJam = true;
          break;
        }
      }
    }
    if (defJam) {
      resetM();
      continue;
    }
    bool gay = false;
    for (int a = 1; a <= 10; a++) {
      for (int b = 1; b <= 10; b++) {
        if (masyvasR[b] != -1) {
          if (masyvasR[b] < masyvasL[a]) {
            int gg = b * 10 + a;
            if (checkP(gg)) {
              cout << 2 << "\n";
              cout << gg << "\n";
              gay = true;
              break;
            }
          }
        }
        if (gay) {
          break;
        }
      }
    }
    resetM();
  }
}
