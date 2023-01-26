#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 5;
int n, t;
char lst1, lst2;
int main() {
  cin >> t;
  srand(time(0));
  while (t--) {
    int n;
    cin >> n;
    if (n == 1)
      cout << "a" << endl;
    else if (n % 2 == 1) {
      for (int i = 1; i <= n / 2 - 1; i++) cout << "a";
      cout << "bc";
      for (int i = 1; i <= n / 2; i++) cout << "a";
      cout << endl;
    } else {
      for (int i = 1; i <= n / 2 - 1; i++) cout << "a";
      cout << "b";
      for (int i = 1; i <= n / 2; i++) cout << "a";
      cout << endl;
    }
  }
  return 0;
}
