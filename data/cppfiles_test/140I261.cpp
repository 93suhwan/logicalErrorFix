#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
int m;
int c[N];
int cc[N];
int main() {
  cin >> n;
  while (n--) {
    int a;
    cin >> a;
    int sum = 0;
    sum = sqrt(a);
    sum += pow(a, (1.0) / 3);
    for (int i = 1; i <= pow(a, (1.0) / 3); i++) {
      if (abs(sqrt(i) - (int)(sqrt(i) + 0.5)) <= 1e-9 &&
          abs(sqrt(i) - (int)(sqrt(i) + 0.5)) >= -1e-9)
        sum--;
    }
    cout << sum << "\n";
  }
}
