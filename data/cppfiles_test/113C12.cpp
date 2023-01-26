#include <bits/stdc++.h>
using namespace std;
int num_of_digits(int n) {
  int cnt = 0;
  while (n > 0) {
    cnt++;
    n /= 10;
  }
  return cnt;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int x1, p1;
    int x2, p2;
    cin >> x1 >> p1;
    cin >> x2 >> p2;
    int cnt1 = num_of_digits(x1);
    int cnt2 = num_of_digits(x2);
    while (cnt1 < cnt2) {
      cnt1++;
      p1--;
      x1 *= 10;
    }
    while (cnt2 < cnt1) {
      cnt2++;
      p2--;
      x2 *= 10;
    }
    if (cnt1 + p1 == cnt2 + p2) {
      if (x1 == x2)
        cout << "=";
      else if (x1 > x2)
        cout << ">";
      else
        cout << "<";
    } else {
      if (cnt1 + p1 < cnt2 + p2)
        cout << "<";
      else
        cout << ">";
    }
    cout << "\n";
  }
  return 0;
}
