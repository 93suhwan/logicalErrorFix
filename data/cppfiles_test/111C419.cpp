#include <bits/stdc++.h>
const double PI = acos(-1);
using namespace std;
const int N = 200010;
int n;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i - 1; j++) cout << "()";
      for (int j = 1; j <= n - i + 1; j++) cout << "(";
      for (int j = 1; j <= n - i + 1; j++) cout << ")";
      cout << endl;
    }
  }
  return 0;
}
