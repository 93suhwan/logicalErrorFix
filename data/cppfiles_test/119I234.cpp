#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    long long int avg = 0;
    vector<long long int> vec(n + 1);
    for (long long int i = 0; i < n; i++) {
      cin >> vec[i];
      avg += vec[i];
    }
    if ((avg % n) % 2 == 0)
      cout << 0 << endl;
    else {
      cout << 1 << endl;
    }
  }
  return 0;
}
