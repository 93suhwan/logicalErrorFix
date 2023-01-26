#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  while (N--) {
    int n, c, m, a = 0;
    cin >> n;
    c = n;
    c = n / 3;
    a = n / 3;
    if (n % 3 == 2) {
      a++;
    } else {
      c += n % 3;
    }
    cout << c << " " << a << endl;
  }
}
