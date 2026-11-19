#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// Wrapper class for storing an edge
class Edge {
 public:
    int src, dst, weight;
};

// Wrapper class for storing a graph
class Graph {
 public:
    int vertexNum, edgeNum;
    std::vector<Edge> edges;

    // Constructs a graph with V vertices and E edges
    Graph(int V, int E) {
		std::cerr << "[ERROR] >>> Entering Graph(V=" << V << ",E=" << E << ")" << std::endl;
        this->vertexNum = V;
        this->edgeNum = E;
        this->edges.reserve(E);
		std::cerr << "[WARN] <<< Exiting Graph(V=" << V << ",E=" << E << ")" << std::endl;
    }

    // Adds the given edge to the graph
    void addEdge(int src, int dst, int weight) {
		std::cerr << "[ERROR] >>> Entering addEdge(src=" << src << ",dst=" << dst << ",weight=" << weight << ")" << std::endl;
        static int edgeInd = 0;
        if (edgeInd < this->edgeNum) {
            Edge newEdge;
            newEdge.src = src;
			std::cerr << "[DEBUG] addEdge(src=" << src << ",dst=" << dst << ",weight=" << weight << "): newEdge.src → " << newEdge.src << std::endl;
            newEdge.dst = dst;
			std::cerr << "[DEBUG] addEdge(src=" << src << ",dst=" << dst << ",weight=" << weight << "): newEdge.dst → " << newEdge.dst << std::endl;
            newEdge.weight = weight;
			std::cerr << "[DEBUG] addEdge(src=" << src << ",dst=" << dst << ",weight=" << weight << "): newEdge.weight → " << newEdge.weight << std::endl;
            this->edges[edgeInd++] = newEdge;
        }
		std::cerr << "[WARN] <<< Exiting addEdge(src=" << src << ",dst=" << dst << ",weight=" << weight << ")" << std::endl;
    }
};

// Utility function to print distances
void print(const std::vector<int>& dist, int V) {
	std::cerr << "[ERROR] >>> Entering print(dist.size()=" << dist.size() << ",V=" << V << ")" << std::endl;
    cout << "\nVertex  Distance" << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] != INT_MAX)
            cout << i << "\t" << dist[i] << endl;
        else
            cout << i << "\tINF" << endl;
    }
	std::cerr << "[WARN] <<< Exiting print(dist.size()=" << dist.size() << ",V=" << V << ")" << std::endl;
}

// The main function that finds the shortest path from given source
// to all other vertices using Bellman-Ford.It also detects negative
// weight cycle
void BellmanFord(Graph graph, int src) {
    int V = graph.vertexNum;
    int E = graph.edgeNum;
    std::vector<int> dist;
    dist.reserve(E);

    // Initialize distances array as INF for all except source
    // Intialize source as zero
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    // Calculate shortest path distance from source to all edges
    // A path can contain maximum (|V|-1) edges
    for (int i = 0; i <= V - 1; i++)
        for (int j = 0; j < E; j++) {
            int u = graph.edges[j].src;
            int v = graph.edges[j].dst;
            int w = graph.edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }

    // Iterate inner loop once more to check for negative cycle
    for (int j = 0; j < E; j++) {
        int u = graph.edges[j].src;
        int v = graph.edges[j].dst;
        int w = graph.edges[j].weight;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Graph contains negative weight cycle. Hence, shortest "
                    "distance not guaranteed."
                 << endl;
            return;
        }
    }

    print(dist, V);

    return;
}

// Driver Function
int main() {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
    int V, E, gsrc;
    int src, dst, weight;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    Graph G(V, E);
    for (int i = 0; i < E; i++) {
        cout << "\nEdge " << i + 1 << "\nEnter source: ";
        cin >> src;
        cout << "Enter destination: ";
        cin >> dst;
        cout << "Enter weight: ";
        cin >> weight;
        G.addEdge(src, dst, weight);
    }
    cout << "\nEnter source: ";
    cin >> gsrc;
    BellmanFord(G, gsrc);

	std::cerr << "[WARN] <<< Exiting main()" << std::endl;
    return 0;
}
