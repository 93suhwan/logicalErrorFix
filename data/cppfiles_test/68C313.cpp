#include <bits/stdc++.h>
using namespace std;
int n;
int k;
int main() {
  cin >> n;
  while (n--) {
    cin >> k;
    int sum = 1;
    int i = 1;
    int tmp = 1;
    while (sum < k) {
      sum += i;
      if (sum > k) {
        sum -= i;
        break;
      }
      i += 2;
      tmp++;
    }
    if (sum + tmp - 1 >= k) {
      cout << k - sum + 1 << " " << tmp << endl;
    } else {
      cout << tmp << " " << tmp - (k - sum - tmp + 1) << endl;
    }
  }
  return 0;
}
