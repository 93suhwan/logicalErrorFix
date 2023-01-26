#include <bits/stdc++.h>
using namespace std;
void print_bracket() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    char arr[2 * n];
    for (int i = 0; i < n; i++) arr[i] = '(';
    for (int i = n; i < 2 * n; i++) arr[i] = ')';
    for (int i = 0; i < 2 * n; i++) cout << arr[i];
    cout << endl;
    long long count = 1;
    for (int i = 1; i < 2 * n - 2; i++) {
      char arr1[2 * n];
      for (int i = 0; i < n; i++) arr1[i] = '(';
      for (int i = n; i < 2 * n; i++) arr1[i] = ')';
      if (count == n) break;
      {
        arr1[i] = arr[2 * n - i - 1];
        arr1[2 * n - i - 1] = arr[i];
      }
      for (int i = 0; i < 2 * n; i++) cout << arr1[i];
      cout << endl;
      count++;
    }
  }
}
void Home_work() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c, m;
    cin >> a >> b >> c >> m;
    if ((a - 1) > b + c + m || (b - 1) > a + c + m || (c - 1) > a + b + m)
      cout << "no" << endl;
    else if (m <= (a + b + c - 3))
      cout << "yes" << endl;
    else
      cout << "no\n";
  }
}
int main() { Home_work(); }
