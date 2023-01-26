#include <bits/stdc++.h>
using namespace std;
const long double Pi = acos(-1);
int nofdigits(int n) {
  int coun = 0;
  while (n != 0) {
    n = n / 10;
    coun++;
  }
  return coun;
}
void solve() {
  int n, k;
  cin >> n >> k;
  int num = n;
  vector<int> v;
  while (num != 0) {
    v.push_back(num % 10);
    num = num / 10;
  }
  reverse(v.begin(), v.end());
  if (k == 1) {
    int dif[2];
    memset(dif, -1, sizeof(dif));
    int number_of_digits = nofdigits(n);
    dif[0] = n / pow(10, number_of_digits - 1);
    for (int i = number_of_digits - 2; i > -1; i--) {
      int tmp = n / pow(10, i);
      if (tmp % 10 != dif[0]) {
        dif[1] = tmp % 10;
        break;
      }
    }
    if (dif[1] == -1)
      cout << n << "\n";
    else {
      if (dif[1] < dif[0]) {
        for (int i = 0; i < number_of_digits; i++) cout << dif[0];
      } else {
        for (int i = 0; i < number_of_digits; i++) cout << (dif[0] + 1);
      }
      cout << "\n";
    }
  }
  if (k == 2) {
    int dif[10];
    memset(dif, -1, sizeof(dif));
    int number_of_digits = nofdigits(n);
    dif[0] = n / pow(10, number_of_digits - 1);
    int pos[10];
    int curr = 0;
    for (int i = number_of_digits - 2; i > -1; i--) {
      int tmp = n / pow(10, i);
      if (tmp % 10 != dif[curr] && tmp % 10 != dif[0]) {
        dif[curr + 1] = tmp % 10;
        pos[curr] = number_of_digits - i - 1;
        curr++;
      }
    }
    if (dif[2] == -1)
      cout << n << "\n";
    else {
      int a = min(dif[0], dif[1]);
      int b = max(dif[0], dif[1]);
      if (dif[2] < a) {
        for (int i = 0; i < pos[1]; i++) cout << v[i];
        for (int i = pos[1]; i < number_of_digits; i++) cout << a;
      } else if (dif[2] > a && dif[2] < b) {
        for (int i = 0; i < pos[1]; i++) cout << v[i];
        for (int i = pos[1]; i < number_of_digits; i++) cout << b;
      } else {
        for (int i = 0; i < pos[0]; i++) cout << dif[0];
        cout << (dif[1] + 1);
        if (dif[1] + 1 != dif[0])
          for (int i = pos[0] + 1; i < number_of_digits; i++) cout << a;
        else
          for (int i = pos[0] + 1; i < number_of_digits; i++) cout << 0;
      }
      cout << "\n";
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
