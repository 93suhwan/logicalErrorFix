#include <bits/stdc++.h>
using namespace std;
long long get_time() {
  return chrono::duration_cast<chrono::nanoseconds>(
             chrono::steady_clock::now().time_since_epoch())
      .count();
}
template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
  bool done_something = false;
  stringstream res;
  res << "[";
  for (; begin_iter != end_iter and counter; ++begin_iter) {
    done_something = true;
    counter--;
    res << *begin_iter << ", ";
  }
  string str = res.str();
  if (done_something) {
    str.pop_back();
    str.pop_back();
  }
  str += "]";
  return str;
}
template <typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T>& p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    out << v[i];
    if (i != (int)v.size() - 1) out << ", ";
  }
  out << "]";
  return out;
}
template <class TH>
void _dbg(const char* name, TH val) {
  clog << name << ": " << val << endl;
}
template <class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
  while (*names != ',') clog << *names++;
  clog << ": " << curr_val << ", ";
  _dbg(names + 1, vals...);
}
const int M = 5;
struct Rank {
  int r[M];
};
bool operator<(const Rank& A, const Rank& B) {
  int cnt = 0;
  for (int i = 0; i < M; i++) cnt += A.r[i] < B.r[i];
  return cnt >= 3;
}
void solve() {
  int n;
  cin >> n;
  vector<Rank> ath(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < M; j++) cin >> ath[i].r[j];
  vector<int> ord(n);
  for (int i = 0; i < n; i++) ord[i] = i;
  unsigned seed = 0;
  shuffle(ord.begin(), ord.end(), default_random_engine(seed));
  for (int i = 0; i < n; i++) {
    bool works = true;
    for (int j = 0; j < n and works; j++) {
      if (i != j) works &= ath[ord[i]] < ath[ord[j]];
    }
    if (works) {
      cout << ord[i] + 1 << "\n";
      return;
    }
  }
  cout << -1 << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  srand(time(NULL));
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) solve();
}
