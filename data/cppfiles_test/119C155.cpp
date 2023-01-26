#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, sum = 0;
    cin >> n;
    vector<int> A;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      A.push_back(x);
      sum += x;
    }
    if (sum % n == 0)
      cout << "0";
    else
      cout << "1";
    cout << endl;
  }
  return 0;
}
