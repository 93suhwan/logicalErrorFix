#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> lower(n);
  vector<long long> higher(n);
  vector<long long> nums(n);
  for (int i = 0; i < n; ++i) {
    lower[i] = -1;
    higher[i] = -1;
    nums[i] = -1;
  }
  long long lastIndex = 0;
  for (int i = 0; i < n; ++i) {
    cout << "? ";
    for (int j = 0; j < n; ++j) {
      if (i == j)
        cout << "1 ";
      else
        cout << "2 ";
    }
    cout << endl;
    fflush(stdout);
    long long ans;
    cin >> ans;
    if (ans == 0) {
      nums[i] = 0;
      lastIndex = i;
    } else if (ans - 1 != i)
      lower[i] = ans - 1;
    cout << "? ";
    for (int j = 0; j < n; ++j) {
      if (i == j)
        cout << "2 ";
      else
        cout << "1 ";
    }
    cout << endl;
    fflush(stdout);
    cin >> ans;
    if (ans == 0)
      nums[i] = n - 1;
    else if (ans - 1 != i)
      higher[i] = ans - 1;
  }
  for (int i = 1; i < n - 1; ++i) {
    if (higher[lastIndex] != -1) {
      nums[higher[lastIndex]] = i;
      lastIndex = higher[lastIndex];
    } else {
      for (int j = 0; j < n; ++j) {
        if (lower[j] == lastIndex) {
          nums[j] = i;
          lastIndex = j;
          break;
        }
      }
    }
  }
  cout << "! ";
  for (int i = 0; i < n; ++i) {
    cout << nums[i] + 1 << " ";
  }
  cout << endl;
  fflush(stdout);
  return 0;
}
