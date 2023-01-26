#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr, l, r;
int main() {
  cin >> n;
  arr.resize(n);
  l.resize(n);
  r.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  l[n - 1] = 1;
  r[0] = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1])
      r[i] = r[i - 1] + 1;
    else
      r[i] = 1;
  }
  for (int i = n - 2; i >= 0; i--) {
    if (arr[i] < arr[i + 1])
      l[i] = l[i + 1] + 1;
    else
      l[i] = 1;
  }
  int a = 0, b = n - 1;
  int prev = -1;
  int c = 0;
  for (; a <= b;) {
    if (arr[a] <= prev && arr[b] <= prev) {
      if (c % 2) {
        cout << "Bob";
      } else
        cout << "Alice";
      exit(0);
    } else if (arr[a] <= prev) {
      if ((c + r[b]) % 2) {
        cout << "Bob";
      } else
        cout << "Alice";
      exit(0);
    } else if (arr[b] <= prev) {
      if ((c + l[a]) % 2) {
        cout << "Bob";
      } else
        cout << "Alice";
      exit(0);
    } else {
      if (arr[b] > arr[a] && r[b] % 2 == 1) {
        if (c % 2) {
          cout << "Bob";
        } else
          cout << "Alice";
        exit(0);
      } else if (arr[a] > arr[b] && l[a] % 2 == 1) {
        if (c % 2) {
          cout << "Bob";
        } else
          cout << "Alice";
        exit(0);
      } else if (arr[a] == arr[b]) {
        if (l[a] % 2 == 1 || r[b] % 2 == 1) {
          if (c % 2) {
            cout << "Bob";
          } else
            cout << "Alice";
          exit(0);
        } else {
          if (c % 2) {
            cout << "Alice";
          } else
            cout << "Bob";
          exit(0);
        }
      } else {
        if (arr[a] < arr[b]) {
          a++;
          prev = arr[a];
        } else {
          b++;
          prev = arr[b];
        }
      }
    }
    c++;
  }
}
