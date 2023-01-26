#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int z = 0; z < t; z++) {
    long long n, k, a;
    cin >> n >> k;
    vector<long long> v;
    vector<long long> ans;
    for (int i = 0; i < n; i++) {
      cin >> a;
      v.push_back(pow(10, a));
    }
    long long biggest;
    for (int i = 0; i < v.size() - 1; i++) {
      if (v[i + 1] / v[i] < k) {
        ans.push_back((v[i + 1] / v[i] - (long long)1) * v[i]);
        k -= (v[i + 1] / v[i] - (long long)1);
        if (i == v.size() - 2) {
          biggest = v[i + 1];
        }
      } else {
        biggest = v[i];
        break;
      }
    }
    long long finalans = 0;
    for (int i = 0; i < ans.size(); i++) {
      finalans += ans[i];
    }
    finalans += biggest * (k + (long long)1);
    cout << finalans << endl;
  }
}
