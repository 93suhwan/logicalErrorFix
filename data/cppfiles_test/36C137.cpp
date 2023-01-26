#include <bits/stdc++.h>
using namespace std;
void buildPrimes(vector<int> &composite) {
  for (int i = 2; i <= 20000; i++) {
    if (not composite[i]) {
      for (int j = i * i; j <= 200000; j += i) composite[j]++;
    }
  }
}
void printRes(vector<int> &a) {
  for (int i = 1; i <= 200; i++)
    if (a[i]) cout << a[i] << " ";
  cout << "\n";
}
void solveFn(vector<int> &a, int sum, vector<int> &composite) {
  for (int i = 1; i < 20000; i += 2) {
    if (a[i] && composite[sum - i]) {
      a[i] = 0;
      return;
    }
  }
}
int main() {
  vector<int> composite(200001, 0);
  buildPrimes(composite);
  int tc, n, sum, m;
  cin >> tc;
  while (tc--) {
    cin >> n;
    vector<int> a(201, 0);
    sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> m;
      a[m] = i + 1;
      sum += m;
    }
    if (composite[sum]) {
      cout << n << '\n';
    } else {
      cout << n - 1 << '\n';
      solveFn(a, sum, composite);
    }
    printRes(a);
  }
  return 0;
}
