#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      long long int x;
      cin >> x;
      a.push_back(x);
    }
    long long sum = accumulate(a.begin(), a.end(), 0);
    if (sum % n == 0) {
      cout << "0" << endl;
    } else {
      cout << "1" << endl;
    }
  }
  return 0;
}
