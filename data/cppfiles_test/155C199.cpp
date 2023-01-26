#include <bits/stdc++.h>
using namespace std;
int arr[200001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout.precision(20);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    string o;
    for (int i = 0; i < n; ++i) cin >> p[i];
    cin >> o;
    vector<int> zero;
    vector<int> one;
    for (int i = 0; i < n; ++i) {
      if (o[i] == '1') {
        one.push_back(p[i]);
      } else {
        zero.push_back(p[i]);
      }
    }
    sort(zero.begin(), zero.end());
    sort(one.begin(), one.end());
    int index = 1;
    for (int i = 0; i < zero.size(); ++i) {
      arr[zero[i]] = index++;
    }
    for (int i = 0; i < one.size(); ++i) {
      arr[one[i]] = index++;
    }
    for (int i = 0; i < n; ++i) {
      cout << arr[p[i]] << " ";
    }
    cout << endl;
  }
  return 0;
}
