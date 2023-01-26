#include <bits/stdc++.h>
using namespace std;
void IG(vector<vector<long long>>& vec, long long x, long long y) {
  vec[x].push_back(y);
  vec[y].push_back(x);
}
void solution() {
  double n;
  cin >> n;
  long long x = ceil(sqrt(n));
  long long summ = ((x - 1) * (x - 1)) + 1;
  long long sum = x * x;
  long long a = 1;
  long long b = x;
  long long c = summ;
  for (long long i = 0; i < x; i++) {
    if (c == n) {
      cout << a << " " << b;
      return;
    }
    c++;
    a++;
  }
  a = x;
  b = 1;
  for (long long i = 0; i < x - 1; i++) {
    if (n == sum) {
      cout << a << " " << b;
    }
    b++;
    sum--;
  }
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    solution();
    cout << endl;
  }
}
