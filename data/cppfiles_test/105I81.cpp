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

#define MULTIPLE_CASES 1

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
  int n;
  cin >> n;
  auto c = Input<int>(n);
 // auto colors = c;
 // sort(colors.begin(), colors.end());
 // colors.erase(std::unique_copy(colors.begin(), colors.end(), colors.begin()), colors.end());
  vector<int> next(n, -1);
  vector<int> c2p(n + 1, -1);
  for (int i = n - 1; i >= 0; --i) {
    next[i] = c2p[c[i]];
    c2p[c[i]] = i;
  }
  
  vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));
  for (int l = 1; l <= n; ++l) {
    for (int i = 0; i + l <= n; ++i) {
      int j = i + l;
      if (l == 1) {
        m[i][j] = 0;
        continue;
      }
      int k = next[i];
      if (k >= j || k == -1) {
        m[i][j] = std::min(m[i + 1][j] + 1, m[i][j - 1] + 1);
        continue;
      }
      // if (i + 1 == k) {
      //   m[i][j] = m[i + 1][j];
      //   continue;
      // }
      int sum = 0;
      m[i][j] = std::min(m[i + 1][j] + 1, m[i][j - 1] + 1);
      int last_k = i;
      while (k < j && k != -1) {
        int t = 0;
        int sum_t = 0;
        if (k - i > 1) {
          t += m[i + 1][k] + 1;
        }
        if (k - last_k > 1) {
          sum += m[last_k + 1][k] + 1; 
        }
        if (k < j - 1) {
          t += 1 + m[k + 1][j];
          sum_t = 1 + m[k + 1][j];
        }
        m[i][j] = std::min(m[i][j], t);
        m[i][j] = std::min(m[i][j], sum + sum_t);
        last_k = k;
        k = next[k];
      }
    }
  }
  cout << m[0][n] << endl;
}
