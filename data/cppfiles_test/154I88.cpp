#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int read() {
  int x;
  cin >> x;
  return x;
}
int arr[3];
void solve() {
  int Max = 0;
  int Sum = 0;
  for (int i = 0; i < 3; i++) {
    arr[i] = read();
    if (arr[i] > Max) Max = i;
    Sum += arr[i];
  }
  printf("%s", Sum - Max == Max ? "YES" : "NO");
}
int main() {
  int t = read();
  while (t--) {
    solve();
  }
  return 0;
}
