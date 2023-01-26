#include <bits/stdc++.h>
using namespace std;
template <typename T, typename T_iterable>
vector<pair<T, int>> run_length_encoding(const T_iterable &items) {
  vector<pair<T, int>> encoding;
  T previous;
  int count = 0;
  for (const T &item : items)
    if (item == previous) {
      count++;
    } else {
      if (count > 0) encoding.emplace_back(previous, count);
      previous = item;
      count = 1;
    }
  if (count > 0) encoding.emplace_back(previous, count);
  return encoding;
}
void run_case() {
  int N, K;
  int64_t X;
  string S;
  cin >> N >> K >> X >> S;
  X--;
  vector<pair<char, int>> encoding = run_length_encoding<char>(S);
  vector<int64_t> bases;
  for (auto &pr : encoding)
    if (pr.first == '*') bases.push_back(pr.second * K + 1);
  vector<int64_t> B;
  while (!bases.empty()) {
    B.push_back(X % bases.back());
    X /= bases.back();
    bases.pop_back();
  }
  string ans;
  for (auto &pr : encoding)
    if (pr.first == '*') {
      ans += string(B.back(), 'b');
      B.pop_back();
    } else {
      ans += string(pr.second, pr.first);
    }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tests;
  cin >> tests;
  while (tests-- > 0) run_case();
}
