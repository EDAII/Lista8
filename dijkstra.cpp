#include <bits/stdc++.h>
#define oo 0x3f3f3f3f

using namespace std;

int n, e;
vector< vector< pair<int, int> > > adj;

struct node {
  int x, cst;
  node(int x, int cst) : x(x), cst(cst) {}
  inline bool operator<(const node &a) const { return a.cst < cst;}
};

int dijk(int src, int des) {
  vector<int> cost(n + 1, oo);
  priority_queue<node> que;
  que.push(node(src, 0));
  cost[src] = 0;
  while (que.size()) {
    int x = que.top().x, cst = que.top().cst;
    que.pop();
    if (x == des) {
      sort(cost.rbegin(), cost.rend());

      for (auto & v : cost)
        if (v != oo && v != 0)
          cout << v << " ";
      cout << endl << endl << endl;

      return cst;
    }
    for (int i = 0, ln = adj[x].size(); i < ln; ++i) {
      int y = adj[x][i].first, _cst = adj[x][i].second;
      if (cst + _cst < cost[y]) {
        cost[y] = cst + _cst;
        que.push(node(y, cost[y]));
      }
    }
  }
}
int main() {
  int q;
  cin >> n >> e >> q; // query
  adj.clear();
  adj.resize(n + 1);
  while (e--) {
    int x, y, z; //pair of nodes, cost
    cin >> x >> y >> z;
    adj[x].push_back(make_pair(y, z));
  }
  while (q--) {
    int src, des;
    cin >> src >> des;
    cout << dijk(src, des) << endl;
  }
  return 0;
}
/*
    3
a ----- b
 1\  1/  |2   
   c     |
    \    d
     \   |
     8\  |4
       \ |
        \|
         f
a=1
b=2
c=3
d=4
f=5

5 12 1
1 2 3
2 1 3
1 3 1
3 1 1
2 3 1
3 2 1
2 4 2
4 2 2
3 5 8
5 3 8
4 5 4
5 4 4
1 5
*/