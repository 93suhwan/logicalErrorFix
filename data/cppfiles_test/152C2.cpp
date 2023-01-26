#include <bits/stdc++.h>
using namespace std;
const int stala = 1e6 + 10;
int dp[stala][2];
int poprzedni[stala][2];
int tab[stala];
int res[stala];
void f2(int ile, int index) {
  for (int i = ile; i >= 1; i--) {
    if (index == 1) {
      res[i] = tab[i];
    } else {
      res[i] = -tab[i];
    }
    index = poprzedni[i][index];
  }
  for (int i = 1; i <= ile; i++) {
    cout << res[i] << " ";
  }
  cout << "\n";
}
void czysc(int ile) {
  for (int i = 1; i <= ile; i++) {
    dp[i][0] = 0;
    dp[i][1] = 0;
    poprzedni[i][0] = 0;
    poprzedni[i][1] = 0;
    tab[i] = 0;
    res[i] = 0;
  }
}
void f() {
  int ile;
  cin >> ile;
  for (int i = 1; i <= ile; i++) {
    cin >> tab[i];
  }
  dp[1][0] = -1e9;
  dp[1][1] = -1e9;
  for (int i = 2; i <= ile; i++) {
    dp[i][0] = 1e9;
    dp[i][1] = 1e9;
    if (dp[i - 1][0] != 1e9) {
      if (tab[i - 1] > tab[i]) {
        dp[i][0] = min(dp[i][0], dp[i - 1][0]);
      }
      if (dp[i - 1][0] < tab[i] * (-1)) {
        dp[i][0] = min(dp[i][0], tab[i - 1] * (-1));
      }
      if (tab[i - 1] * (-1) < tab[i]) {
        dp[i][1] = min(dp[i][1], dp[i - 1][0]);
      }
      if (dp[i - 1][0] < tab[i]) {
        dp[i][1] = min(dp[i][1], tab[i - 1] * (-1));
      }
    }
    if (dp[i - 1][1] != 1e9) {
      if (tab[i - 1] < tab[i] * (-1)) {
        if (dp[i][0] > dp[i - 1][1]) {
          dp[i][0] = dp[i - 1][1];
          poprzedni[i][0] = 1;
        }
      }
      if (dp[i - 1][1] < tab[i] * (-1)) {
        if (dp[i][0] > tab[i - 1]) {
          dp[i][0] = tab[i - 1];
          poprzedni[i][0] = 1;
        }
      }
      if (tab[i - 1] < tab[i]) {
        if (dp[i][1] > dp[i - 1][1]) {
          dp[i][1] = dp[i - 1][1];
          poprzedni[i][1] = 1;
        }
      }
      if (dp[i - 1][1] < tab[i]) {
        if (dp[i][1] > tab[i - 1]) {
          dp[i][1] = tab[i - 1];
          poprzedni[i][1] = 1;
        }
      }
    }
  }
  if (dp[ile][1] != 1e9 || dp[ile][0] != 1e9) {
    cout << "YES"
         << "\n";
    if (dp[ile][1] != 1e9) {
      f2(ile, 1);
    } else {
      f2(ile, 0);
    }
  } else {
    cout << "NO"
         << "\n";
  }
  czysc(ile);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int testy;
  cin >> testy;
  for (int i = 1; i <= testy; i++) {
    f();
  }
  return 0;
}
