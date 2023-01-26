#include <bits/stdc++.h>
using namespace std;
void nhapmang(int mang[], int n) {
  for (int i = 0; i < n; i++) {
    cin >> mang[i];
  }
}
void swap(int &a, int &b) {
  int s = a;
  a = b;
  b = s;
}
bool chan(int n) {
  if (n % 2 == 0) {
    return true;
  } else {
    return false;
  }
}
bool cungchancungle(int a, int b) {
  if ((chan(a) && chan(b)) || (chan(a) == false && chan(b) == false)) {
    return true;
  } else {
    return false;
  }
}
int main() {
  int test, dodai, sole, sochan, solanswap, g;
  cin >> test;
  if (test < 1 || test > 1000) {
    return 0;
  }
  for (int x = 0; x < test; x++) {
    g = 1;
    sole = 0;
    sochan = 0;
    solanswap = 0;
    cin >> dodai;
    if (dodai < 1 || dodai > 100000) {
      continue;
    }
    int mang[dodai];
    nhapmang(mang, dodai);
    if (dodai == 1) {
      cout << 0 << endl;
      continue;
    }
    if (dodai == 2) {
      if (cungchancungle(mang[0], mang[1]) == false) {
        cout << 0 << endl;
        continue;
      }
    }
    for (int i = 0; i < dodai; i++) {
      if (chan(mang[i])) {
        sochan++;
      } else {
        sole++;
      }
    }
    if (abs(sochan - sole) >= 2) {
      cout << -1 << endl;
      continue;
    }
    if (sochan > sole) {
      while (chan(mang[0]) == false) {
        if (chan(mang[g])) {
          swap(mang[g - 1], mang[g]);
          solanswap++;
          g = 1;
        } else {
          g++;
        }
      }
    }
    if (sochan < sole) {
      while (chan(mang[0])) {
        if (chan(mang[g]) == false) {
          swap(mang[g - 1], mang[g]);
          solanswap++;
          g = 1;
        } else {
          g++;
        }
      }
    }
    if (sochan == sole) {
      if (cungchancungle(mang[0], mang[1]) == false &&
          cungchancungle(mang[1], mang[2])) {
        swap(mang[0], mang[1]);
        solanswap++;
      }
    }
    while (g < dodai - 1) {
      if (cungchancungle(mang[g - 1], mang[g]) &&
          cungchancungle(mang[g], mang[g + 1]) == false) {
        swap(mang[g], mang[g + 1]);
        solanswap++;
        g = 1;
      } else {
        g++;
      }
    }
    cout << solanswap << endl;
  }
}
