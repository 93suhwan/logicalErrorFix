#include <bits/stdc++.h>
using namespace std;
vector<int> toBinary(int n) {
  vector<int> ans(33, 0);
  int i = 0;
  while (n > 0) {
    ans[i] = n % 2;
    n /= 2;
    i++;
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int p = m + 1;
    vector<int> v1 = toBinary(n);
    vector<int> v2 = toBinary(p);
    vector<int> ans(33, 0);
    for (int i = 32; i >= 0; i--) {
      if (v1[i] == v2[i])
        continue;
      else if (v1[i] == 1)
        break;
      else
        ans[i] = 1;
    }
    int cur = 1;
    int k = 0;
    for (int i = 0; i <= 32; i++) {
      k += cur * ans[i];
      cur *= 2;
    }
    cout << k << endl;
  }
  return 0;
}
