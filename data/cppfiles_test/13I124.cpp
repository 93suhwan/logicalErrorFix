#include <bits/stdc++.h>
using namespace std;
void solve(long long counter) {
  long long zeilen, spalten, horizontal;
  cin >> zeilen >> spalten >> horizontal;
  long long vertikal = (zeilen * spalten) / 2 - horizontal;
  bool erste_zeile = false;
  bool erste_spalte = false;
  if (zeilen % 2 == 1) {
    zeilen--;
    horizontal -= spalten / 2;
    if (horizontal < 0) {
      cout << "NO\n";
      return;
    }
    erste_zeile = true;
  } else if (spalten % 2 == 1) {
    spalten--;
    vertikal -= zeilen / 2;
    if (vertikal < 0) {
      cout << "NO\n";
      return;
    }
    erste_spalte = true;
  }
  if (vertikal % 2 == 0 && horizontal % 2 == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
    return;
  }
  if (erste_zeile) {
    for (long long i = 0; i < spalten; i += 2) {
      cout << "ab";
    }
    cout << "\n";
  }
  string next_line;
  for (long long y = 0; y < zeilen; y++) {
    if (erste_spalte) {
      if (y / 2 % 2 == 0) {
        cout << "g";
      } else {
        cout << "h";
      }
    }
    if (y % 2 == 1) {
      cout << next_line << "\n";
      continue;
    }
    next_line = "";
    for (long long x = 0; x < spalten; x++) {
      if (y % 2 == 0) {
        if (horizontal > 0) {
          horizontal -= 1;
          if (x / 2 % 2 == 0) {
            cout << "c";
            next_line += "d";
          } else {
            cout << "d";
            next_line += "c";
          }
        } else {
          if (x % 2 == y / 2 % 2) {
            cout << "e";
            next_line += "e";
          } else {
            cout << "f";
            next_line += "f";
          }
        }
      }
    }
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve(i);
  }
}
