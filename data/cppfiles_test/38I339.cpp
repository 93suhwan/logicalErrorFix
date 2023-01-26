#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  long long n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    if (n % 2 == 0) {
      cout << n * 2.5 << endl;
    } else {
      n++;
      cout << n * 2.5 << endl;
    }
  }
  return 0;
}
