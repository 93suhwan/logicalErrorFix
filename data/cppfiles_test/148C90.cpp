#include <bits/stdc++.h>
using namespace std;
ofstream ou("out.out");
struct nod {
  char val;
  int pos;
};
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int w, h;
    cin >> w >> h;
    long long int n;
    cin >> n;
    vector<long long int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    long long int n1;
    cin >> n1;
    vector<long long int> v1(n1);
    for (int i = 0; i < n1; i++) cin >> v1[i];
    long long int n2;
    cin >> n2;
    vector<long long int> v2(n2);
    for (int i = 0; i < n2; i++) cin >> v2[i];
    long long int n3;
    cin >> n3;
    vector<long long int> v3(n3);
    for (int i = 0; i < n3; i++) cin >> v3[i];
    long long int mx = 0;
    long long int mn = INT_MAX;
    long long int mx1 = 0;
    long long int mn1 = INT_MAX;
    long long int mx2 = 0;
    long long int mn2 = INT_MAX;
    long long int mx3 = 0;
    long long int mn3 = INT_MAX;
    for (int i = 0; i < n; i++) {
      mx = max(mx, v[i]);
      mn = min(mn, v[i]);
    }
    for (int i = 0; i < n1; i++) {
      mx1 = max(mx1, v1[i]);
      mn1 = min(mn1, v1[i]);
    }
    for (int i = 0; i < n2; i++) {
      mx2 = max(mx2, v2[i]);
      mn2 = min(mn2, v2[i]);
    }
    for (int i = 0; i < n3; i++) {
      mx3 = max(mx3, v3[i]);
      mn3 = min(mn3, v3[i]);
    }
    long long int A1 = (mx - mn) * h;
    long long int A2 = (mx1 - mn1) * h;
    long long int A3 = (mx2 - mn2) * w;
    long long int A4 = (mx3 - mn3) * w;
    cout << max(A1, max(A2, max(A3, A4))) << endl;
  }
}
