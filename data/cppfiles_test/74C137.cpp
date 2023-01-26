#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    long long t = a + b;
    long long Na = t / 2;
    long long Nb = t - Na;
    set<long long> st;
    for (int i = 0; i <= min(a, Na); i++) {
      if (Nb + i >= a) {
        st.insert(Na - i + a - i);
      }
    }
    swap(Na, Nb);
    for (int i = 0; i <= min(b, Nb); i++) {
      if (Na + i >= b) {
        st.insert(Nb - i + b - i);
      }
    }
    cout << st.size() << endl;
    for (auto it : st) cout << it << " ";
    cout << endl;
  }
  return 0;
}
