#include <bits/stdc++.h>
using namespace std;
void sol() {
  long long n;
  cin >> n;
  long long x;
  vector<long long> a;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
  }
  long long st = 0, ed = n - 1;
  long long ct = 0, it = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] <= it) {
      it++;
      continue;
    } else {
      ct = ct + a[i] - it;
      it = a[i] + 1;
    }
  }
  cout << ct << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    sol();
  }
}
