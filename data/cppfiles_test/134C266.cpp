#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    std::vector<long long int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    long long int op1 = 0;
    for (int i = 0; i < n; i = i + 2) {
      op1 = gcd(op1, arr[i]);
    }
    bool flag = true;
    for (int i = 1; i < n; i = i + 2) {
      if (arr[i] % op1 == 0) flag = false;
    }
    if (flag == true) {
      cout << op1 << "\n";
      continue;
    }
    long long int op2 = 0;
    for (int i = 1; i < n; i = i + 2) op2 = gcd(op2, arr[i]);
    flag = true;
    for (int i = 0; i < n; i = i + 2) {
      if (arr[i] % op2 == 0) {
        flag = false;
        break;
      }
    }
    if (flag == true) {
      cout << op2 << "\n";
      continue;
    }
    cout << "0\n";
  }
  return 0;
}
