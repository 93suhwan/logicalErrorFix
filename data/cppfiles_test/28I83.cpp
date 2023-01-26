#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    long long s1 = 0;
    s1 += a;
    s1 += 2 * b;
    s1 += 3 * c;
    s1 %= 2;
    cout << s1 << endl;
  }
  return 0;
}
