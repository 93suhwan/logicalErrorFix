#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    vector<int> v;
    for (int i = 0; i < 7; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    vector<int> vec;
    for (int i = 0; i < 6; i++) {
      vec.push_back(v[6] - v[i]);
    }
    reverse(vec.begin(), vec.end());
    for (int i = 0; i < 6; i++) {
      if ((vec[0] + vec[1] >= vec[i + 2] || vec[1] + vec[i + 2] >= v[0] ||
           vec[i + 2] + vec[0] >= vec[1]) &&
          vec[0] + vec[1] + vec[i + 2] == v[6]) {
        cout << vec[0] << " " << vec[1] << " " << vec[i + 2] << endl;
        break;
      }
    }
  }
}
