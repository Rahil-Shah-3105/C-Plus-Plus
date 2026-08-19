#include <iostream>
using namespace std;

#define V 4
#define INFINITY 99999

int graph[V][V] = {{0, 5, 1, 2}, {5, 0, 3, 3}, {1, 3, 0, 4}, {2, 3, 4, 0}};

struct mst {
    bool visited;
    int key;
    int near;
};

mst MST_Array[V];

void initilize() {
	std::cerr << ">>> Entering initilize()" << std::endl;
    for (int i = 0; i < V; i++) {
        MST_Array[i].visited = false;
        MST_Array[i].key = INFINITY;  // considering INFINITY as inifinity
        MST_Array[i].near = i;
    }

    MST_Array[0].key = 0;
	std::cerr << "<<< Exiting initilize()" << std::endl;
}

void updateNear() {
	std::cerr << ">>> Entering updateNear()" << std::endl;
    for (int v = 0; v < V; v++) {
        int min = INFINITY;
		std::cerr << "updateNear(): min → " << min << std::endl;
        int minIndex = 0;
		std::cerr << "updateNear(): minIndex → " << minIndex << std::endl;
        for (int i = 0; i < V; i++) {
            if (MST_Array[i].key < min && MST_Array[i].visited == false &&
                MST_Array[i].key != INFINITY) {
                min = MST_Array[i].key;
                minIndex = i;
            }
        }

        MST_Array[minIndex].visited = true;

        for (int i = 0; i < V; i++) {
            if (graph[minIndex][i] != 0 && graph[minIndex][i] < INFINITY) {
                if (graph[minIndex][i] < MST_Array[i].key) {
                    MST_Array[i].key = graph[minIndex][i];
                    MST_Array[i].near = minIndex;
                }
            }
        }
    }
	std::cerr << "<<< Exiting updateNear()" << std::endl;
}

void show() {
	std::cerr << ">>> Entering show()" << std::endl;
    for (int i = 0; i < V; i++) {
        cout << i << "  -  " << MST_Array[i].near << "\t"
             << graph[i][MST_Array[i].near] << "\n";
    }
	std::cerr << "<<< Exiting show()" << std::endl;
}

int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    initilize();
    updateNear();
    show();
	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
