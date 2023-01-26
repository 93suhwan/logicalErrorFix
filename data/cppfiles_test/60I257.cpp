#include <bits/stdc++.h>
using namespace std;
template <typename T>
void showSTL(T H);
template <typename T, typename V>
void showSTL(pair<T, V> H);
template <typename T>
void showSTL(priority_queue<T> H);
template <typename T>
void showSTL(stack<T> H);
template <typename T, typename V>
void showSTL(map<T, V> H);
template <typename T, typename V>
void showSTL(multimap<T, V> H);
template <typename T>
void showSTL(vector<T> H);
template <typename T>
void showSTL(set<T> H);
template <typename T>
void showSTL(multiset<T> H);
template <typename T>
void showSTL(list<T> H);
void showSTL(char *H);
template <typename T>
void showSTL(deque<T> H);
template <typename T>
void showSTL(queue<T> H);
template <typename T>
void showSTL(T H) {
  stringstream ss;
  ss << H;
  cerr << ss.str();
}
template <typename T, typename V>
void showSTL(pair<T, V> H) {
  cerr << "(";
  showSTL(H.first);
  cerr << "=>";
  showSTL(H.second);
  cerr << ")";
}
template <typename T>
void showSTL(priority_queue<T> H) {
  cerr << '\n';
  while (!H.empty()) {
    cerr << H.top() << '\n';
    H.pop();
  }
  cerr << '\n';
}
template <typename T>
void showSTL(stack<T> H) {
  cerr << '\n';
  while (!H.empty()) {
    cerr << H.top() << '\n';
    H.pop();
  }
}
template <typename T, typename V>
void showSTL(map<T, V> H) {
  cerr << "[ ";
  for (auto val : H) {
    showSTL(val);
    cerr << " ";
  }
  cerr << "]";
}
template <typename T, typename V>
void showSTL(multimap<T, V> H) {
  cerr << "[ ";
  for (auto val : H) {
    showSTL(val);
    cerr << " ";
  }
  cerr << "]";
}
template <typename T>
void showSTL(vector<T> H) {
  cerr << "[ ";
  for (auto val : H) {
    showSTL(val);
    cerr << ' ';
  }
  cerr << "]";
}
template <typename T>
void showSTL(set<T> H) {
  cerr << "[ ";
  for (auto val : H) {
    showSTL(val);
    cerr << ' ';
  }
  cerr << "]";
}
template <typename T>
void showSTL(multiset<T> H) {
  cerr << "[ ";
  for (auto val : H) {
    showSTL(val);
    cerr << ' ';
  }
  cerr << "]";
}
template <typename T>
void showSTL(list<T> H) {
  cerr << "[ ";
  for (auto val : H) {
    showSTL(val);
    cerr << ' ';
  }
  cerr << "]";
}
void showSTL(char *H) {
  for (int i = 0; i < strlen(H); i++) {
    showSTL(H[i]);
  };
}
template <typename T>
void showSTL(deque<T> H) {
  cerr << "[ ";
  for (auto val : H) {
    showSTL(val);
    cerr << ' ';
  }
  cerr << "]";
}
template <typename T>
void showSTL(queue<T> H) {
  cerr << "[ ";
  while (!H.empty()) {
    showSTL(H.front());
    cerr << ' ';
    H.pop();
  }
  cerr << "]";
}
vector<string> vec_spltr(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty())
    res.push_back(s.substr(0, s.find(','))), s = s.substr(s.find(',') + 1);
  return res;
}
void dbg_out(vector<string> __attribute__((unused)) args,
             __attribute__((unused)) int idx,
             __attribute__((unused)) int LINE_NUM) {
  cerr << '\n';
}
template <typename Head, typename... Tail>
void dbg_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << "):";
  cerr << " " << args[idx] << " = ";
  showSTL(H);
  dbg_out(args, idx + 1, LINE_NUM, T...);
}
const long long mod = 1e9 + 7;
long long findpair(vector<long long> &arr, long long n, long long sum) {
  unordered_map<long long, long long> m;
  for (long long i = 0; i < n; i++) m[arr[i]]++;
  long long cnt = 0;
  for (long long i = 0; i < n; i++) {
    cnt += m[sum - arr[i]];
    if (sum - arr[i] == arr[i]) cnt--;
  }
  return cnt / 2;
}
void SakiBee() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  long long tot = 0;
  for (long long(i) = 0; (i) < (n); (i)++) cin >> v[i], tot += v[i];
  sort(v.begin(), v.end());
  long long d = tot / n;
  cout << findpair(v, n, d * 2) << '\n';
}
int main() {
  long long tc;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> tc;
  while (tc--) SakiBee();
  return 0;
}
