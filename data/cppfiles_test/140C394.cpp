#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int ans = 0;
    set<long long int> st;
    for (int i = 1; i <= sqrt(n); i++) st.insert(i * i);
    for (int i = 1; i <= cbrt(n); i++) st.insert(i * i * i);
    cout << st.size() << endl;
  }
  return 0;
}
