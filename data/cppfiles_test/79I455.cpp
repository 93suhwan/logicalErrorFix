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
    long long int two = 0, three = 0, five = 0, seven = 0;
    for (int i = 0; i < a.size(); i++) {
      x = (int)a[i];
      x -= 48;
      if (x == 2)
        two++;
      else if (x == 3)
        three++;
      else if (x == 5)
        five++;
      else if (x == 7)
        seven++;
      else
        ;
    }
    cout << 2 << "\n";
    if (two > 0 && seven > 0)
      cout << 27 << "\n";
    else if (two > 0 && five > 0)
      cout << 25 << "\n";
    else if (three > 0 && five > 0)
      cout << 35 << "\n";
    else
      ;
  }
  return 0;
}
