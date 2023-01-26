#include <bits/stdc++.h>
using namespace std;
void sol() {
  long long n;
  cin >> n;
  vector<int> mon, tue, wed, thu, fri;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 5; j++) {
      long long x;
      cin >> x;
      if (x == 1 && j == 0) {
        mon.push_back(i);
      }
      if (x == 1 && j == 1) {
        tue.push_back(i);
      }
      if (x == 1 && j == 2) {
        wed.push_back(i);
      }
      if (x == 1 && j == 3) {
        thu.push_back(i);
      }
      if (x == 1 && j == 4) {
        fri.push_back(i);
      }
    }
  }
  if (mon.size() >= n / 2 && tue.size() >= n / 2) {
    cout << "YES"
         << "\n";
    return;
  } else if (mon.size() >= n / 2 && wed.size() >= n / 2) {
    cout << "YES"
         << "\n";
    return;
  }
  if (mon.size() >= n / 2 && thu.size() >= n / 2) {
    cout << "YES"
         << "\n";
    return;
  }
  if (mon.size() >= n / 2 && fri.size() >= n / 2) {
    cout << "YES"
         << "\n";
    return;
  }
  if (wed.size() >= n / 2 && tue.size() >= n / 2) {
    cout << "YES"
         << "\n";
    return;
  }
  if (thu.size() >= n / 2 && tue.size() >= n / 2) {
    cout << "YES"
         << "\n";
    return;
  }
  if (fri.size() >= n / 2 && tue.size() >= n / 2) {
    cout << "YES"
         << "\n";
    return;
  }
  if (wed.size() >= n / 2 && thu.size() >= n / 2) {
    cout << "YES"
         << "\n";
    return;
  }
  if (wed.size() >= n / 2 && fri.size() >= n / 2) {
    cout << "YES"
         << "\n";
    return;
  }
  if (thu.size() >= n / 2 && fri.size() >= n / 2) {
    cout << "YES"
         << "\n";
    return;
  }
  cout << "NO"
       << "\n";
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    sol();
  }
  return 0;
}
