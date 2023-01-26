#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> v1, v2;
    for (long long int i = 0; i < n; i++) {
      long long int x;
      cin >> x;
      if (i % 2 == 0) {
        v1.push_back(x);
      } else {
        v2.push_back(x);
      }
    }
    long long int val1 = v1[0];
    for (long long int i = 1; i < v1.size(); i++) {
      val1 = gcd(val1, v1[i]);
    }
    long long int val2 = v2[0];
    for (long long int i = 1; i < v2.size(); i++) {
      val2 = gcd(val2, v2[i]);
    }
    long long int flag = 0;
    for (long long int i = 0; i < v2.size(); i++) {
      if (v2[i] % val1 == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      flag = 0;
      for (long long int i = 0; i < v1.size(); i++) {
        if (v1[i] % val2 == 0) {
          cout << 0 << endl;
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        cout << val2 << endl;
      }
    } else {
      cout << val1 << endl;
    }
  }
}
