// C++ Program to find height of the tree using bottom-up dynamic programming.

/*
 * Given a rooted tree with node 1.
 * Task is to find the height of the tree.
 * Example: -
 * 4
 * 1 2
 * 1 3
 * 2 4
 * which can be represented as
 *   1
 *  / \
 * 2   3
 * |
 * 4
 *
 * Height of the tree : - 2
 */

#include <iostream>
#include <vector>

// global declarations
// no of nodes max limit.
const int MAX = 1e5;
// adjacency list
std::vector<int> adj[MAX];
std::vector<bool> visited;
std::vector<int> dp;

void depth_first_search(int u) {
	std::cerr << ">>> Entering depth_first_search(u=" << u << ")" << std::endl;
    visited[u] = true;
    int child_height = 1;
	std::cerr << "depth_first_search(u=" << u << "): child_height → " << child_height << std::endl;
    for (int v : adj[u]) {
        if (!visited[v]) {
            depth_first_search(v);

            // select maximum sub-tree height from all children.
            child_height = std::max(child_height, dp[v] + 1);
        }
    }
    // assigned the max child height to current visited node.
    dp[u] = child_height;
	std::cerr << "<<< Exiting depth_first_search(u=" << u << ")" << std::endl;
}

int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    // number of nodes
    int number_of_nodes;
    std::cout << "Enter number of nodes of the tree : " << std::endl;
    std::cin >> number_of_nodes;

    // u, v denotes an undirected edge of tree.
    int u, v;
    // Tree contains exactly n-1 edges where n denotes the number of nodes.
    std::cout << "Enter edges of the tree : " << std::endl;
    for (int i = 0; i < number_of_nodes - 1; i++) {
        std::cin >> u >> v;
        // undirected tree u -> v and v -> u.
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // initialize all nodes as unvisited.
    visited.assign(number_of_nodes + 1, false);
    // initialize depth of all nodes to 0.
    dp.assign(number_of_nodes + 1, 0);
    // function call which will initialize the height of all nodes.
    depth_first_search(1);
    std::cout << "Height of the Tree : " << dp[1] << std::endl;
	std::cerr << "<<< Exiting main()" << std::endl;
}
