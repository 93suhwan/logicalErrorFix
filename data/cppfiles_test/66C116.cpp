#include <bits/stdc++.h>
using namespace std;
int a[1050];
void gen() {
  int num = 1;
  int idx = 1;
  int n = 1010;
  while (n--) {
    if (num % 3 == 0 || num % 10 == 3) {
      num++;
      n++;
    } else {
      a[idx] = num;
      num++;
      idx++;
    }
  }
}
int main() {
  gen();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << a[n] << endl;
  }
  return 0;
}
