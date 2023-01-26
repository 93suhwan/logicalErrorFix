#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, s[200005] = {0}, left = 0, right = 0;
  cin >> a;
  for (int i = 0; i < a; i++) cin >> s[i];
  if (a == 1) {
    cout << "Alice" << endl;
    return 0;
  }
  for (int i = 0; i < a - 1; i++) {
    if (s[i] >= s[i + 1]) {
      left = i + 1;
      break;
    }
    if (i == a - 2) {
      cout << "Alice" << endl;
      return 0;
    }
  }
  for (int i = a - 1; i > 0; i--) {
    if (s[i] >= s[i - 1]) {
      right = a - i;
      break;
    }
    if (i == 1) {
      cout << "Alice" << endl;
      return 0;
    }
  }
  if (left % 2 == 0 && right % 2 == 0)
    cout << "Bob" << endl;
  else
    cout << "Alice" << endl;
  return 0;
}
