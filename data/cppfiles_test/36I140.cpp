// //JAI SHREE RAM// //
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
map<int,set<int>> mp;

typedef pair<int, int> pi;

bool is_prime(int n) {
    // Assumes that n is a positive natural number
    // We know 1 is not a prime number
    if (n == 1) {
        return false;
    }

    int i = 2;
    // This will loop from 2 to int(sqrt(x))
    while (i*i <= n) {
        // Check if i divides x without leaving a remainder
        if (n % i == 0) {
            // This means that n has a factor in between 2 and sqrt(n)
            // So it is not a prime number
            return false;
        }
        i += 1;
    }
    // If we did not find any factor in the above loop,
    // then n is a prime number
    return true;
}



void solve(long long tz)
{
	int n;
	cin>>n;
	int a[n];
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(is_prime(sum)){
		int cnt=0;
		for(int i=0;i<n;i++){
			if(is_prime(a[i])){
				cnt=i;
				break;
			}
		}
		int cnt1=0;
		for(int i=n-1;i>=0;i++){
			if(is_prime(a[i]))
			{
				cnt1 = i;
				break;
			}
		}
		int f = n-cnt;
		int s = cnt1;
		if(f>s)
		{
			cout<<f<<endl;
			for(int i=cnt+1;i<=n;i++){
				cout<<i<<" ";
			}
			cout<<endl;
		}
		else{
			cout<<s<<endl;
			for(int i=1;i<=cnt1;i++){
				cout<<i<<" ";
			}
			cout<<endl;
		}
		return;

		if(cnt>cnt1)
		{
			cout<<cnt1<<endl;
			for(int i=1;i<=cnt;i++){
				cout<<i<<" ";
			}
			cout<<endl;
		}
		else{
			cout<<cnt1<<endl;
			for(int i=cnt1+1;i<=n;i++){
				cout<<i<<" ";
			}
			cout<<endl;
		}
	}
	else{
		cout<<n<<endl;
		for(int i=1;i<=n;i++){
			cout<<i<<" ";
		}
	}
}

int  main()
{
    
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	// #ifndef ONLINE_JUDGE
	// freopen("input4.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif
    long long t;
	t = 1;
    cin>>t;
	long long z = 0;
	while (t--)
	{
	 	z++;
		solve(z);
	}
}

