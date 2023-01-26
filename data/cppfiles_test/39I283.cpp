#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << '[';
  for (auto v : vec) os << v << ',';
  os << ']';
  return os;
}
template <class T>
T ABS(const T &x) {
  return x > 0 ? x : -x;
}
long long int gcd(long long int n1, long long int n2) {
  return n2 == 0 ? ABS(n1) : gcd(n2, n1 % n2);
}
long long int lcm(long long int n1, long long int n2) {
  return n1 == 0 && n2 == 0 ? 0 : ABS(n1 * n2) / gcd(n1, n2);
}
long long int ceil2(long long int a, long long int b) {
  return (a + b - 1) / b;
}
template <typename T>
bool chmax(T &m, const T q) {
  if (m < q) {
    m = q;
    return true;
  } else
    return false;
}
template <typename T>
bool chmin(T &m, const T q) {
  if (m > q) {
    m = q;
    return true;
  } else
    return false;
}
template <typename T>
vector<T> sorttrunq(vector<T> vec) {
  sort(vec.begin(), vec.end()),
      vec.erase(unique(vec.begin(), vec.end()), vec.end());
  return vec;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> ans(n, -1);
  vector<int> bigger(n, -1);
  vector<int> smaller(n, -1);
  int mnIdx, mxIdx;
  for (int i = 0; i < n; ++i) {
    int idx;
    cout << "? ";
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        cout << 2 << " ";
      } else {
        cout << 1 << " ";
      }
    }
    cout << endl;
    cin >> idx;
    if (idx == 0) {
      ans[i] = 1;
      mnIdx = i;
    } else if (--idx != i) {
      smaller[i] = idx;
    }
  }
  for (int i = 0; i < n; ++i) {
    int idx;
    cout << "? ";
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        cout << 1 << " ";
      } else {
        cout << 2 << " ";
      }
    }
    cout << endl;
    cin >> idx;
    if (idx == 0) {
      ans[i] = n;
      mxIdx = i;
    } else if (--idx != i) {
      bigger[i] = idx;
    }
  }
  queue<pair<int, pair<int, int>>> q;
  auto push = [&smaller, &bigger, &q, &n, &ans](int f, int idx) {
    for (int i = 0; i < n; ++i) {
      if (smaller[i] == idx && ans[i] == -1) {
        q.push({i, {f, 1}});
      }
      if (bigger[i] == idx && ans[i] == -1) {
        q.push({i, {f, -1}});
      }
    }
  };
  push(1, mnIdx);
  push(n, mxIdx);
  if (smaller[mxIdx] != -1) {
    ans[smaller[mxIdx]] = n - 1;
    push(n - 1, smaller[mxIdx]);
  }
  if (bigger[mnIdx] != -1) {
    ans[bigger[mnIdx]] = 2;
    push(2, bigger[mnIdx]);
  }
  while (!q.empty()) {
    auto curr = q.front();
    q.pop();
    int f = curr.second.first + curr.second.second, idx = curr.first;
    ans[idx] = f;
    if (smaller[idx] != -1) {
      ans[smaller[idx]] = f - 1;
      push(f - 1, smaller[idx]);
    }
    if (bigger[idx] != -1) {
      ans[bigger[idx]] = f + 1;
      push(f + 1, bigger[idx]);
    }
  }
  cout << "! ";
  for (auto &el : ans) {
    cout << el << " ";
  }
  return 0;
}
