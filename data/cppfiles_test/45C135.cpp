#include <bits/stdc++.h>
using namespace std;
void fun() {
  long long int co = 0, co1 = 0, co2 = 0, co3 = 0, count = 0, f = 0, f1 = 0,
                f2 = 0, f3 = 0, flag = 0;
  long long int i, j, k, l, m, n, a, b, c, d, x, tmp, temp;
  string s, s1, s2, s3;
  cin >> n;
  long long int arr[n + 10];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  co = 1;
  f = 0;
  for (i = 0; i < n; i++) {
    if (arr[i] == 0) {
      f++;
      co1 = 0;
    } else if (arr[i] == 1) {
      co1++;
      if (co1 > 1)
        co += 5;
      else
        co += 1;
      f = 0;
    }
    if (f == 2) break;
  }
  if (f == 2)
    cout << -1 << endl;
  else
    cout << co << endl;
}
int main() {
  long long int n;
  cin >> n;
  while (n--) fun();
  return 0;
}
