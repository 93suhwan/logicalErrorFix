#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long x, n;
    cin >> x >> n;
    if (n == 0) {
      cout << x << endl;
      continue;
    }
    long long xxx = n - 1;
    long long t2 = xxx % 4;
    long long temp = (xxx / 4);
    long long n1, n2, n3, n4;
    if (t2 == 0) {
      n1 = n2 = n3 = n4 = temp;
    } else if (t2 == 1) {
      n1 = temp + 1;
      n2 = n3 = n4 = temp;
    } else if (t2 == 2) {
      n1 = n2 = (temp + 1);
      n3 = n4 = temp;
    } else if (t2 == 3) {
      n1 = n2 = n3 = (temp + 1);
      n4 = temp;
    }
    long long s1 = (n1 * (4 * n1)) / 2;
    long long s2 = (n2 * (2 + 4 * n2)) / 2;
    long long s3 = (n3 * (4 + 4 * n3)) / 2;
    long long s4 = (n4 * (6 + 4 * n4)) / 2;
    if (x % 2 == 0) {
      x += s1 + s2;
      x -= (1 + s3 + s4);
    } else {
      x += (1 + s3 + s4);
      x -= (s1 + s2);
    }
    cout << x << endl;
  }
}
