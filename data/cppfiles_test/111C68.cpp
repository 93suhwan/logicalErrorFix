#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    n *= 2;
    if ((n / 2) % 2 || n == 4) {
      for (int j = 0; j < n / 2; j++) cout << '(';
      for (int j = n / 2; j < n; j++) cout << ')';
      cout << endl;
    }
    for (int i = 1; i <= n / 4; i++) {
      for (int j = 0; j < n / 2 - i; j++) cout << '(';
      for (int j = n / 2 - i; j < n / 2; j++) cout << ')';
      for (int j = n / 2; j < n / 2 + i; j++) cout << '(';
      for (int j = n / 2 + i; j < n; j++) cout << ')';
      cout << endl;
    }
    if (n != 4) {
      for (int i = 1; i <= n / 4; i++) {
        for (int j = 0; j < i; j++) cout << "()";
        for (int j = 0; j < n / 2 - 2 * i; j++) cout << '(';
        for (int j = 0; j < n / 2 - 2 * i; j++) cout << ')';
        for (int j = 0; j < i; j++) cout << "()";
        cout << endl;
      }
    }
  }
}
