 /*
                                                                    __
                                                                   _ ,___,-'",-=-.
                                                       __,-- _ _,-'_)_  (""`'-._\ `.
                                                    _,'  __ |,' ,-' __)  ,-     /. |
                                                  ,'_,--'   |     -'  _)/         `\
                                                ,','      ,'       ,-'_,`           :
                                                ,'     ,-'       ,(,-(              :
                                                     ,'       ,-' ,    _            ;
                                                    /        ,-._/`---'            /
                                                   /        (____)(----. )       ,'
                                                  /         (      `.__,     /\ /,
                                                 :           ;-.___         /__\/|
                                                 |         ,'      `--.      -,\ |
                                                 :        /            \    .__/
                                                  \      (__            \    |_
                                                   \       ,`-, *       /   _|,\
                                                    \    ,'   `-.     ,'_,-'    \
                                                   (_\,-'    ,'\")--,'-'       __\
                                                    \       /  // ,'|      ,--'  `-.
                                                     `-.    `-/ \'  |   _,'         `.
                                                        `-._ /      `--'/             \
                                                           ,'           |              \
                                                          /             |               \
                                                       ,-'              |               /
                                                       /                 |             -'

  */
  #include <bits/stdc++.h>
#define ll long long
#define int long long
#define f(i,a,b) for(int i=a;i<b;i++)
#define co cout
#define ed endl
#define ff first
#define ss second
using namespace std;

ll  MM = 1e18 + 7;
int maxx(map<int, int> & x) {
	int maax = 0;
	for (int i = 0; i < x.size(); i++)
		if (x[i] > maax)
			maax = x[i];
	return maax;
}

int minn(map<int, int> & x) {
	int maax = 10000000000000;
	for (int i = 0; i < 2000005; i++)
		if (x[i] < maax)
			maax = x[i];
	return maax;
}
ll gcd(ll a, ll b) {
	if (a == 0 || b == 0)return abs(a - b);
	ll res = a % b;
	while (res) {
		a = b;
		b = res;
		res = a % b;
	}
	return b;
}
ll lcm(int a, int b)
{
	return (a / gcd(a, b)) * b;
}

int to_int(string s) {
	stringstream geek(s);
	int x = 0;
	geek >> x;
	return x;
}
void ff(string t) {
	string x;
	for (int i = t.size(); i >= 0; i--)
		x += t[i];
	t = x;
}
void copy_array(int* a, int* b, int n) {
	f(i, 0, n)
		b[i] = a[i];
}

int prime(int x) {
	bool f = true;
	for (int i = 2; i < x; i++)
		if (x % i == 0)
		{
			f = false; break;
		}
	return f;
}
int diff(string s, int n) {
	bool f = false;
	for (int i = 0; i < n - 1; i++)
		if (s[i] != s[i + 1])
			f = true;
	return f;
}

bool is_itdouble(double N)
{
	int X = N;
	double temp2 = N - X;
	if (temp2 > 0) {
		return true;
	}
	return false;
}
void sort_row(int a[][101], int x, int m) {
	for (int j = 0; j < m; j++)
		for (int i = j + 1; i < m; i++)
			if (a[x][i] < a[x][j])
				swap(a[x][i], a[x][j]);
}
void rsort_row(int a[][101], int x, int m) {
	for (int j = m - 1; j >= 0; j--)
		for (int i = j - 1; i >= 0; i--)
			if (a[x][i] < a[x][j])
				swap(a[x][i], a[x][j]);
}
ll fact(ll x) {
	ll sum = 1;
	for (int i = 1; i <= x; i++)
		sum *= i;
	return sum;
}
ll combintion(ll n, ll r) {
	return fact(n) / (fact(n - r) * fact(r)) * 1ll;
}

int binaryToDecimal(int n)
{
	int num = n;
	int dec_value = 0;
	int base = 1;
	int temp = num;
	while (temp) {
		int last_digit = temp % 10;
		temp = temp / 10;
		dec_value += last_digit * base;
		base = base * 2;
	}
	return dec_value;
}

int pprime(int x) {
	for (int i = x + 1;; i++)
		if (prime(i))
			return i;
}
pair<int, int> mxx(deque<int> a) {
	pair<int, int> x;
	x.first = a[0]; x.second = 0;
	for (int i = 0; i < a.size(); i++)
		if (x.first < a[i])
			x.first = a[i], x.second = i;
	return x;
}
ll pow(ll a, ll b, ll m) {
	if (b == 0)return 1;
	if (b == 1)return a;
	ll x = pow(a, b / 2, m);
	x = (x * x) % m;
	if (b % 2)x = (x * a);
	return x % m;
}
int cm(string s, string x) {
	int c = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == x[i])
			c++;
		else break;
	return c;
}
int palindrome(string a, int n) {
	for (int i = 0; i < n / 2; i++)
		if (a[i] != a[n - i - 1])
			return 0;
	return 1;
}
int n;
string s;
int is(int i){
if(i>s.size()-3||i<0)return 0;
if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')return 1;
return 0;
}

void swap1(int a[],int n){
for(int i=0;i<n;i++)
    swap(a[i],a[n+i]);
}
void swap2(int a[],int n){
for(int i=0;i<2*n-1;i+=2)
    swap(a[i],a[i+1]);
}
int check(int a[],int b[],int n){
    int f=1;
for(int i=0;i<2*n;i++)
if(a[i]!=b[i]){f=0;break;}
return f;
}


pair<int,int> b[200005],c[200005];
signed main()
{

	//freopen("window.in", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);

	typedef vector<int> vi;
	typedef multiset<int> msi;
	typedef vector<char> vc;
	typedef set<int> si;
	typedef set<char> sc;
	typedef multiset<char> msc;
	typedef map<int, int> mapi;
	int T = 1;
		cin >> T;
	while (T--){

int n;
cin>>n;
pair<int,int> a[n],b[n];
set<int> s,ss;
int c[n]={0};
for(int i=0;i<n;i++)
    cin>>a[i].ss>>a[i].ff,b[i].ff=a[i].ff-a[i].ss,b[i].ss=i;
    sort(b,b+n);

    for(int i=1;i<=n;i++)
        s.emplace(i);
    for(int i=0;i<n;i++)
        if(a[i].ff==a[i].ss)
          c[i]=a[i].ff,s.erase(a[i].ff),ss.emplace(i);

         // for(auto g:s)cout<<g<<" -";cout<<endl;
    for(int i=0;i<n;i++){if(ss.count(b[i].ss)>0)continue;
    for(int j=1;j<=n;j++){
            cout<<a[b[i].ss].ff<<"*"<<j<<endl;
        if(a[b[i].ss].ff>=j+1&&s.count(j)!=0&&j>=a[b[i].ss].ss)
{c[b[i].ss]=j,s.erase(j);break;}
    else if(a[b[i].ss].ss<=j-1&&s.count(j)!=0&&j<=a[b[i].ss].ff){
        c[b[i].ss]=j,s.erase(j);break;}}
        //for(auto g:s)cout<<g<<" -";cout<<endl;
        }
    for(int i=0;i<n;i++)
        cout<<a[i].ss<<" "<<a[i].ff<<" "<<c[i]<<endl;
        cout<<endl;
	}
	return 0;
}
