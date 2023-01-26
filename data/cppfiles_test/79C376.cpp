#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  long long int b[10] = {0};
  b[2] = 1;
  b[3] = 1;
  b[5] = 1;
  b[7] = 1;
  while (t--) {
    long long int n;
    cin >> n;
    string a;
    cin >> a;
    string d;
    d += a;
    sort(a.begin(), a.end());
    long long int x;
    long long int k = 0;
    for (int i = 0; i < a.size(); i++) {
      x = (int)a[i];
      x -= 48;
      if (b[x] == 0) {
        k = 1;
        break;
      }
    }
    if (k == 1) {
      cout << 1 << "\n";
      cout << x << "\n";
      continue;
    }
    string c;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] == a[i + 1]) {
        k = 1;
        c += a[i];
        c += a[i];
        break;
      }
    }
    if (k == 1) {
      cout << 2 << "\n";
      cout << c << "\n";
      continue;
    }
    cout << 2 << "\n";
    k = 0;
    a.clear();
    a += d;
    for (long long int i = 0; i < a.size(); i++) {
      for (long long int j = i + 1; j < a.size(); j++) {
        if (a[i] == '2' && a[j] == '7') {
          cout << 27 << "\n";
          k = 1;
          break;
        } else if (a[i] == '2' && a[j] == '5') {
          cout << 25 << "\n";
          k = 1;
          break;
        } else if (a[i] == '3' && a[j] == '5') {
          cout << 35 << "\n";
          k = 1;
          break;
        } else if (a[i] == '5' && a[j] == '7') {
          cout << 57 << "\n";
          k = 1;
          break;
        } else if (a[i] == '3' && a[j] == '2') {
          cout << 32 << "\n";
          k = 1;
          break;
        } else if (a[i] == '5' && a[j] == '2') {
          cout << 52 << "\n";
          k = 1;
          break;
        } else if (a[i] == '7' && a[j] == '5') {
          cout << 75 << "\n";
          k = 1;
          break;
        } else if (a[i] == '7' && a[j] == '2') {
          cout << 72 << "\n";
          k = 1;
          break;
        } else
          ;
      }
      if (k == 1) break;
    }
  }
  return 0;
}
