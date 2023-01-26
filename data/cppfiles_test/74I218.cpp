#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a == b) {
      cout << a + 1 << "\n";
      cout << "0 ";
      int start = 2;
      while (a--) {
        cout << start << " ";
        start += 2;
      }
      cout << "\n";
      continue;
    }
    if (a == 0) {
      int v = b / 2;
      if (b % 2 == 0) {
        cout << "1\n";
        cout << b / 2 << " ";
      } else {
        if (b == 1) {
          cout << "1\n";
          cout << "1 ";
        } else {
          cout << "2\n";
          cout << v << " " << v + 1 << " ";
        }
      }
      cout << "\n";
      continue;
    }
    if (b == 0) {
      int v = a / 2;
      if (a % 2 == 0) {
        cout << "1\n";
        cout << a / 2 << " ";
      } else {
        if (a == 1) {
          cout << "1\n";
          cout << "1 ";
        } else {
          cout << "2\n";
          cout << v << " " << v + 1 << " ";
        }
      }
      cout << "\n";
      continue;
    }
    if ((a + b) % 2 == 0) {
      cout << "1\n";
      cout << min(a, b) << "\n";
      continue;
    }
    int size = max(a, b);
    size += 2;
    cout << size << "\n";
    int start = 0;
    while (size--) {
      cout << start << " ";
      start++;
    }
    cout << "\n";
  }
  return 0;
}
