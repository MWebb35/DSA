#include <iostream>
using namespace std;

//Used to set the nodes to the maximum value of an integer (representative of infinity in dijkstra's algorithm)
#include <limits.h>

//Amount of Vertices within the graph
#define V 8

//Finds the node with the minimum distance from nodes not yet included in the shortest path
int minDistance(const int dist[V], const bool shortestPath[V]){

    int min = INT_MAX; //Set min to max integer value
    int min_index; //Initialise min_index but equate it to nothing

    //For every vertex in the graph
    for (int i = 0; i < V; i++){
        //If not included in the shortest path and the distance is less than min
        if (!shortestPath[i] && dist[i] <= min){
            //Update values
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

//Function that uses a switch case to change the int representations in the graph back to char
char intToChar(int changedChar){
    switch(changedChar){
        case 0:
            changedChar = 'A';
            break;
        case 1:
            changedChar = 'B';
            break;
        case 2:
            changedChar = 'C';
            break;
        case 3:
            changedChar = 'D';
            break;
        case 4:
            changedChar = 'E';
            break;
        case 5:
            changedChar = 'F';
            break;
        case 6:
            changedChar = 'G';
            break;
        case 7:
            changedChar = 'H';
            break;
        default:
            cout << "\nInvalid input received";
    }

    return changedChar;
}

//Prints the path from the source to target node
void printPath(int currentNode, int pathway[], int startingNode, int targetNode){
    //Base case - if currentNode = startingNode, print currentNode then exit
    if (currentNode == startingNode){
        cout << intToChar(currentNode) << " ";
        return;
    }

    //Recursive call to function
    printPath(pathway[currentNode], pathway, startingNode, targetNode);

    //Print each node - calls to intToChar and prints the output
    cout << intToChar(currentNode) << " ";
}

//Main Dijkstra function - finds the shortest path between two nodes
void dijkstras(int graph[V][V], int startingNode, int targetNode, char startingNodeChar, char targetNodeChar){
    //Holds the distance between the source node and all other nodes
    int dist[V];

    //Holds booleans to say if vertex included in shortestPath
    bool shortestPath[V];

    //Parent array to hold path - used to display path at end of program
    int pathway[V];

    /*Sets the source node distance to 0 and all other nodes to the max an integer can be
     * (so it is out of range of the source node)*/
    for (int i = 0; i < V; i++){
        //Distance from startingNode and itself is set to 0
        if (i == startingNode){
            dist[i] = 0;
            //Parent array values set to unachievable value - Dijkstra's cannot handle negative edges so -1 was chosen
            pathway[i] = -1;
        } else {
            dist[i] = INT_MAX;
            shortestPath[i] = false;
            pathway[i] = -1;
        }
    }

    //Evaluates the shortest path
    for (int i = 0; i < V; i++){
        int minV = minDistance(dist, shortestPath);
        shortestPath[minV] = true;

        for (int j = 0; j < V; j++){
            /*Conditions:
             * If the vertex is not yet included in shortestPath
             * If there is an edge between the minVertex and j
             * If dist at pos[minV] is not an infinite value
             * If dist at pos[minV] and the current known distance to j is shorter than the distance to j*/
            if (!shortestPath[j] && graph[minV][j] && dist[minV] != INT_MAX && dist[minV] + graph[minV][j] < dist[j]){
                //Update dist[j] to be this shorter value
                dist[j] = dist[minV] + graph[minV][j];
                //Add parent vertex to parent array
                pathway[j] = minV;
            }
        }
    }

    printf("\nShortest path from source (%c) to target (%c): ", startingNodeChar, targetNodeChar);
    //Call to printPath function
    printPath(targetNode, pathway, startingNode, targetNode);
    //Output distance
    printf("\nDistance: %d" ,dist[targetNode]);

}

//Function to change char input to int - makes it available to use within the function as the vertices within the 2d array graph are numbers
int charToInt(int changedInt){
    switch (changedInt){
        case 'A':
            changedInt = 0;
            break;
        case 'B':
            changedInt = 1;
            break;
        case 'C':
            changedInt = 2;
            break;
        case 'D':
            changedInt = 3;
            break;
        case 'E':
            changedInt = 4;
            break;
        case 'F':
            changedInt = 5;
            break;
        case 'G':
            changedInt = 6;
            break;
        case 'H':
            changedInt = 7;
            break;
        default:
            cout << "\nInvalid input received";
    }

    return changedInt;
}

int main() {
    //2 dimensional array to hold the graph - representative of an adjacency matrix
    int graph [V][V] = {{0, 10, 0, 12, 0, 0, 11, 4},
                        {10, 0, 0,8, 0, 0, 0, 20},
                        {0,0,0,17,8,0,13,10},
                        {12,8,17,0,0,16,24,14},
                        {0,0,8,0,0,8,11,5},
                        {0,0,0,16,8,0,18,21},
                        {11, 0, 13, 24, 11, 0, 18, 30},
                        {4, 20, 10, 14, 5,21, 30,0}};

    //Prompt for user to enter starting node
    char startingNode;
    cout << "\nEnter starting node: ";
    cin >> startingNode;

    //Prompt for user to enter target node
    char targetNode;
    cout << "\nEnter target node: ";
    cin >> targetNode;

    //Converts values from char to int
    int startingNodeInt = charToInt(startingNode);
    int targetNodeInt = charToInt(targetNode);

    //Call to dijkstra with necessary parameters
    dijkstras(graph, startingNodeInt, targetNodeInt, startingNode, targetNode);

    return 0;
}
