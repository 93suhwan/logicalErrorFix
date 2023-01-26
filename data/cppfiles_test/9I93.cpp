/*
Problem link:

1. Understand
  Input:
  Output:
  Conditions:
    Separate various parts of the condition:

2. Plan
  Connection between data and unknown:
    Subproblem / Simpler problem:
  Related problem:
  Restate the problem:
  Restate again:
  Drop part of the condition:
  Use all data?
  Use the whole condition?

Problems tags:
  Case Analysis
  Classic
    DP
  Math
  Combinatorics
  Data Structure
  Graph
  Tree
  Flows
  Greedy (or not?)
  Implementation
    Date time
    Ordered set
    Fast io
  String
  Visualization
  Simple



Notes:



*/

#include<bits/stdc++.h>
using namespace std;

// //#define DB
// #ifdef DB
// #define el cerr << "\n";
// #define db(...) cerr << " [" << #__VA_ARGS__ << " : " << __VA_ARGS__ << "] ";
// #else
// #define el
// #define db(...)
// #endif // DB

// DEBUG
#define format(x) << #x << ": " << (x)
#define com << ", "
#define ndl << "\n"
#define debug1(x) cerr format(x) ndl;
#define debug2(x, y) cerr format(x) com format(y) ndl;
#define debug3(x, y, z) cerr format(x) com format(y) com format(z) ndl;
#define debug4(x, y, z, w) cerr format(x) com format(y) com format(z) com format(w) ndl;
void debug_out() { cerr << "\n"; }
template <typename H, typename... T> 
void debug_out(H h, T... t) { cerr << " " << (h); debug_out(t...); }
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define el cerr << "\n";
//

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;
// define double long double will mess up the debug code
// #define double long double
template <typename T, typename U>
pair<T, U> operator + (const pair<T, U> &L, const pair<T, U> &R) {
  return {L.first + R.first, L.second + R.second};
}
template <typename T, typename U>
pair<T, U> operator - (const pair<T, U> &L, const pair<T, U> &R) {
  return {L.first - R.first, L.second - R.second};
}


#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<
	int, // key // if multiset, use pair<T, int> as the key where the int is time when added
	null_type, // value
	less<int>, // comparator (less --> normal set)
	rb_tree_tag,
	tree_order_statistics_node_update
> ordered_set;
/*
  How to use ordered_set:
ordered_set os;
os.insert(x);
os.erase(x);
os.find_by_order(k)  returns iterator to kth element starting from 0;
os.order_of_key(x) returns count of elements strictly smaller than x; (Lower bound, 0 based position)
  
  erase, insert same as normal set
*/

//const int MOD = 998244353;
const int MOD = 1e9 + 7;

// Assume: MOD is coprime with a
ll invMod(ll a) {
    ll b = MOD, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    return (MOD + u) % MOD;
}

ll mul(ll a, ll b) {
    // return ((a % MOD) * (b % MOD)) % MOD;  // Safer but slower
    return (a * b) % MOD;
}

ll add(ll a, ll b) {
    // return ((a % MOD) + (b % MOD)) % MOD;  // Safer but slower
    return (a + b) % MOD;
}

ll sub(ll a, ll b) {
    // return ((a - b) % MOD + MOD) % MOD;  // Safer but slower
    return (a - b + MOD) % MOD;
}

ll divMod(ll a, ll b) {
    return mul(a, invMod(b));
}

ll powMod(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b % 2) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b /= 2;
    }
    return res;
}


/**
 * Frequent bugs:
 *   - Overflows: Are limits on static arrays enough?? Double-check!!
 *      Input is N but we need N * 2? N * 4 (segment tree)?
 *      Is N upto 10^7?
 *   - 1-off errors:
 *      Is indexing 0-based or 1-based?
 *   - Corner cases:
 *      N == 0?
 *      N == 1?
 *      Impossible?
 *   - Output format:
 *      Special characters? Long 'minus' signs? Copy-and-paste from statement to be sure
 *      New-lines?
 *   - Casting problems:
 *      Function calculates long long but return int --> WA?
 *      Provide long long as argument but the parameter is int --> WA?
 *      Use #define int long long if memory limit is high
 *   - Problem definition: read the statement correctly:
 *      'y' is vowel?
 **/
const int N = 1e3 + 5;
int a[N][N];
set<int> cols[N];
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        cin >> a[i][j];
        if (a[i][j] != 2) {
          cols[j].insert(i);
        }
      }
    }
    int y, x;
    for (int i = 0; i < k; ++i) {
      cin >> y; x = 0;
      while (1) {
        auto it = cols[y].lower_bound(x);
        if (it == cols[y].end()) {
          cout << y << " ";
          break;
        }
        x = *it;
        cols[y].erase(it);
        if (a[x][y] == 1) {
          ++y;
        } else {
          --y;
        }
        a[x][y] = 2;
      }
    }
    //cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}

/*
1. UNDERSTAND THE PROBLEM

 • *First.* You have to _understand_ the problem.

 • What is the unknown? The unknown is ...
 What are the data? The data are ...
 What is the condition? The condition is ...

 • Is it possible to satisfy the condition?
 Is the condition sufficient to determine the unknown? Or is it insufficient? Or redundant? Or contradictory?

 • Draw a figure. Introduce suitable notation.

 Let x be ...

 • Separate the various parts of the condition. Can you write them down?

 The condition can be separated into ... parts: ...



2. DEVISING A PLAN
 • *Second.* Find the connection between the data and the unknown.
 You may be obliged to consider auxiliary problems if an immediate connection cannot be found.
 You should obtain eventually a _plan_ of the solution.

 • Have you seen it before? Or have you seen the same problem in a slightly different form?

 • _Do you know a related problem?_ Do you know a theorem that could be useful?

 • _Look at the unknown!_ Try to think of a familiar problem having the same or a similar unknown.

 • _Here is a problem related to yours and solved before. Could you use it?_
 Could you use its result? Could you use its method?
 Should you _introduce some auxiliary element_ in order to make its use possible?

 • Could you restate the problem? Could you restate it still differently? Go back to definitions.

 The problem can be restated as follows: Given ...

 • If you cannot solve the proposed problem, try to solve first some related problem.
 Could you imagine a more accessible related problem?
 A more general problem? A more special problem? An analogous problem?
 Could you solve a part of the problem?
 Keep only a part of the condition, drop the other part; how far is the unknown then determined, how can it vary?

 Let's see what happens when condition ... is removed: ...

 Could you derive something useful from the data? Could you think of other data appropriate to determine the unknown?
 Could you change the unknown or data, or both if necessary, so that the new unknown and the new data are nearer to each other?

 • Did you use all the data? Did you use the whole condition?
 Have you taken into account all essential notions involved in the problem?




3 3. CARRYING OUT THE PLAN
 • *Third.* Carry out your plan.
 • Carrying out your plan of the solution, check each step.
 Can you see clearly that the step is correct? Can you prove that it is correct?

4. LOOKING BACK
 • *Fourth.* Examine the solution obtained.
 • Can you check the result? Can you check the argument?
 • Can you derive the solution differently? Can you see it at a glance?
 • Can you use the result, or the method, for some other problem?

 */
