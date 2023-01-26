#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int cnt = 0;
    cout << "()";
    for (long long int i = 1; i < n; i++) {
      cout << "()";
    }
    cout << endl;
    cnt++;
    if (cnt == n) continue;
    long long int c;
    long long int d = 1;
    for (long long int i = 1; i < n; i++) {
      if ((i + 1) % n == 0) {
        cout << "(())";
        long long int a = (2 * n - 4) / 2;
        for (long long int i = 0; i < a; i++) {
          cout << '(';
        }
        for (long long int i = 0; i < a; i++) {
          cout << ')';
        }
        cout << endl;
      } else {
        for (long long int i = 0; i < d; i++) {
          cout << "()";
        }
        c = ((2 * n) - (d * 2)) / 2;
        d++;
        for (long long int j = 0; j < c; j++) {
          cout << '(';
        }
        for (long long int j = 0; j < c; j++) {
          cout << ')';
        }
        c++;
        cout << endl;
      }
    }
  }
  return 0;
}
