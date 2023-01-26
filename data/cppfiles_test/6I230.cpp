#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define range(a, b) substr(a, b - a + 1)
#define ps(x, y) fixed << setprecision(y) << x
#define rep(i, a, n) for (int i = a; i < (int)(n); i++)
#define repeq(i, a, n) for (int i = a; i <= (int)(n); i++)
#define rev(i, a, b) for (int i = a; i > b; i--)
#define reveq(i, a, b) for (int i = a; i >= (int)(b); i--)
#define trav(a, b) for (auto a : b)
#define boost                  \
	ios::sync_with_stdio(false); \
	cin.tie(0);                  \
	cout.tie(0);

#define MOD 1000000007
#define MOD2 998244353
#define INF INT_FAST64_MAX;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef set<int> si;

/* Debug Begins */ 
# define trace(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
  stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
string to_string(char c) { return "'" + string(1, c) + "'";}
string to_string(string s) { return '"' + s + '"';}
string to_string(bool f) { if(f) return "True"; else return "False";}
string to_string(const char* s) { return to_string((string) s);}
template<typename A> string to_string(A);
template<typename A, typename B> string to_string(pair<A, B> p){
  return "(" + to_string(p.first) + ": " + to_string(p.second) + ")";}
template<typename A> string to_string(A v) {bool f = false; string r = "{"; 
  for (auto x: v) {if (f) r += ", "; r += to_string(x); f = true;} return r += "}";}
template<typename A> string to_string(vector<vector<A>> v) {string r; 
  for (auto x: v) r += "\n" + to_string(x); return r;}
int Nerr;
template<typename A> string to_string(A *p) {return to_string(vector<A>(p, p + Nerr));}
void err(istream_iterator<string>) { cerr << endl; }
template<typename T,typename... Args> void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << to_string(a) << "; "; err(++it, args...); }
template<typename T> void kek(T ans) {cout << ans << endl; exit(0);}
#define Lu(...) [&] (auto &&u) { return __VA_ARGS__; }
#define Luv(...) [&] (auto &&u, auto &&v) { return __VA_ARGS__; }
/***************************************************************/


vector<bool> seive(10000001, true);

void initSeive()
{
	seive[0] = false;
	seive[1] = false;
	for (int i = 2; i * i <= 10000001; i++)
	{
		if (seive[i] == true)
		{
			for (int j = i * i; j <= 10000001; j += i)
			{
				seive[j] = false;
			}
		}
	}
}

vi primes;

void initPrime()
{
	primes.pb(2);
	primes.pb(3);
	for (int i = 6; i < 10000001; i += 6)
	{
		if (seive[i - 1])
			primes.pb(i - 1);
		if (seive[i + 1])
			primes.pb(i + 1);
	}
}

ll fact(ll n)
{
	if (n == 0)
		return 1;
	ll i = n, fact = 1;
	while (n / i != n)
	{
		fact = fact * i;
		i--;
	}
	return fact;
}

void ExecutionTime(auto t1, auto t2)
{
	//auto t1 = chrono::high_resolution_clock::now();   pass these as parameters
	//auto t2 = chrono::high_resolution_clock::now();

	chrono::duration<double, milli> new_time = t2 - t1;
	cout << "\nExecution Time = " << new_time.count() << endl;
}

void sort(unordered_map<int, int> &M)
{
	vector<pair<int, int>> A;

	for (auto &it : M)
	{
		A.push_back(it);
	}
	M.clear();
	sort(A.begin(), A.end());
	for (auto &it : A)
		M[it.first] = it.second;
}

