#include <bits/stdc++.h>
using namespace std;
long long int GCD(long long int x, long long int y) {
  if (y == 0) return x;
  return GCD(y, x % y);
}
vector<bool> seive_Of_Eratosthenes(long long int n) {
  vector<bool> prime(n + 1, true);
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) {
        prime[i] = false;
      }
    }
  }
  return prime;
}
long long int power(long long int x, long long int y) {
  long long int ans = 1;
  while (y > 0) {
    if (y % 2 == 1) {
      ans = ans * x;
    }
    y = (y >> 1);
    x = x * x;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  int arr[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < k; i++) {
    int row = 0;
    int col;
    cin >> col;
    --col;
    while (row < n) {
      int val = arr[row][col];
      arr[row][col] = 2;
      if (val == 1)
        col++;
      else if (val == 2)
        row++;
      else
        col--;
    }
    cout << col + 1 << " ";
  }
  return 0;
}
