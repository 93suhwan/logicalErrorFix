#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int testcase;
  cin >> testcase;
  while (testcase--) {
    int range = 7;
    int array[7];
    for (int i = 0; i < range; i++) cin >> array[i];
    sort(array, array + range);
    int a = array[0];
    int b = array[1];
    int c;
    int sln = 0;
    for (int i = 2; i < range; i++) {
      int val = array[i];
      int sum_1 = val + a;
      int sum_2 = val + b;
      int sum_3 = val + a + b;
      int sum_4 = a + b;
      bool first_cond = false;
      bool second_cond = false;
      bool third_cond = false;
      bool forth_cond = false;
      for (int j = 0; j < range; j++) {
        if (i != j) {
          if (sum_1 == array[j]) first_cond = true;
          if (sum_2 == array[j]) second_cond = true;
          if (sum_3 == array[j]) third_cond = true;
          if (sum_4 == array[j]) forth_cond = true;
        }
      }
      if (first_cond && second_cond && third_cond && forth_cond) {
        c = val;
        break;
      }
    }
    cout << a << " " << b << " " << c << endl;
  }
  return 0;
}
