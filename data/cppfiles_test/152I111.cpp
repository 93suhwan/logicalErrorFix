#include <bits/stdc++.h>
using namespace std;
template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;
const long double PI = 3.14159265358979323846;
const long double E = 2.718281828459;
const long double EPS = 1e-8;
long long pow2(long long n) { return 1ll << n; }
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
long long n;
long long idx(long long x, long long y) { return x * 2 * (n + 1) + y; }
pair<long long, long long> rev(long long idx) {
  long long x = idx / (2 * n + 2);
  long long y = idx % (2 * n + 2);
  return {x, y};
}
int main(int argn, char **argv) {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  for (int(I) = (0); (I) <= ((T)-1); (I)++) {
    cin >> n;
    vector<long long> p(n);
    for (int(i) = (0); (i) <= ((n)-1); (i)++) cin >> p[i];
    stack<pair<long long, long long>> st;
    st.emplace(0, 0);
    map<long long, long long> last;
    bool found = true;
    for (int(i) = (0); (i) <= ((n)-1); (i)++) {
      vector<tuple<int, int, int>> vec;
      while (!st.empty()) {
        auto [x, y] = st.top();
        st.pop();
        long long pre = idx(x, y);
        if (x < -p[i] + n + 1)
          vec.emplace_back(-p[i] + n + 1, y, pre);
        else if (x < p[i] + n + 1)
          vec.emplace_back(p[i] + n + 1, y, pre);
        if (y < -p[i] + n + 1)
          vec.emplace_back(x, -p[i] + n + 1, pre);
        else if (y < p[i] + n + 1)
          vec.emplace_back(x, p[i] + n + 1, pre);
      }
      sort((vec).begin(), (vec).end());
      for (auto [x, y, pre] : vec) {
        bool can = true;
        if (!st.empty()) {
          auto [x0, y0] = st.top();
          if (y >= y0) can = false;
        }
        if (can) st.emplace(x, y), last[idx(x, y)] = pre;
      }
      if (st.empty()) {
        found = false;
        break;
      };
    }
    if (found) {
      cout << "YES" << endl;
      vector<long long> sign(n, 1);
      auto [x, y] = st.top();
      long long a = x, b = y;
      long long crt = n - 1;
      while (idx(a, b)) {
        ;
        if (a - (n + 1) + p[crt] == 0) sign[crt] = -1;
        if (b - (n + 1) + p[crt] == 0) sign[crt] = -1;
        long long pre = last[idx(a, b)];
        auto [x, y] = rev(pre);
        a = x, b = y, crt--;
      }
      for (int(i) = (0); (i) <= ((n)-1); (i)++) cout << p[i] * sign[i] << " ";
      cout << endl;
    } else
      cout << "NO" << endl;
  }
}
