#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string n;
    cin >> n;
    int k;
    cin >> k;
    map<char, int> used;
    int l = (int)n.size();
    if (l == 1) {
      cout << n << "\n";
      continue;
    }
    int cnt = 1;
    int pos = 0;
    used[n[0]] = 1;
    char curmx = n[0];
    for (int i = 1; i < l; i++) {
      if (cnt > k) {
        break;
      }
      if (n[i] != '9') {
        if (!used[n[i] + 1] && cnt == k && curmx < n[i] + 1) {
        } else {
          pos = i;
        }
      }
      if (!used[n[i]]) {
        cnt++;
        used[n[i]] = 1;
      }
      curmx = max(curmx, n[i]);
    }
    if (cnt <= k) {
      cout << n << '\n';
      continue;
    }
    set<char> st;
    for (int i = 0; i < pos; i++) {
      cout << n[i];
      st.insert(n[i]);
    }
    if ((int)st.size() == k) {
      cout << *st.lower_bound(n[pos] + 1);
    } else {
      st.insert(n[pos] + 1);
      cout << (char)(n[pos] + 1);
    }
    if ((int)st.size() < k) {
      for (int i = pos + 1; i < l; i++) {
        cout << 0;
      }
    } else {
      for (int i = pos + 1; i < l; i++) {
        cout << *st.begin();
      }
    }
    cout << "\n";
  }
  return 0;
}
