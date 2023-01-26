#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &output, const vector<T> &v) {
  if (v.empty()) return output;
  for (int i = 0; i < v.size() - 1; i++) output << v[i] << " ";
  output << v.back();
  return output;
}
template <typename T>
istream &operator>>(istream &input, vector<T> &v) {
  for (auto &i : v) cin >> i;
  return input;
}
void __sol() {
  int n;
  cin >> n;
  deque<int> d;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    d.push_back(x);
  }
  int f = 0;
  int last = INT_MIN;
  while (!d.empty()) {
    if (last >= max(d.front(), d.back())) break;
    if (d.size() == 1) {
      last = d.back();
      d.pop_back();
    } else {
      if (d.front() == d.back()) {
        int x = d.front();
        d.pop_front();
        int y = d.back();
        d.pop_back();
        if (d.empty()) {
          last = x;
          d.push_back(x);
        } else {
          if (d.front() <= d.back()) {
            last = x;
            d.push_back(y);
          } else {
            last = y;
            d.push_front(x);
          }
        }
      } else {
        if (d.front() > d.back()) {
          last = d.front();
          d.pop_front();
        } else {
          last = d.back();
          d.pop_back();
        }
      }
    }
    f ^= 1;
  }
  if (f)
    cout << "Alice";
  else
    cout << "Bob";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  while (tc--) __sol();
  return 0;
}
