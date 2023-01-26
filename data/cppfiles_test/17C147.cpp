#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
void re(T &x) {
  cin >> x;
}
template <class T>
void read(vector<T> &a) {
  for (auto &x : a) re(x);
}
unsigned long long mod = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  int arr[n][5];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> arr[i][j];
    }
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    int find1 = 0;
    for (int j = 0; j < 5; j++) {
      if (arr[ans][j] < arr[i][j]) {
        find1++;
      }
    }
    if (find1 <= 2) {
      ans = i;
    }
  }
  for (int i = 0; i < n; i++) {
    int find1 = 0;
    for (int j = 0; j < 5; j++) {
      if (arr[ans][j] > arr[i][j]) {
        find1++;
      }
    }
    if (find1 >= 3) {
      cout << "-1" << '\n';
      return;
    }
  }
  cout << ans + 1 << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
