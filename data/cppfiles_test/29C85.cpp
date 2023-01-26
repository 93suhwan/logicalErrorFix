#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int testcases = 1;
  cin >> testcases;
  while (testcases--) {
    int num;
    int m1 = 0, m2 = 0;
    cin >> num;
    vector<int> q(num);
    for (int i = 0; i < num; i++) {
      cin >> q[i];
      if (q[i] == 1) {
        m1++;
      }
      if (q[i] == 0) {
        m2++;
      }
    }
    long long int res = (long long)m1;
    for (int i = 0; i < m2; i++) {
      res *= 2;
    }
    cout << res << endl;
  }
}
