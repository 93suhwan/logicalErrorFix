#include <bits/stdc++.h>
const bool debugging = 1;
const long long mod = 1e9 + 7;
using namespace std;
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  for (auto v : V) {
    os << v << " ";
  }
  return os << "";
}
template <class T>
ostream &operator<<(ostream &os, vector<vector<T>> V) {
  for (long long i = 0; i < V.size(); i++) {
    for (long long j = 0; j < V[i].size(); j++) {
      os << V[i][j] << " ";
    }
    os << "\n";
  }
  return os << "";
}
template <class T>
ostream &operator<<(ostream &os, set<T> S) {
  for (auto s : S) {
    os << s << " ";
  }
  return os << "";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << P.first << " " << P.second;
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M) {
  os << "\n";
  for (auto m : M) {
    os << m << "\n";
  }
  return os << "";
}
void solve() {
  long long N, M;
  cin >> N >> M;
  long long ptr = 1;
  vector<long long> arr(N);
  vector<long long> ideal(N);
  for (long long i = 0; i < N; i++) {
    cin >> arr[i];
    ideal[i] = ptr;
    ptr++;
  }
  vector<long long> shift(N);
  map<long long, long long> pos;
  for (long long i = 0; i < N; i++) {
    pos[ideal[i]] = i + 1;
  }
  for (long long i = 0; i < N; i++) {
    if (pos[arr[i]] == 0) {
      continue;
    }
    long long index = (N - (pos[arr[i]] - i - 1 + N) % N) % N;
    shift[index]++;
  }
  vector<long long> vals;
  long long ans = 0;
  for (long long i = 0; i < N; i++) {
    if ((N - shift[i] + 1) / 2 <= M) {
      ans++;
      vals.push_back(i);
    }
  }
  cout << ans << " ";
  cout << vals << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long no_of_testcases;
  cin >> no_of_testcases;
  while (no_of_testcases-- > 0) {
    solve();
  }
  return 0;
}
