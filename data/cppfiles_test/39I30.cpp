#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  function<int(vector<int>)> qry = [&](vector<int> A) {
    cout << "? ";
    for (int i = 0; i < n; i++) {
      cout << A[i] << " ";
    }
    cout << endl;
    int k;
    cin >> k;
    return k;
  };
  vector<int> V(n, 2);
  int one = -1;
  for (int i = 0; i < n; i++) {
    V[i] = 1;
    int k = qry(V);
    if (k == 0) {
      one = i;
      break;
    }
    V[i] = 2;
  }
  vector<int> P(n, 0);
  P[one] = 1;
  fill(V.begin(), V.end(), 1);
  for (int i = 2; i <= n; i++) {
    V[one] = i;
    int k = qry(V);
    P[k - 1] = i;
    V[one] = 1;
  }
  cout << "! ";
  for (int i = 0; i < n; i++) {
    cout << P[i] << " ";
  }
  cout << endl;
  return 0;
}
