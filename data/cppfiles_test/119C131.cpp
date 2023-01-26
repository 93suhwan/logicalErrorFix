#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      vec.push_back(a);
    }
    long long int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      sum += vec[i];
    }
    if (sum % n == 0) {
      ans = 0;
    } else {
      ans = 1;
    }
    cout << ans << endl;
  }
}
