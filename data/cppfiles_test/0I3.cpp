#include <bits/stdc++.h>
using namespace std;
string str[1000000];
long long x;
bool compare1(long long i1, long long i2) { return (str[i1][x] < str[i2][x]); }
bool compare2(long long i1, long long i2) { return (str[i1][x] > str[i2][x]); }
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
  sort(ara, ara + n, compare1);
  x = 1;
  for (i = 1; i < m; i++, x++) {
    l = 0;
    r = 0;
    for (j = 0; j < n - 1; j++) {
      if (str[ara[j]][i - 1] == str[ara[j + 1]][i - 1]) {
        r++;
      } else {
        if (i % 2 == 1) {
          sort(ara + l, ara + r + 1, compare2);
        } else {
          sort(ara + l, ara + r + 1, compare1);
        }
        l = r + 1;
        r = r + 1;
      }
    }
    if (l != r) {
      if (i % 2 == 1) {
        sort(ara + l, ara + r + 1, compare2);
      } else {
        sort(ara + l, ara + r + 1, compare1);
      }
    }
  }
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
