#include <bits/stdc++.h>
using namespace std;
string str[1000000];
long long x, y;
bool compare1(long long i1, long long i2) {
  long long j, k;
  for (j = 0; j < x; j++) {
    if (j % 2 == 1) {
      if (str[i1][j] > str[i2][j]) {
        return 1;
      } else if (str[i1][j] < str[i2][j]) {
        return 0;
      }
    } else {
      if (str[i1][j] > str[i2][j]) {
        return 0;
      } else if (str[i1][j] < str[i2][j]) {
        return 1;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m, i, j, k, l, r;
  cin >> n >> m;
  long long ara[n];
  for (i = 0; i < n; i++) {
    cin >> str[i];
    ara[i] = i;
  }
  x = m;
  sort(ara, ara + n, compare1);
  for (i = 0; i < n; i++) {
    cout << ara[i] + 1;
    if (i < n - 1) {
      cout << " ";
    } else {
      cout << "\n";
    }
  }
  return 0;
}
