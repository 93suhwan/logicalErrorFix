#include <bits/stdc++.h>
using namespace std;
void AboTupoi() {
  long long n, a;
  cin >> n;
  long long cnt = 0;
  char c;
  for (int i = 0; i < n; i++) {
    cin >> c;
    a = 0;
    if (c != '0') {
      if (c == '1')
        a = 1;
      else if (c == '2')
        a = 2;
      else if (c == '3')
        a = 3;
      else if (c == '4')
        a = 4;
      else if (c == '5')
        a = 5;
      else if (c == '6')
        a = 6;
      else if (c == '7')
        a = 7;
      else if (c == '8')
        a = 8;
      else if (c == '9')
        a = 9;
    }
    if (i != n - 1 && a != 0) a++;
    cnt += a;
  }
  cout << cnt << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    AboTupoi();
  }
}
