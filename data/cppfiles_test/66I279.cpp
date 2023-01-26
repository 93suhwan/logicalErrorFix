#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int numOfTestCase;
  cin >> numOfTestCase;
  vector<int> arr;
  int i = 0, t = 1;
  while (i <= 1000) {
    if (t % 3 != 0 && t % 10 != 0) {
      arr.push_back(t);
      ++i;
    }
    ++t;
  }
  for (int test_case = 0; test_case < numOfTestCase; ++test_case) {
    int n;
    cin >> n;
    cout << arr[n - 1] << endl;
  }
}
