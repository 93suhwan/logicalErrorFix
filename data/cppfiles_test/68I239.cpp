#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::ios_base;
using std::max;
using std::min;
using std::priority_queue;
using std::sort;
using std::stack;
using std::string;
using std::vector;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  for (; t > 0; --t) {
    int k;
    cin >> k;
    if (k == 1) {
      cout << "1 1\n";
    } else {
      int temp = 1;
      int x = 1;
      while (temp < k) {
        k -= temp;
        temp += 2;
        x++;
      }
      if (k <= (x + 1) / 2) {
        cout << k << " " << x << "\n";
      } else {
        cout << x << " " << 2 * x - k << "\n";
      }
    }
  }
  return 0;
}