string to_bin(int num, int len=0)
{
	if (len == 0)
	{
		string ans;
		while (num > 0)
		{
			ans.push_back(char(num % 2 + 48));
			num /= 2;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
	else
	{
		string ans(len, '0');
		int i = ans.length() - 1;
		while (num > 0)
		{
			ans[i] = char(num % 2 + 48);
			num /= 2;
			i--;
		}
		return ans;
	}
}

ll modmul(ll a, ll b, ll mod)
{
    ll res = 0; // Initialize result
		if(b>a) 
			return modmul(b,a,mod);
    // Update a if it is more than
    // or equal to mod
    a %= mod;
 
    while (b)
    {
        // If b is odd, add a with result
        if (b & 1)
            res = (res + a) % mod;
 
        // Here we assume that doing 2*a
        // doesn't cause overflow
        a = (2 * a) % mod;
 
        b >>= 1; // b = b / 2
    }
 
    return res;
}
 

int random(int min, int max)
{
	//srand(time(nullptr)); // use current time as seed for random generator
	int random_variable = rand();
	return min + (random_variable % (max - min + 1));
}

template <typename T>
void print(vector<T> arr)
{
	trav(ele, arr)
					cout
			<< ele << " ";
	cout << endl;
}

template <typename T>
void print(vector<vector<T>> &arr)
{
	trav(row, arr)
	{
		trav(ele, row)
						cout
				<< ele << " ";
		cout << endl;
	}
}

string nextGreater(string num)
{
	int l = num.size();
	int i = l - 1;
	// examine bits from the right
	for (; i >= 0; i--)
	{
		// if '0' is encountered, convert
		// it to '1' and then break
		if (num.at(i) == '0')
		{
			num.at(i) = '1';
			break;
		}

		// else convert '1' to '0'
		else
			num.at(i) = '0';
	}

	// if the binary representation
	// contains only the set bits
	if (i < 0)
		num = "1" + num;

	// final binary representation
	// of the required integer
	return num;
}

int countDigit(long long n)
{
	return floor(log10(n) + 1);
}

bool compare2(piii a, piii b)
{
	if (a.ff == b.ff)
	{
		if (a.ss.first == 1)
			return true;
		return false;
	}
	if (a.ff < b.ff)
		return true;
	return false;
}

bool compare(pii a, pii b)
{
	
	if (a.ff == b.ff)
	{
		if (a.ss < b.ss)
			return true;
		return false;
	}
	if (a.ff > b.ff)
		return true;
	return false;
}

vector<si> adj(100001);
si removed;
vi minimas(100001,0);

map<int,si> maps;

void calculate() {
  removed.clear();
  minimas.clear();
  minimas.resize(adj.size(),0);
  //trace(adj);
  rep(i,1,adj.size()) {
    bool flag = false;
    int Min = i;
    trav(ele, adj[i]) {
      //trace(ele,i,Min);
      bool temp = removed.find(ele) == removed.end();
      if(temp)
        flag = true;
      if(ele < Min && temp) {
        //cout<<"curr" << ele << endl;
        Min = ele;
      }
    }

    //cout<<"to be removed : "<<Min<<endl; 
    if(removed.find(i) == removed.end() && flag) {
      minimas[i] = Min;
      maps[Min].insert(i);
      removed.insert(Min);
    }
    
  }
  //trace(removed);
}

void solve()
{
	int n,m;
	cin>>n>>m;
  adj.resize(n+1);
  minimas.resize(n+1,0);

  rep(i,0,m) {
    int a, b;
    cin>>a>>b;
    adj[a].insert(b);
    adj[b].insert(a);
  }
  
	//code goes here
  int q;
  cin>>q;
  calculate();
  while(q--) {
    //trace(removed,minimas,maps);
    int ch = 0, u, v;
    cin>>ch;
    if(ch == 3) {
      cout<<adj.size() - removed.size() - 1<<endl;
    }
    else {
      cin>>u>>v;
      if(ch == 1) {
        adj[u].insert(v);
        adj[v].insert(u);
        int tar = u;
        int other = v;
        if(v > u) {
          tar = v;
          other = u;
        }
        if(minimas[tar] > other) {
          calculate();
        }
      }
      else {
        adj[u].erase(v);
        int tar = u;
        int other = v;
        if(v > u) {
          tar = v;
          other = u;
        }
        if(minimas[tar] == other) {
          bool flag = false;
          int Min = tar;
          trav(ele, adj[tar]) {
            //trace(ele,tar,Min);
            bool temp = removed.find(ele) == removed.end();
            if(temp)
              flag = true;
            if(ele < Min && temp) {
              //cout<<"curr" << ele << endl;
              Min = ele;
            }
          }
          if(removed.find(tar) == removed.end() && flag) {
            minimas[tar] = Min;
            removed.insert(Min);
          }
        }
      }
    }
  }
	
}

void debugger()
{
	int n, e, h, a, b, c;
	int cnt = 10;
	while (1)
	{
		n = random(1, 10);
		e = random(0, 10);
		h = random(0, 10);
		a = random(1, 10);
		b = random(1, 10);
		c = random(1, 10);
		int x = min(e, h);
		int checkSm = x;
		if (e > x)
			checkSm += (e - x) / 2;
		if (h > x)
			checkSm += (h - x) / 3;
		if (checkSm < n)
			continue;
		else
		{
			// int ans1 = solve(n,e,h,a,b,c);
			// int ans2 = solve2(n,e,h,a,b,c,0);
			// if(ans1 != ans2) {
			//   cout<<n<<" "<<e<<" "<<h<<" "<<a<<" "<<b<<" "<<c<<endl;
			//   cout<<ans2<<" "<<ans1<<endl;
			//   break;
			// }
		}
	}
}

signed main()
{
	//auto t1 = chrono::high_resolution_clock::now();
	boost ll t = 1;
	//cin >> t;
	//initSeive();
	//initPrime();
	int cases = 1;
	while (t--)
	{
		//cout << "Case #"<<cases<<": ";
		solve();
		cases++;
		//debugger();
	}

	// auto t2 = chrono::high_resolution_clock::now();
	// ExecutionTime(t1, t2);

	return 0;
}