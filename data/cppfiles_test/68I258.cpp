#include <bits/stdc++.h>
using namespace std;
void print(int a[], int n) {
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;
}
void solve() {
  int n;
  cin >> n;
  int row = ceil(sqrt(n));
  int col = -1;
  if (n <= row * row - row + 1)
    col = row;
  else
    col = row * row + 1 - n;
  cout << row << " " << col << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
