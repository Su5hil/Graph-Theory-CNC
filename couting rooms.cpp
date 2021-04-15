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
char grid[31][31];
int dis[31][31], vis[31][31];
int dx[4] = { -1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isValid(int x, int y, int n) {
  if (x < 0 || x > n - 1 || y < 0 || y > n - 1) {
    return false;
  }
  if (vis[x][y] == 1) {
    return false;
  }
  return true;
}

void bfs(int srcx, int srcy, int n) {
  queue<pair<int, int>> q;
  vis[srcx][srcy] = 1;
  dis[srcx][srcy] = 0;

  while (!q.empty()) {
    int currx = q.front().first;
    int curry = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      if (isValid(currx + dx[i], curry + dy[i], n))
      {
        int newx = currx + dx[i];
        int newy = curry + dy[i];
        dis[newx][newy] = dis[currx][curry] + 1;
        vis[newx][newy] = 1;
        q.push({newx, newy});
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, a, b, c, d;
  cin >> n;
  loop(i, 0, n) {
    loop(j, 0, n) {
      cin >> grid[i][j];
      if (grid[i][j] == 'S') {
        a = i, b = j;
      }
      if (grid[i][j] == 'E') {
        c = i, d = j;
      }
    }
  }
  bfs(a, b, n);
  cout << dis[c][d] << endl;
  return 0;
}
