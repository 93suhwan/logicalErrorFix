#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  float res = 111;
  char ch = ' ';
  switch (n) {
    case 1:
      cout << "1" << endl;
    case 2:
      cout << "2 3" << endl;
    case 3:
      cout << "2 3 4" << endl;
  }
  long long r;
  if (n > 3) {
    cout << 11 << ch << 111 << ch;
    for (float i = 3; i < n + 1; i++) {
      res = res + pow(10, i);
      r = res;
      cout << r << ch;
    }
  }
  return 0;
}
