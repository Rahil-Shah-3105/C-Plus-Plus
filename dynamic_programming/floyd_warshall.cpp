#include <climits>
#include <cstddef>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

// Wrapper class for storing a graph
class Graph {
 public:
    int vertexNum;
    int **edges;

    // Constructs a graph with V vertices and E edges
    Graph(int V) {
		std::cerr << ">>> Entering Graph(V=" << V << ")" << std::endl;
        this->vertexNum = V;
        this->edges = new int *[V];
        for (int i = 0; i < V; i++) {
            this->edges[i] = new int[V];
            for (int j = 0; j < V; j++) this->edges[i][j] = INT_MAX;
            this->edges[i][i] = 0;
        }
		std::cerr << "<<< Exiting Graph(V=" << V << ")" << std::endl;
    }

    ~Graph() {
		std::cerr << ">>> Entering ~Graph()" << std::endl;
        for (int i = 0; i < vertexNum; i++) {
            delete[] edges[i];
        }
        delete[] edges;
		std::cerr << "<<< Exiting ~Graph()" << std::endl;
    }

    // Adds the given edge to the graph
    void addEdge(int src, int dst, int weight) {
		std::cerr << ">>> Entering addEdge(src=" << src << ",dst=" << dst << ",weight=" << weight << ")" << std::endl;
        this->edges[src][dst] = weight;
		std::cerr << "<<< Exiting addEdge(src=" << src << ",dst=" << dst << ",weight=" << weight << ")" << std::endl;
    }
};

// Utility function to print distances
void print(const std::vector<int>& dist, int V) {
	std::cerr << ">>> Entering print(dist=" << dist << ",V=" << V << ")" << std::endl;
    cout << "\nThe Distance matrix for Floyd - Warshall" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i * V + j] != INT_MAX)
                cout << dist[i * V + j] << "\t";
            else
                cout << "INF"
                     << "\t";
        }
        cout << endl;
    }
	std::cerr << "<<< Exiting print(dist=" << dist << ",V=" << V << ")" << std::endl;
}

// The main function that finds the shortest path from a vertex
// to all other vertices using Floyd-Warshall Algorithm.
void FloydWarshall(Graph graph) {
	std::cerr << ">>> Entering FloydWarshall(graph=" << graph << ")" << std::endl;
    std::size_t V = graph.vertexNum;
    std::vector<std::vector<int> > dist(V, std::vector<int>(V));

    // Initialise distance array
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) dist[i][j] = graph.edges[i][j];

    // Calculate distances
    for (int k = 0; k < V; k++)
        // Choose an intermediate vertex

        for (int i = 0; i < V; i++)
            // Choose a source vertex for given intermediate

            for (int j = 0; j < V; j++)
                // Choose a destination vertex for above source vertex

                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                    // If the distance through intermediate vertex is less than
                    // direct edge then update value in distance array
                    dist[i][j] = dist[i][k] + dist[k][j];

    // Convert 2d array to 1d array for print
    std::vector<int> dist1d(V * V);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) dist1d[i * V + j] = dist[i][j];

    print(dist1d, V);
	std::cerr << "<<< Exiting FloydWarshall(graph=" << graph << ")" << std::endl;
}

// Driver Function
int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    int V, E;
    int src, dst, weight;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    Graph G(V);
    for (int i = 0; i < E; i++) {
        cout << "\nEdge " << i + 1 << "\nEnter source: ";
        cin >> src;
        cout << "Enter destination: ";
        cin >> dst;
        cout << "Enter weight: ";
        cin >> weight;
        G.addEdge(src, dst, weight);
    }
    FloydWarshall(G);

	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
