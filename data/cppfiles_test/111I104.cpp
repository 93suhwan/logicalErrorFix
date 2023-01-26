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
    cout << "()";
    long long int c = 2;
    for (long long int i = 1; i < n; i++) {
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
  return 0;
}
