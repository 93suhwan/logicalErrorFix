#include <bits/stdc++.h>
using namespace std;
int main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    long long i, j = 1;
    cout << "2 ";
    for (i = 1; i < n; i++) {
      j += 2;
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}
