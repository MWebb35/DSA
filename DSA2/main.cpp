#include <iostream>
using namespace std;

#define V 8

int dijkstras(int graph[V][V], int startingNode, int targetNode){
    cout << "\nStarting node in function: " << startingNode;
    cout << "\nTarget node in function: " << targetNode;
    cout << "\nPosition in graph: " << graph[3][0];
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