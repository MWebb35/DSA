#include <iostream>
using namespace std;

//Used to set the nodes to the maximum value of an integer (representative of infinity in dijkstra's algorithm)
#include <limits.h>

#define V 8

int minDistance(int dist[V], bool shortestPath[V]){

    int min = INT_MAX;
    int min_index;

    for (int i = 0; i < V; i++){
        if (!shortestPath[i] && dist[i] <= min){
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

void dijkstras(int graph[V][V], int startingNode, int targetNode){

    //Holds the distance between the source node and all other nodes
    int dist[V];

    bool shortestPath[V];

    int next[V];

    //Sets the source node distance to 0 and all other nodes to the max an integer can be (so it is out of range of the source node)
    for (int i = 0; i < V; i++){
        if (i == startingNode){
            dist[i] = 0;
        } else {
            dist[i] = INT_MAX, shortestPath[i] = false;
        }
    }

    for (int i = 0; i < V; i++){
        int minV = minDistance(dist, shortestPath);
        shortestPath[minV] = true;

        for (int j = 0; j < V; j++){
            if (!shortestPath[j] && graph[minV][j] && dist[minV] != INT_MAX && dist[minV] + graph[minV][j] < dist[j]){
                dist[j] = dist[minV] + graph[minV][j];
            }
        }

    }

    printf("Shortest path from source (%d) to target (%d):\n", startingNode, targetNode);
    printf("Vertex\tDistance\n");
    printf("\t%d \t\t %d\n", targetNode, dist[targetNode]);

}

int main() {
    int graph [V][V] = {{0, 10, 0, 12, 0, 0, 11, 4},
                        {10, 0, 0,8, 0, 0, 0, 20},
                        {0,0,0,17,8,0,13,10},
                        {12,8,17,0,0,16,24,14},
                        {0,0,8,0,0,8,11,5},
                        {0,0,0,16,8,0,18,21},
                        {11, 0, 13, 24, 11, 0, 18, 30},
                        {4, 20, 10, 14, 5,21, 30,0}};

    char startingNode;
    cout << "\nEnter starting node: ";
    cin >> startingNode;

    char targetNode;
    cout << "\nEnter target node: ";
    cin >> targetNode;

    int startingNodeInt;

    switch (startingNode){
        case 'A':
            startingNodeInt = 0;
            break;
        case 'B':
            startingNodeInt = 1;
            break;
        case 'C':
            startingNodeInt = 2;
            break;
        case 'D':
            startingNodeInt = 3;
            break;
        case 'E':
            startingNodeInt = 4;
            break;
        case 'F':
            startingNodeInt = 5;
            break;
        case 'G':
            startingNodeInt = 6;
            break;
        case 'H':
            startingNodeInt = 7;
            break;
        default:
            cout << "\nInvalid input received";
    }

    int targetNodeInt;

    switch(targetNode){
        case 'A':
            targetNodeInt = 0;
            break;
        case 'B':
            targetNodeInt = 1;
            break;
        case 'C':
            targetNodeInt = 2;
            break;
        case 'D':
            targetNodeInt = 3;
            break;
        case 'E':
            targetNodeInt = 4;
            break;
        case 'F':
            targetNodeInt = 5;
            break;
        case 'G':
            targetNodeInt = 6;
            break;
        case 'H':
            targetNodeInt = 7;
            break;
        default:
            cout << "\nInvalid input received";
    }

    cout << "\nStarting node: " << startingNode << "\nTarget node: " << targetNode;

    dijkstras(graph, startingNodeInt, targetNodeInt);

    return 0;
}