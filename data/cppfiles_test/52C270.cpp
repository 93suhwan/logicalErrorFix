#include <bits/stdc++.h>
using namespace std;
const int maxx = 1e9 + 7;
long long power(int n, int r) {
  if (r == 1) {
    return n;
  } else if (r == 0) {
    return 1;
  }
  return (n * power(n, r - 1)) % maxx;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    vector<int> binary;
    while (b > 0) {
      int sm = b % 2;
      b = b / 2;
      if (sm) {
        binary.push_back(1);
      } else {
        binary.push_back(0);
      }
    }
    long long sum = 0;
    for (int i = 0; i < binary.size(); i++) {
      if (binary[i]) {
        sum = (sum + power(a, i)) % maxx;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
