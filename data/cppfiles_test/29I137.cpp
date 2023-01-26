#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int N;
  cin >> N;
  while (N--) {
    long int n;
    cin >> n;
    long long int a[n];
    long long int y = 0, x = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 0)
        y++;
      else if (a[i] == 1)
        x++;
    }
    cout << x + x * (pow(2, y) - 1) << endl;
    ;
  }
  return 0;
}
