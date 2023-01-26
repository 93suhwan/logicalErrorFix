#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
void dout(string name, T arg)
{
	cerr << "\e[91m" << name << " = " << arg << "\e[39m" << endl;
}

template <typename T1, typename... T2>
void dout(string names, T1 arg, T2... args)
{
	cerr << "\e[91m" << names.substr(0, names.find(',')) << " = " << arg << "   |   \e[39m";
	dout(names.substr(names.find(',') + 2), args...);
}

#ifdef LOCAL
#define debug(...) dout(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr> &operator<<(basic_ostream<Ch, Tr> &os, Container const &x)
{
	os << "{ ";
	for (auto &y : x)
		os << y << " ; ";
	return os << "}";
}

template <class X, class Y>
ostream &operator<<(ostream &os, pair<X, Y> const &p)
{
	return os << "[ " << p.first << ", " << p.second << "]";
}

typedef pair<long long int, long long int> ii;
typedef vector<long long int> vi;
typedef vector<vector<long long int>> vvi;
typedef vector<pair<long long int, long long int>> vii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) (c).begin(), (c).end()
#define sz(a) ((long long int)(a).size())
#define lli long long int
#define ull unsigned long long int
#define ld long double
#define ref(i, x, y) for (long long int i = (x); i <= (y); ++i)
#define reb(i, x, y) for (long long int i = (x); i >= (y); --i)
#define trf(c, it) for (auto it = (c).begin(); it != (c).end(); ++it)
#define trb(c, it) for (auto it = (c).end() - 1; it != (c).begin() - 1; --it)
#define tc(t) int t; cin >> t; while (t--)
#define endl '\n'

const long long int mod = 1e9 + 7;
const long long int pinf = 9223372036854775807;
const long long int ninf = -9223372036854775807;

lli n, arr[200005];
lli sm, gg, cnt, a1, a2;

lli first(lli low, lli high, lli key)
{
    lli ans = -1;
 
    while (low <= high) {
        lli mid = low + (high - low + 1) / 2;
        lli midVal = arr[mid];
 
        if (midVal < key) {
            low = mid + 1;
        }

        else if (midVal > key) {
            high = mid - 1;
        }

        else if (midVal == key) {
            ans = mid;
            high = mid - 1;
        }
    }
 
    return ans;
}

lli last(lli low, lli high, lli key)
{
    lli ans = -1;
 
    while (low <= high) {
        lli mid = low + (high - low + 1) / 2;
        lli midVal = arr[mid];
 
        if (midVal < key) {
            low = mid + 1;
        }

        else if (midVal > key) {
            high = mid - 1;
        }

        else if (midVal == key) {
            ans = mid;
            low = mid + 1;
        }
    }
 
    return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// auto start = std::chrono::high_resolution_clock::now();
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	tc(t)
	{
		sm=0;
		cnt=0;

		cin>>n;
		ref(i,0,n-1)
		{
			cin>>arr[i];
			sm+=arr[i];
		}

		sort(arr, arr+n);

		if (((n-2)*sm)%n!=0)
		{
			debug("Not possible");
			cout<<0<<endl;
			continue;
		}

		else
		{
			gg = ((n-2)*sm)/n;
			gg = sm-gg;
			debug(gg);
			cnt=0;

			if (gg%2==0)
			{
				a1=first(0, n-1, gg/2);
				a2=last(0, n-1, gg/2);

				if (a2-a1>0)
					cnt+=((a2-a1+1)*(a2-a1))/2;
			}

			ref(i,0,n-1)
			{
				if (arr[i]<gg-arr[i])
				{
					a1=first(0, n-1, gg-arr[i]);
					a2=last(0, n-1, gg-arr[i]);

					debug(arr[i], gg-arr[i], a1, a2);

					if (a1!=-1 && a2!=-1)
						cnt+=a2-a1+1;
				}
			}

			cout<<cnt<<endl;
		}
	}

	// auto stop = std::chrono::high_resolution_clock::now();
	// auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	// #ifdef LOCAL
	// cerr << "\e[91mTime taken : " << ((long double)duration.count())/((long double) 1e9) <<"s\e[39m"<< endl;
	// #endif

	return 0;
}