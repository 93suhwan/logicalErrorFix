#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
using namespace std;
void hyuga(int T) {
  int x1, p1, x2, p2;
  cin >> x1 >> p1 >> x2 >> p2;
  long double x = x1 / long double(x2);
  long long int p = p2 - p1;
  if (log10f(x) > p2 - p1)
    cout << ">\n";
  else if (log10f(x) < p2 - p1)
    cout << "<\n";
  else
    cout << "=\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    hyuga(T);
  }
  return 0;
}
