#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T>
void Output(const T &v, bool print_new_line = true) {
  bool first = true;
  for (auto element : v) {
    if (!first)
      cout << " ";
    else
      first = false;
    cout << element;
  }
  if (print_new_line) cout << endl;
}

template <class T>
void Input(vector<T> &v, int n) {
  v.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
}

template <class T>
std::vector<T> Input(int n) {
  vector<T> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  return v;
}

template <class T>
vector<int> Query(const T &c, int answer_counts) {
  cout << "? " << c.size();
  for (auto it = c.begin(); it != c.end(); ++it) {
    cout << " " << (*it);
  }
  cout << endl;
  cout.flush();
  vector<int> s(answer_counts);
  for (int i = 0; i < answer_counts; ++i) {
    cin >> s[i];
  }
  return s;
}

#define MULTIPLE_CASES 0

void main_();
int main() {
#if defined(LOCAL_DEBUG__)
  cout << "<Start>" << endl;
#endif
  ios_base::sync_with_stdio(false);
#if MULTIPLE_CASES
  int case_number;
  cin >> case_number;
  for (int case_index = 0; case_index < case_number; ++case_index) {
#endif
    main_();
#if MULTIPLE_CASES
  }
#endif
#if defined(LOCAL_DEBUG__)
  system("pause");
#endif
  return 0;
}

/**********************************  problem code  **********************************/

void main_() {
  int n, m;
  cin >> n >> m;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  vector<int> sum(m, 0);
  int M = sqrt(m);
  vector<vector<int>> s(M);
  vector<int> added(n);
  vector<int> answer;
  int current = 0;
  for (int i = 2; i < M; ++i) {
    s[i].resize(i);
  }
  for (int i = 0; i < m; ++i) {
    int p, a;
    cin >> p >> a;
    --a;
    int r = x[a] + y[a];
    if (p == 1) {
      if (r >= M) {
        for (int j = i; j < m; j += r) {
          if (j != i) sum[j] -= 1;
          if (j + x[a] < m) {
            sum[j + x[a]] += 1;
          }
        }
      } else {
        for (int j = x[a]; j < r; ++j) {
          s[r][(i + j) % r] += 1;
        }
      }
      added[a] = i;
    } else {
      int ia = added[a];
      if (r >= M) {
        for (int j = ia; j < m; j += r) {
          if (j != ia) {
            if (j < i) current += 1;
            else sum[j] += 1;
          }
          if (j + x[a] < m) {
            if (j < i) current -= 1;
            else sum[j] -= 1;
          }
        }
      } else {
        for (int j = x[a]; j < r; ++j) {
          s[r][(ia + j) % r] -= 1;
        }
      }
    }
    current += sum[i];
    int ans = current;
    for (int j = 2; j < M; ++j) {
      ans += s[j][i % j];
    }
    answer.push_back(ans);
  }
  for (auto x : answer) cout << x << endl;
}
