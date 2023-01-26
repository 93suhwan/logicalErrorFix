#include <bits/stdc++.h>
using std::abs;
using std::cin;
using std::cout;
using std::deque;
using std::greater;
using std::less;
using std::map;
using std::max;
using std::min;
using std::priority_queue;
using std::queue;
using std::sort;
using std::stack;
using std::string;
using std::stringstream;
using std::swap;
using std::vector;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n < 6) n = 6;
    if (n % 2) n++;
    long long ans = n / 2 * 5;
    cout << ans << "\n";
  }
  return 0;
}
