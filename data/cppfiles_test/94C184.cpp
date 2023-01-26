#include <bits/stdc++.h>
using namespace std;
int rest[20], dp[20];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> v;
    while (n != 0) {
      v.push_back(n % 10);
      n /= 10;
    }
    reverse(v.begin(), v.end());
    int a = 0, b = 0;
    for (int i = 0; i < v.size(); i++) {
      if (i % 2 == 0) a = a * 10 + v[i];
      if (i % 2 == 1) b = b * 10 + v[i];
    }
    cout << (a + 1) * (b + 1) - 2 << endl;
  }
  return 0;
}
