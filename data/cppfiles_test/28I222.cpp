#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    long long s1 = 0;
    s1 = a + 2 * b + 3 * c;
    cout << s1 % 2 << endl;
  }
  return 0;
}
