#include <bits/stdc++.h>
using namespace std;
int mult(int a, int b) { return a + b; }
int d(int a, int b) { return a - b; }
int ad(int a, int b) { return a * b; }
int main() {
  int test_case;
  cin >> test_case;
  for (int i = 0; i < test_case; i++) {
    int num;
    cin >> num;
    cout << (num + 2) / 3 << ' ' << num / 3 << "\n";
  }
  return 0;
}
