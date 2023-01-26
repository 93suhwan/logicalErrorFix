#include <bits/stdc++.h>
using namespace std;
int cnt(int n) {
  int cnt1 = 0;
  for (int i = 1; i * i <= n; i++) cnt1++;
  for (int i = 1; i * i * i <= n; i++) cnt1++;
  for (int i = 1; i * i * i * i * i * i <= n; i++) cnt1--;
  return cnt1;
}
int main() {
  int t;
  cin >> t;
  for (int _ = 0; _ < t; _++) {
    int n;
    cin >> n;
    cout << cnt(n) << "\n";
  }
}
