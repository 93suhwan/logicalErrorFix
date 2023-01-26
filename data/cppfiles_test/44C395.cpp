#include <bits/stdc++.h>
using namespace std;
vector<long long int> read(long long int n) {
  vector<long long int> a;
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    a.push_back(x);
  }
  return a;
}
template <typename T>
void showArr(T a) {
  for (auto i : a) cout << i << " ";
  cout << endl;
}
int main() {
  long long int tc;
  tc = 1;
  cin >> tc;
  while (tc--) {
    long long int a, b;
    cin >> a >> b;
    if (abs(a - b) % 2 == 1) {
      cout << -1 << endl;
    } else {
      if (a == 0 and b == 0) {
        cout << 0 << endl;
        continue;
      }
      if (a == b) {
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    }
  }
  return 0;
}
