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
  function<void(vector<int>)> output = [&](vector<int> A) {
    cout << "! ";
    for (int i = 0; i < n; i++) {
      cout << A[i] << " ";
    }
    cout << endl;
  };
  vector<int> P(n, 0);
  vector<int> V(n);
  for (int i = 2; i <= n; i++) {
    fill(V.begin(), V.end(), i);
    V[n - 1] = 1;
    int k = qry(V);
    if (k == 0) {
      P[n - 1] = i - 1;
      break;
    } else {
      P[k - 1] = 1 - i;
    }
  }
  for (int i = 1; i < n; i++) {
    fill(V.begin(), V.end(), i);
    V[n - 1] = 5;
    int k = qry(V);
    if (k != 0) {
      P[k - 1] = n - i;
    }
  }
  for (int i = 0; i + 1 < n; i++) {
    P[i] += P[n - 1];
  }
  output(P);
  return 0;
}
