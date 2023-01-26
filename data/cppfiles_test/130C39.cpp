#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 10;
int T, n;
inline bool ask(int a, int b, int c) {
  cout << "? " << a << " " << b << " " << c << endl;
  cout.flush();
  int x;
  cin >> x;
  int ret = (x == 0);
  return ret;
}
int bad[MAXN], B_id, G_id, bad_id, good_id;
void get_id() {
  int r1 = ask(G_id + 1, G_id + 2, B_id);
  int r2 = ask(G_id + 2, B_id, B_id + 1);
  if (r2 == 0)
    good_id = G_id + 2, bad_id = B_id + 2;
  else if (r1 == 1)
    good_id = G_id, bad_id = B_id;
  else
    good_id = G_id + 1, bad_id = B_id + 1;
}
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    vector<int> ans;
    bad_id = good_id = 0;
    for (int i = 1; i <= n; i += 3) {
      bad[i] = ask(i, i + 1, i + 2);
      if (bad[i])
        B_id = i;
      else
        G_id = i;
    }
    get_id();
    for (int i = 1, r1, r2; i <= n; i += 3) {
      if (bad[i]) {
        r1 = ask(i, i + 1, good_id);
        r2 = ask(i, i + 2, good_id);
        if (r1 == 1 && r2 == 1)
          ans.push_back(i), ans.push_back(i + 1), ans.push_back(i + 2);
        if (r1 == 0 && r2 == 1) ans.push_back(i), ans.push_back(i + 2);
        if (r1 == 1 && r2 == 0) ans.push_back(i), ans.push_back(i + 1);
        if (r1 == 0 && r2 == 0) ans.push_back(i + 1), ans.push_back(i + 2);
      } else {
        r1 = ask(i, i + 1, bad_id);
        r2 = ask(i, i + 2, bad_id);
        if (r1 == 1 && r2 == 1) ans.push_back(i);
        if (r1 == 0 && r2 == 1) ans.push_back(i + 2);
        if (r1 == 1 && r2 == 0) ans.push_back(i + 1);
      }
    }
    cout << "! " << ans.size() << " ";
    for (int x : ans) cout << x << " ";
    cout << endl;
    cout.flush();
  }
  return 0;
}
