#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long i = 1, temp, row = 1, col = 1;
  while (i * i < n) {
    i++;
  }
  temp = i * i - i + 1;
  if (i * i == n) {
    row = i, col = 1;
  } else if (n > temp) {
    col = i - (n - temp);
    row = i;
  } else if (n < temp) {
    col = i;
    row = i - (temp - n);
  }
  cout << row << " " << col << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
