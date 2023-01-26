#include <bits/stdc++.h>
using namespace std;
void pre() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    vector<long long int> pos;
    vector<long long int> neg;
    for (long long int i = 0; i < n; i++) {
      if (arr[i] < 0) {
        neg.push_back(-arr[i]);
      } else {
        pos.push_back(arr[i]);
      }
    }
    sort(pos.begin(), pos.end(), greater<long long int>());
    sort(neg.begin(), neg.end(), greater<long long int>());
    long long int ans = 0;
    long long int n1 = pos.size();
    long long int n2 = neg.size();
    for (long long int i = 0; i < n1; i += k) {
      ans += 2 * pos[i];
    }
    for (long long int i = 0; i < n2; i += k) {
      ans += 2 * neg[i];
    }
    if (pos.size() == 0) {
      ans -= neg[0];
    } else if (neg.size() == 0) {
      ans -= pos[0];
    } else if (pos[0] > neg[0]) {
      ans -= pos[0];
    } else {
      ans -= neg[0];
    }
    cout << ans << "\n";
  }
  return 0;
}
