#include <bits/stdc++.h>
using namespace std;
int a[100000];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  bool check = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] <= a[i - 1]) {
      check = 1;
    }
  }
  if (n % 2 == 0 || check == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin >> test;
  for (int i = 0; i < test; i++) solve();
}
