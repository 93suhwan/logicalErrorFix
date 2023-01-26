#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define vec vector
#define pii pair<int, int> 
#include <chrono>
using namespace std;

const long long MAXVAL = (long long) 1e18 + 1;
const long long MOD = 1000000007ll;
const long long MOD2 = 998244353ll;
const int INF = 1000000001;

long long poww(int x, long long pow, ll mod = MOD) {
  if (pow == 0ll ) return 1;
  if (pow == 1ll) return x % mod;
  long long ans = poww(x, pow >> 1) % mod;
  ans = (ans * ans) % mod;
  if ((pow & 1) == 1) {
    ans = (ans * x ) % mod;
  }
  return ans % mod;
}

ll gcd(ll x, ll y) {
  if (x == 0) return y;
  while (y) {
    x %= y;
    swap(x, y);
  }
  return x;
}

ll sq(int x, int y){ 
  return x * 1ll * x + y  * 1ll * y;
}

template <
    class result_t   = std::chrono::milliseconds,
    class clock_t    = std::chrono::steady_clock,
    class duration_t = std::chrono::milliseconds
>
auto since(std::chrono::time_point<clock_t, duration_t> const& start)
{
    return std::chrono::duration_cast<result_t>(clock_t::now() - start);
}

vec<int> pi;
vec<int> w;

void pseudodsu_init(int n) {
  w = vec<int>(n + 1, 1);
  for (int i = 0; i <= n; ++i) {
    pi.push_back(i);
  }
}

int pseudodsu_get(int x) {
  if (pi[x] == x) return x;
  int res = pseudodsu_get(pi[x]);
  pi[x] = res;
  return res;
}

// attach x to y
void pseudodsu_union(int x, int y) {
  if (x == y) {
    pi[x] = x;
    return;
  }
  y = pseudodsu_get(y);
  pi[x] = y;
  pi[y] = y;
}

//struct intr {
  //int x, a, lb, rb;
  //intr(int x_, int a_, int lb_, int rb_) {
    //x = x_;
    //a = a_;
    //lb = lb_;
    //rb = rb_;
  //}
//};
//
//vec<int> t;

//void init (int nn) {
  //n = nn;
  //t.assign (n, 0);
//}

//int sum (int r) {
  //int result = 0;
  //for (; r >= 0; r = (r & (r+1)) - 1) result += t[r];
  //return result;
//}

//void inc (int i, int delta) {
  //for (; i < n; i = (i | (i+1))) t[i] += delta;
//}

struct suffix {
	int index; // To store original index
	int rank[2]; // To store ranks and next rank pair
};

// A comparison function used by sort() to compare two suffixes
// Compares two pairs, returns 1 if first pair is smaller
int cmp(struct suffix a, struct suffix b) {
	return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0):
			(a.rank[0] < b.rank[0] ?1: 0);
}

// This is the main function that takes a string 'txt' of size n as an
// argument, builds and return the suffix array for the given string
vec<int> build_suff_arr(string txt, int n) {
	// A structure to store suffixes and their indexes
	struct suffix suffixes[n];

	// Store suffixes and their indexes in an array of structures.
	// The structure is needed to sort the suffixes alphabatically
	// and maintain their old indexes while sorting
	for (int i = 0; i < n; i++) {
		suffixes[i].index = i;
		suffixes[i].rank[0] = txt[i] - 'a';
		suffixes[i].rank[1] = ((i+1) < n)? (txt[i + 1] - 'a'): -1;
	}

	// Sort the suffixes using the comparison function
	// defined above.
	sort(suffixes, suffixes+n, cmp);

	// At this point, all suffixes are sorted according to first
	// 2 characters. Let us sort suffixes according to first 4
	// characters, then first 8 and so on
	int ind[n]; // This array is needed to get the index in suffixes[]
				// from original index. This mapping is needed to get
				// next suffix.
	for (int k = 4; k < 2*n; k = k*2) {
		// Assigning rank and index values to first suffix
		int rank = 0;
		int prev_rank = suffixes[0].rank[0];
		suffixes[0].rank[0] = rank;
		ind[suffixes[0].index] = 0;

		// Assigning rank to suffixes
		for (int i = 1; i < n; i++) {
			// If first rank and next ranks are same as that of previous
			// suffix in array, assign the same new rank to this suffix
			if (suffixes[i].rank[0] == prev_rank &&
					suffixes[i].rank[1] == suffixes[i-1].rank[1]) {
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = rank;
			}
			else {
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = ++rank;
			}
			ind[suffixes[i].index] = i;
		}

		// Assign next rank to every suffix
		for (int i = 0; i < n; i++) {
			int nextindex = suffixes[i].index + k/2;
			suffixes[i].rank[1] = (nextindex < n)?
								suffixes[ind[nextindex]].rank[0]: -1;
		}

		// Sort the suffixes according to first k characters
		sort(suffixes, suffixes+n, cmp);
	}

	vec<int>  suff_arr(n);
	for (int i = 0; i < n; i++)
		suff_arr[i] = suffixes[i].index;

	// Return the suffix array
	return suff_arr;
}

void print(vec<int>  arr, int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}


struct interval {
  int l, r, w;
};

uint32_t next_pow2(int x) { 
  return x == 1 ? 1 : 1<<(32 - __builtin_clzl(x-1));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  chrono::steady_clock::time_point START = chrono::steady_clock::now();

  int q = 1;
  cin >> q;

  vec<tuple<int, int, int>> reqs;
  pseudodsu_init(500001);
  while (q-- > 0) { 
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      reqs.emplace_back(1, x, 0);
    } else {
      int x, y;
      cin >> x >> y;
      reqs.emplace_back(2, x, y);
    }
  }
  vec<int> res;
  for (const auto& req: reqs | views::reverse) {
    int t = get<0>(req);
    if (t == 1) {
      int x = get<1>(req);
      res.push_back(pseudodsu_get(x));
    } else {
      int x, y;
      x = get<1>(req);
      y = get<2>(req);
      pseudodsu_union(x, y);
    }
  }
  for (int x : res | views::reverse) {
    cout << x << " ";
  }
  return 0;
}
