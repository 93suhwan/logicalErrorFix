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
    int count1 = num / 3;
    int count2 = num - 2 * (num / 3);
    if (count2 - count1 >= 2) {
      count1++;
      count2 -= 2;
    }
    cout << count2 << " " << count1 << "\n";
  }
  return 0;
}
