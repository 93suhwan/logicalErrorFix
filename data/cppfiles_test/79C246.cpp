#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int tc;
  cin >> tc;
  while (tc--) {
    long long int n, i, j, x, p = 0, dui = 0, teen = 0, pach = 0, shat = 0;
    string s;
    cin >> n >> s;
    vector<long long int> v;
    for (i = 0; i < n; i++) {
      x = s[i] - '0';
      if (x != 2 && x != 3 && x != 5 && x != 7) {
        cout << 1 << endl;
        cout << x << endl;
        p = 1;
        break;
      } else
        v.push_back(x);
    }
    if (!p) {
      cout << 2 << endl;
      for (i = 0; i < v.size(); i++) {
        if (v[i] == 2) {
          if (dui) {
            cout << 22 << endl;
            break;
          }
          if (teen) {
            cout << 32 << endl;
            break;
          }
          if (shat) {
            cout << 72 << endl;
            break;
          }
          if (pach) {
            cout << 52 << endl;
            break;
          }
          dui++;
        } else if (v[i] == 3) {
          if (teen) {
            cout << 33 << endl;
            break;
          }
          teen++;
        } else if (v[i] == 5) {
          if (dui) {
            cout << 25 << endl;
            break;
          }
          if (teen) {
            cout << 35 << endl;
            break;
          }
          if (pach) {
            cout << 55 << endl;
            break;
          }
          if (shat) {
            cout << 75 << endl;
            break;
          }
          pach++;
        } else if (v[i] == 7) {
          if (dui) {
            cout << 27 << endl;
            break;
          }
          if (pach) {
            cout << 57 << endl;
            break;
          }
          if (shat) {
            cout << 77 << endl;
            break;
          }
          shat++;
        }
      }
    }
  }
}
