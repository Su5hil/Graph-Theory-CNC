#include<bits/stdc++.h>
using namespace std;
#define loop(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define lli long long int
#define sci(x) scanf("%d",&x)
#define scii(x,y) scanf("%d %d",&x,&y)
#define scl(x) scanf("%lld",&x)
#define scs(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;
typedef vector<int>   vi;
typedef vector<ll>    vl;
typedef vector<pii>   vpii;
typedef vector<pl>    vpl;
typedef vector<vi>    vvi;
typedef vector<vl>    vvl;
vi arr[100001];
vi primes;
int dist[100001];
int vis[100001];

bool isPrime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)return false;
  }
  return true;
}
bool isValid(int a, int b) {
  int c = 0;
  while (a > 0) {
    if (a % 10 != b % 10) {
      c++;
    }
    a /= 10;
    b /= 10;
  }
  if (c == 1)
    return true;
  else
    return false;
}
void buildGraph() {
  for (int i = 1000; i <= 9999; i++) {
    if (isPrime(i)) {
      primes.pb(i);
    }
  }
  for (int i = 0; i < primes.size(); i++) {
    for (int j = i + 1; j < primes.size(); j++) {
      int a = primes[i];
      int b = primes[j];
      if (isValid(a, b)) {
        arr[a].pb(b);
        arr[b].pb(a);
      }
    }
  }
}
void bfs(int src ) {
  queue<int> q;
  q.push(src);
  vis[src] = 1;
  dist[src] = 0;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (int child : arr[curr]) {
      if (vis[child] == 0) {
        q.push(child);
        dist[child] = dist[curr] + 1;
        vis[child] = 1;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t = 1;
  cin >> t;
  buildGraph();
  while (t--) {
    int m, n;
    cin >> m >> n;
    for (int i = 1000; i <= 9999; i++) {
      dist[i] = -1;
      vis[i] = 0;
    }
    bfs(m);
    if (dist[n] == -1) {
      cout << "Impossible" << '\n';
    }
    else
      cout << dist[n] << '\n';
  }
  return 0;
}
