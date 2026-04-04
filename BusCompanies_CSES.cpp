#include <vector>
#include <iostream>
#include <utility>
#include <set>;
using namespace std;

int main() {
 int n, m, c, k, temp;
 cin >> n >> m;
 vector<vector<int>> company_to_cities(m, vector<int>());
 vector<vector<pair<int,int>>> adj(m, vector<pair<int, int>>());
 vector<vector<int>> cities_to_companies(n+1, vector<int>());
 vector<int> cost(n+1, 100000000);
 set<int> seen;
 for (int i{0}; i < m; i++) {
  cin >> c;
  cost[i] = c;
 }

 for (int i{0}; i < m; i++) {
  cin >> k;
  for (int j{0}; j < k; j++) {
   cin >> temp;
   company_to_cities[i].push_back(temp);
   cities_to_companies[temp].push_back(i);
   if (seen.count(temp) == 0) seen.insert(temp);
   else {
    for (int comp: cities_to_companies[temp]) {
     adj[i].push_back({cost[temp], temp});
     adj[temp].push_back({cost[i], i});

    }
   }
  }
 }




}