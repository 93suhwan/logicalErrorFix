#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    map<int, int> m;
    vector<int> extra;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] <= n) {
        if (m[arr[i]]) {
          extra.push_back(arr[i]);
        } else {
          m[arr[i]]++;
        }
      } else {
        extra.push_back(arr[i]);
      }
    }
    vector<int> remain;
    for (int i = 1; i <= n; i++) {
      if (!m[i]) {
        remain.push_back(i);
      }
    }
    sort(remain.begin(), remain.end());
    sort(extra.begin(), extra.end());
    int flag = 0;
    for (int i = 0; i < remain.size(); i++) {
      if (remain[i] >= (float)extra[i] / 2) {
        flag = 1;
      }
    }
    if (flag) {
      cout << "-1\n";
    } else {
      cout << remain.size() << endl;
    }
  }
  return 0;
}
