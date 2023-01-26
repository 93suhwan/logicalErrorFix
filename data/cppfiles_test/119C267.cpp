#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int test;
  cin >> test;
  while (test--) {
    long long int name;
    cin >> name;
    long long int chodna[name];
    long long int c1 = 0, c2 = 0;
    for (int i = 0; i < name; i++) {
      cin >> chodna[i];
      c1 = c1 + chodna[i];
    }
    if (c1 % name != 0)
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
