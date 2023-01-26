#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  vector<int> abc;
  int a[101];
  cin >> t;
  for (int i = 1; i < 3000; i++) {
    if (i % 10 == 3 || i % 3 == 0) {
      continue;
    } else
      abc.push_back(i);
  }
  for (int i = 0; i < t; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < t; i++) {
    cout << abc[a[i] - 1] << '\n';
  }
}
