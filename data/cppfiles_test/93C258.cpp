#include <bits/stdc++.h>
using namespace std;
using namespace std;
static int computeXOR(int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int testcase = 0;
  cin >> testcase;
  while (testcase--) {
    int a, b;
    cin >> a >> b;
    int val1 = computeXOR(a - 1);
    int val2 = computeXOR(a);
    if (val2 == b) {
      cout << a + 2 << endl;
      continue;
    } else if (val1 == b) {
      cout << a << endl;
      continue;
    } else {
      cout << a + 1 << endl;
      continue;
    }
  }
  return 0;
}
