#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int> x;
void fill() {
  long long int q = 1;
  x[1] = 1;
  int a = 2;
  for (long long int i = 1; i <= 1000000000;) {
    q++;
    i += a;
    x[i] = q;
    a += 2;
  }
}
int main() {
  int t, inp1, p;
  cin >> t;
  vector<int> cases;
  for (int i = 0; i < t; i++) {
    cin >> inp1;
    cases.push_back(inp1);
  }
  for (int i = 0; i < t; i++) {
    long long int g = (*x.lower_bound(cases[i])).first;
    if (cases[i] == g) {
      cout << g << g << "\n";
    }
    p = 1 + (x[g] - 1) * (x[g]);
    if (cases[i] - p < g - cases[i]) {
      cout << x[p] << x[p] - (cases[i] - (p)) << "\n";
    } else {
      cout << x[g] - (g - cases[i]) << x[g] << "\n";
    }
  }
  return 0;
}
