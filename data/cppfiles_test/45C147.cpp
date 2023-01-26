#include <bits/stdc++.h>
using namespace std;
long long n, a, b, p, k;
vector<char> f;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p;
    b = 0;
    f.clear();
    for (int j = 0; j < p; j++) {
      cin >> a;
      if (a % 2 == 0) {
        b++;
        f.push_back('e');
      } else
        f.push_back('o');
    }
    if (abs(p - 2 * b) > 1)
      cout << -1 << endl;
    else if (b > p - b) {
      long long res = 0;
      k = 1;
      for (int j = 0; j < p; j++) {
        if (f[j] != 'o')
          continue;
        else {
          res += abs(k - j);
          k += 2;
        }
      }
      cout << res << endl;
    } else if (b < p - b) {
      long long res = 0;
      k = 1;
      for (int j = 0; j < p; j++) {
        if (f[j] != 'e')
          continue;
        else {
          res += abs(k - j);
          k += 2;
        }
      }
      cout << res << endl;
    } else if (b == p - b) {
      long long res1 = 0, res2 = 0;
      k = 1;
      for (int j = 0; j < p; j++) {
        if (f[j] != 'o')
          continue;
        else {
          res1 += abs(k - j);
          k += 2;
        }
      }
      k = 0;
      for (int j = 0; j < p; j++) {
        if (f[j] != 'o')
          continue;
        else {
          res2 += abs(k - j);
          k += 2;
        }
      }
      cout << min(res1, res2) << endl;
    }
  }
}
