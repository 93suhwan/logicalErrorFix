#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
void solveA() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  if (a[n - 1] == a[0]) {
    return;
  }
  for (long long i = 0; i < n / 2; i++) {
    if (a[0] != a[n - 1 - i]) {
      cout << a[n - 1 - i] << " " << a[0];
    }
    if (i < (n / 2) - 1) {
      cout << endl;
    }
  }
}
int main() {
  long long t;
  cin >> t;
  cin.get();
  while (t > 0) {
    solveA();
    cout << endl;
    t--;
  }
  return 0;
}
