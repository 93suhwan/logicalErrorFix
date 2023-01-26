#include <bits/stdc++.h>
using namespace std;
int T;
long long n1, n2;
string n;
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    n1 = n2 = 0;
    for (int i = 0; i < n.length(); i += 2) n1 = n1 * 10 + n[i] - '0';
    for (int i = 1; i < n.length(); i += 2) n2 = n2 * 10 + n[i] - '0';
    if (!n2)
      cout << n1 - 1 << endl;
    else
      cout << (n1 + 1) * (n2 + 1) - 2 << endl;
  }
  return 0;
}
