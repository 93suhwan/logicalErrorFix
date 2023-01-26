#include <bits/stdc++.h>
using namespace std;

bool prime[10000007];
vector<int> primes;
void Sieve()
{
    int n = 100000;
 
    // In general Sieve of Sundaram, produces primes
    // smaller than (2*x + 2) for a number given
    // number x
    int nNew = sqrt(n);
 
    // This array is used to separate numbers of the
    // form i+j+2ij from others where  1 <= i <= j
    int marked[n/2+500] = {0};
 
    // eliminate indexes which does not produce primes
    for (int i=1; i<=(nNew-1)/2; i++)
        for (int j=(i*(i+1))<<1; j<=n/2; j=j+2*i+1)
            marked[j] = 1;
 
    // Since 2 is a prime number
    primes.push_back(2);
 
    // Remaining primes are of the form 2*i + 1 such
    // that marked[i] is false.
    for (int i=1; i<=n/2; i++)
        if (marked[i] == 0)
            primes.push_back(2*i + 1);
}
void SieveOfEratosthenes()
{
  //bool prime[n + 1];
  memset(prime, true, sizeof(prime));

  for (int p = 2; p * p <= 10000007; p++)
  {
    if (prime[p] == true)
    {

      for (int i = p * p; i <= 10000007; i += p)
        prime[i] = false;
    }
  }
  // Print all prime numbers
  // for (int p = 2; p <= 10000007; p++)
  //     if (prime[p])
  //         cout << p << " ";
}

int binarySearch(int left,int right,int n)
{
    if (left<=right)
    {
        int mid = (left + right)/2;
 
        // base condition is, if we are reaching at left
        // corner or right corner of primes[] array then
        // return that corner element because before or
        // after that we don't have any prime number in
        // primes array
        if (mid == 0 || mid == primes.size()-1)
            return primes[mid];
 
        // now if n is itself a prime so it will be present
        // in primes array and here we have to find nearest
        // prime less than n so we will return primes[mid-1]
        if (primes[mid] == n)
            return primes[mid-1];
 
        // now if primes[mid]<n and primes[mid+1]>n that
        // mean we reached at nearest prime
        if (primes[mid] < n && primes[mid+1] > n)
            return primes[mid];
        if (n < primes[mid])
            return binarySearch(left, mid-1, n);
        else
            return binarySearch(mid+1, right, n);
    }
    return 0;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());

    unordered_map<int, int> mp;
    for(int i = 0; i < n; ++i)
    {
        int a = arr[i];
        // int b = (a-1)/2;
        mp[a]++;
        // mp[b+1]--;
    }

    // int steps = 0;
    // int temp = 0;
    // for(int i = 1; i <= n; ++i)
    // {
    //     temp+=mp[i];
    //     if(temp == 0)
    //     {
    //         cout<<i<<endl;
    //         cout<<-1<<endl;
    //         return;
    //     }
    // }
    // for(int i = 1; i <= n; ++i)
    // {
    //     if(arr[i-1] != i)
    //     {
    //         steps++;
    //     }
    // }
    // cout<<steps<<endl;

    int steps = 0;
    for(int i = 1; i <= n; ++i)
    {
        int a = arr[i-1];
        if(a==i || mp[i]>0)
        {
            // cout<<"hello";
            continue;
        }
        else if(((a-1)/2) < i)
        {
            cout<<-1<<endl;
            return;
        }
        else
        {
            steps++;
        }
    }
    cout<<steps<<endl;
}

int main() {
    // SieveOfEratosthenes();
    Sieve();
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
