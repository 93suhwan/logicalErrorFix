#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int > > vvi;
typedef vector<long long> vll;
typedef vector<vector<long long> > vvl;

#define ll long long
#define ld long double

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second

#define sz(x) (int)(x).size()
#define szo(x) (int)sizeof(x)
#define sza(x) (szo(x) / szo(x[0]))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ms(a, b) memset(a, int(b), szo(a))

#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i =1;i<=n;i++)

#define endl "\n"

const ll int mod = 1e9 + 7;



int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cout.precision(10);
  cout << fixed;

  #ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);  
	#endif

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int  i = 0;
    string str[2];
    while(i < n){
      str[0] += 'B';str[1] += 'R';
      i++;
      if(i == n)break;
      str[0] += 'R';str[1] += 'B';
      i++;
    }


    //cout<<str<<endl;

    int imp[2] = {0};

    string temp[2] = s;
    for(int j = 0;j<2;j++)
    for(int i = 0;i<n;i++){
      if(temp[j][i] == '?')temp[j][i] = str[j][i];
    }

    for(int j = 0;j<2;j++ ){
      for(int i = 1;i<n;i++){
        if(temp[j][i] == temp[j][i-1])imp[j]++;
      }
    }
    

    if(imp[0] < imp[1])cout<<temp[0];
    else cout<<temp[1];

    cout<<endl;


  }
  

  return 0;
}