#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int num[1000];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  int ii;
  int numm;
  for (int i = 0; i < n; i++) {
    if (num[i] % 3 == 0)
      continue;
    else if (num[i] % 10 == 3)
      continue;
    else if (num[i] % 3 == 0 && num[i] % 10 == 3)
      continue;
    else {
      cout << num[i] << endl;
      ii = i;
      numm = num[i];
    }
  }
  return 0;
}
