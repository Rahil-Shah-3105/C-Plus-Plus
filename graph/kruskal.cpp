#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
//#include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
const int mx = 1e6 + 5;
using ll = int64_t;

std::array<ll, mx> parent;
ll node, edge;
std::vector<std::pair<ll, std::pair<ll, ll>>> edges;
void initial() {
	std::cerr << ">>> Entering initial()" << std::endl;
    for (int i = 0; i < node + edge; ++i) {
        parent[i] = i;
    }
	std::cerr << "<<< Exiting initial()" << std::endl;
}

int root(int i) {
	std::cerr << ">>> Entering root(i=" << i << ")" << std::endl;
    while (parent[i] != i) {
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
	std::cerr << "<<< Exiting root(i=" << i << ")" << std::endl;
    return i;
}

void join(int x, int y) {
	std::cerr << ">>> Entering join(x=" << x << ",y=" << y << ")" << std::endl;
    int root_x = root(x);  // Disjoint set union by rank
	std::cerr << "<<< Exiting join(x=" << x << ",y=" << y << ")" << std::endl;
	std::cerr << "join(x=" << x << ",y=" << y << "): root_x → " << root_x << std::endl;
    int root_y = root(y);
	std::cerr << "join(x=" << x << ",y=" << y << "): root_y → " << root_y << std::endl;
    parent[root_x] = root_y;
}

ll kruskal() {
	std::cerr << ">>> Entering kruskal()" << std::endl;
    ll mincost = 0;
    for (int i = 0; i < edge; ++i) {
        ll x = edges[i].second.first;
        ll y = edges[i].second.second;
        if (root(x) != root(y)) {
            mincost += edges[i].first;
            join(x, y);
        }
    }
	std::cerr << "<<< Exiting kruskal()" << std::endl;
    return mincost;
}

int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    while (true) {
        int from = 0, to = 0, cost = 0, totalcost = 0;
        std::cin >> node >> edge;  // Enter the nodes and edges
        if (node == 0 && edge == 0) {
            break;  // Enter 0 0 to break out
        }
        initial();  // Initialise the parent array
        for (int i = 0; i < edge; ++i) {
            std::cin >> from >> to >> cost;
            edges.emplace_back(make_pair(cost, std::make_pair(from, to)));
            totalcost += cost;
        }
        sort(edges.begin(), edges.end());
        std::cout << kruskal() << std::endl;
        edges.clear();
    }
	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
