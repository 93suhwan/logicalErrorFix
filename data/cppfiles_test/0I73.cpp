#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
string arr[N];
bool cmp(string x, string y) {
  for (int i = 0; i < x.size() - 1; ++i) {
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
    char index = (i + 1) + '0';
    arr[i] += index;
  }
  sort(arr, arr + n, cmp);
  for (int i = 0; i < n; ++i) {
    cout << arr[i][arr[i].size() - 1] << endl;
  }
  return 0;
}
