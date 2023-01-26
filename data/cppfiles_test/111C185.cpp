#include <bits/stdc++.h>
using namespace std;
const int maxx = 100001;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int temp;
    cin >> temp;
    int i, j;
    int flag = temp;
    for (i = 1; i <= temp; i++) {
      for (j = 1; j <= temp; j++) {
        cout << "(";
        if (j == flag) cout << ")";
      }
      for (int k = 1; k < temp; k++) cout << ")";
      cout << endl;
      flag--;
    }
  }
  return 0;
}
