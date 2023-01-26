#include <bits/stdc++.h>
using namespace std;
void generate(string s, long long op, long long cl, vector<string> &res,
              long long n) {
  if (op == 0 && cl == 0) {
    res.push_back(s);
    return;
  }
  if (res.size() == n) return;
  if (op) {
    generate(s + '(', op - 1, cl, res, n);
  }
  if (res.size() == n) return;
  if (op < cl) {
    generate(s + ')', op, cl - 1, res, n);
  }
  if (res.size() == n) return;
}
vector<string> solve(long long n) {
  vector<string> res;
  generate("", n, n, res, n);
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    vector<string> res;
    res = solve(n);
    for (long long i = 0; i < n; i++) {
      cout << res[i] << endl;
    }
    cout << "size " << res.size() << endl;
  }
}
