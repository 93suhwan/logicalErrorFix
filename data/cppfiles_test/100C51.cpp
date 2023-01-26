#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      int x;
      cin >> x;
      cout << x << '\n';
    } else {
      int mas[n];
      for (int i = 0; i < n; i++) {
        cin >> mas[i];
      }
      sort(mas, mas + n);
      int sum = mas[0], y = -1000000001;
      for (int i = 1; i < n; i++) {
        mas[i] -= sum;
        y = max({y, mas[i - 1], mas[i]});
        sum += mas[i];
      }
      cout << y << '\n';
    }
  }
}
