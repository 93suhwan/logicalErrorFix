#include <bits/stdc++.h>
using namespace std;
bool isComposite(int n) {
  if (n == 1) return true;
  if (n <= 1) return false;
  if (n <= 3) return false;
  if (n % 2 == 0 || n % 3 == 0) return true;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return true;
  return false;
}
int i, j, k;
int a;
int main() {
  int t, n, i;
  cin >> t;
  long long l, r, a, b, res;
  string num;
  while (t--) {
    bool found = false;
    cin >> n >> num;
    for (i = 0; i < n; i++) {
      if (num[i] == '1' || num[i] == '4' || num[i] == '6' || num[i] == '8' ||
          num[i] == '9') {
        found = true;
        cout << "1\n" << num[i] << endl;
        break;
      }
    }
    if (!found) {
      for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
          int bc = (num[i] - '0') * 10 + (num[j] - '0');
          if (isComposite(bc)) {
            found = true;
            cout << "2\n" << bc << endl;
            break;
          }
        }
        if (found) break;
      }
    }
    if (!found) cout << "3\n" << num.substr(0, 3) << endl;
  }
}
