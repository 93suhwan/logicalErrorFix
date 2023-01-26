#include <bits/stdc++.h>
using namespace std;
int t, n;
const int N = 110;
long long a[N];
bool flag1, flag2;
long long judge(long long num) {
  if (num % 3 == 0) return num / 3;
  long long sum = num / 3;
  long long s = num % 3;
  if (s % 3 == 1) flag1 = true;
  if (s % 3 == 2) flag2 = true;
  return sum;
}
int main() {
  cin >> t;
  while (t--) {
    bool exist_odd = false;
    bool exist_even = false;
    flag1 = false, flag2 = false;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] % 2 != 0) exist_odd = true;
      if (a[i] % 2 == 0) exist_even = true;
    }
    long long mi = -1e9;
    for (int i = 0; i < n; i++) {
      mi = max(judge(a[i]), mi);
    }
    if (n == 1) {
      if (a[0] % 3 != 0) mi++;
      cout << mi << endl;
      continue;
    }
    if ((flag1 && !flag2) || (!flag1 && flag2)) mi++;
    if (flag1 && flag2) mi += 2;
    if (exist_odd == false || exist_even == false) mi--;
    cout << mi << endl;
  }
}
