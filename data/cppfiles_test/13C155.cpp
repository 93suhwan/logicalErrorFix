#include <bits/stdc++.h>
using namespace std;
string a;
int main() {
  int n;
  cin >> n;
  while (n--) {
    cin >> a;
    int i1 = 0, j1 = 0, k1 = 0;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] == 'A')
        i1++;
      else if (a[i] == 'B')
        j1++;
      else if (a[i] == 'C')
        k1++;
    }
    if (i1 + k1 == j1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
