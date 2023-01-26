#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve() {
  int n, k, temp, comp, negComp, oldComp;
  ll res;
  cin >> n >> k;
  vector<int> arr, negArr;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    if (temp < 0) {
      negArr.push_back(temp * -1);
    } else {
      arr.push_back(temp);
    }
  }
  sort(arr.begin(), arr.end());
  sort(negArr.begin(), negArr.end());
  comp = negComp = 0;
  res = 0;
  if (negArr.size() && arr.size()) {
    if (arr[arr.size() - 1] >= negArr[negArr.size() - 1]) {
      res += arr[arr.size() - 1];
      arr.resize(max((int)arr.size() - k, 0));
    } else {
      res += negArr[negArr.size() - 1];
      negArr.resize(max((int)negArr.size() - k, 0));
    }
  } else if (arr.size()) {
    res += arr[arr.size() - 1];
    arr.resize(max((int)arr.size() - k, 0));
  } else {
    res += negArr[negArr.size() - 1];
    negArr.resize(max((int)negArr.size() - k, 0));
  }
  while (comp < arr.size()) {
    res += 2 * arr[arr.size() - 1 - comp];
    comp += min(k, (int)arr.size() - comp);
  }
  while (negComp < negArr.size()) {
    res += 2 * negArr[negArr.size() - 1 - negComp];
    negComp += min(k, (int)negArr.size() - negComp);
  }
  cout << res << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
