#include <bits/stdc++.h>
using namespace std;
bool composite(int sum) {
  int count = 0;
  for (int i = 2; i <= sum; i++) {
    if (sum % i == 0) {
      count += 1;
    }
    if (count == 2) {
      return true;
    }
  }
  return false;
}
int findSum(int n, int arr[]) {
  int s = 0;
  for (int i = 0; i < n; i++) {
    s += arr[i];
  }
  return s;
}
vector<int> solve(int n, int arr[]) {
  vector<int> res;
  int sum = findSum(n, arr);
  int tempSum = sum;
  if (composite(sum) == true) {
    for (int i = 1; i <= n; i++) {
      res.push_back(i);
    }
    return res;
  } else {
    for (int i = 0; i < n; i++) {
      sum = sum - arr[i];
      if (composite(sum) == true) {
        for (int j = 0; j < n; j++) {
          if (j == i) {
            continue;
          }
          res.push_back(j + 1);
        }
        return res;
      }
      sum = tempSum;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    vector<int> res = solve(n, arr);
    for (auto it : res) {
      cout << it << " ";
    }
    cout << "\n";
  }
}
