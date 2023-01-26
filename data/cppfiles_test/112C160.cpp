#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a + b + c - 3 < d)
      cout << "NO";
    else {
      long long int arr[3] = {a, b, c};
      sort(arr, arr + 3);
      long long int k = arr[2] - arr[1] - arr[0];
      if (d + 1 >= k)
        cout << "YES";
      else
        cout << "NO";
    }
    cout << endl;
  }
  return 0;
}
