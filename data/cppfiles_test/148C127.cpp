#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print(T t) {
  for (const auto &e : t) cout << e << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int TC = 1;
  cin >> TC;
  for (long long int tc = 1; tc <= TC; tc++) {
    long long int w, h;
    cin >> w >> h;
    long long int x1, x2;
    cin >> x1;
    long long int ans1, ans2, ans3, ans4;
    vector<long long int> a1(x1);
    for (long long int i = 0; i < x1; i++) cin >> a1[i];
    cin >> x2;
    vector<long long int> a2(x2);
    for (long long int i = 0; i < x2; i++) cin >> a2[i];
    long long int y1, y2;
    cin >> y1;
    vector<long long int> b1(y1);
    for (long long int i = 0; i < y1; i++) cin >> b1[i];
    cin >> y2;
    vector<long long int> b2(y2);
    for (long long int i = 0; i < y2; i++) cin >> b2[i];
    ans1 = (a1.back() - a1.front()) * h;
    ans2 = (a2.back() - a2.front()) * h;
    ans3 = (b1.back() - b1.front()) * w;
    ans4 = (b2.back() - b2.front()) * w;
    cout << max(ans1, max(ans2, max(ans3, ans4))) << "\n";
  }
  return 0;
}
