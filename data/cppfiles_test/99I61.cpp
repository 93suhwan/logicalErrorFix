#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int sum = 0;
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= b; i++) {
      if (a & 1)
        a += i;
      else
        a -= i;
    }
    cout << a << endl;
  }
}
