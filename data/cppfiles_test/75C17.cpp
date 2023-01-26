#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  vector<bool> preWin(n, 1), sufWin(n, 1);
  for (long long &x : a) {
    cin >> x;
  }
  for (long long i = 1; i < n; i++) {
    if (a[i] < a[i - 1]) {
      preWin[i] = preWin[i] ^ preWin[i - 1];
    }
  }
  for (long long i = n - 2; i >= 0; i--) {
    if (a[i] < a[i + 1]) {
      sufWin[i] = sufWin[i] ^ sufWin[i + 1];
    }
  }
  long long l = 0, r = n - 1;
  bool Alice = 0;
  long long cur = -1;
  while (1) {
    string winner = "Bob", loser = "Alice";
    Alice ^= 1;
    if (Alice) {
      swap(winner, loser);
    }
    if (a[l] == a[r]) {
      bool win = 0;
      if (preWin[r] || sufWin[l]) {
        win = 1;
      }
      if (!win) {
        swap(winner, loser);
      }
      cout << winner << "\n";
      return 0;
    }
    if (a[l] > a[r]) {
      if (sufWin[l]) {
        cout << winner << "\n";
        return 0;
      }
      if (a[r] > cur) {
        cur = a[r];
        r--;
      } else {
        cout << loser << "\n";
        return 0;
      }
    } else {
      if (preWin[r]) {
        cout << winner << "\n";
        return 0;
      }
      if (a[l] > cur) {
        cur = a[l];
        l++;
      } else {
        cout << loser << "\n";
        return 0;
      }
    }
  }
  return 0;
}
