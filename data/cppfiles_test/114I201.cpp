#include <bits/stdc++.h>
using namespace std;
const long long mxN = 2e5 + 5;
const long long INF = 1e18 + 7;
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(bool t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T>
void _print(T arr[], long long i, long long j) {
  cerr << "[ ";
  for (long long k = i; k <= j; k++) cerr << arr[k] << ", ";
  cerr << "]\n";
}
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
long long N, M, C, X;
vector<vector<long long>> A;
class compare {
 public:
  bool operator()(const vector<long long> &a, const vector<long long> &b) {
    long long strength1 = 0, strength2 = 0;
    for (long long i : a) strength1 += i;
    for (long long i : b) strength2 += i;
    return strength1 > strength2;
  }
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (long long i = 1; i <= N; i++) {
    cin >> C;
    vector<long long> temp;
    for (long long j = 1; j <= C; j++) {
      cin >> X;
      temp.push_back(X);
    }
    A.push_back(temp);
  }
  map<vector<long long>, bool> banned, visited;
  cin >> M;
  for (long long i = 1; i <= M; i++) {
    vector<long long> temp;
    for (long long i = 1; i <= N; i++) {
      cin >> X;
      temp.push_back(X - 1);
    }
    banned[temp] = true;
  }
  priority_queue<vector<long long>, vector<vector<long long>>, compare> pq;
  vector<long long> temp;
  for (long long i = 0; i < N; i++)
    temp.push_back((long long)(A[i].size() - 1));
  pq.push(temp);
  long long count = 0;
  while (!pq.empty() && count < M + 1) {
    vector<long long> check = pq.top();
    if (banned[check] == false) {
      for (long long ans : check) cout << ans + 1 << ' ';
      return 0;
    }
    count += 1;
    pq.pop();
    for (long long i = 0; i < N; i++) {
      if (check[i] > 0) {
        vector<long long> next = check;
        next[i] -= 1;
        if (visited[next] == false) {
          pq.push(next);
          visited[next] = true;
        }
      }
    }
  }
  return 0;
}
