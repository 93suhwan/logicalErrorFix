#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string arr[N];
bool cmp(string x, string y) {
  for (int i = 0; i < x.size(); ++i) {
    if (x[i] < y[i] && i & 1) {
      return x > y;
    }
    if (x[i] < y[i] && !(i & 1)) {
      return x < y;
    }
    if (x[i] > y[i] && i & 1) {
      return x > y;
    }
    if (x[i] > y[i] && !(i & 1)) {
      return x < y;
    }
  }
  return x < y;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(arr, arr + n, cmp);
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << endl;
  }
  return 0;
}
