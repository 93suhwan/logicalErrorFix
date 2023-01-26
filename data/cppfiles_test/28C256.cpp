#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int arr[t][3], num;
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> num;
      arr[i][j] = num;
    }
  }
  for (int i = 0; i < t; i++) {
    if ((arr[i][0] + (2 * arr[i][1]) + (3 * arr[i][2])) % 2 == 0)
      cout << "0" << endl;
    else
      cout << "1" << endl;
  }
  return 0;
}
