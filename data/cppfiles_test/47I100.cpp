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
  while (comp < arr.size() && negComp < negArr.size()) {
    if (arr[min(comp + k - 1, (int)arr.size() - 1)] <=
        negArr[min(negComp + k - 1, (int)negArr.size() - 1)]) {
      res += arr[min(comp + k - 1, (int)arr.size() - 1)] * 2;
      comp += min(k, (int)arr.size() - comp);
    } else {
      res += negArr[min(negComp + k - 1, (int)negArr.size() - 1)] * 2;
      negComp += min(k, (int)negArr.size() - negComp);
    }
  }
  if (comp < arr.size()) {
    res += arr[arr.size() - 1];
    arr.resize(max((int)arr.size() - k, 0));
  }
  while (comp < arr.size()) {
    oldComp = comp;
    comp += min(k, (int)arr.size() - comp);
    res += arr[min(oldComp + k - 1, (int)arr.size() - 1)] * 2;
  }
  if (negComp < negArr.size()) {
    res += negArr[negArr.size() - 1];
    negArr.resize(max((int)negArr.size() - k, 0));
  }
  while (negComp < negArr.size()) {
    oldComp = negComp;
    negComp += min(k, (int)negArr.size() - negComp);
    res += negArr[min(oldComp + k - 1, (int)negArr.size() - 1)] * 2;
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
