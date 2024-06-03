#include <iostream>
using namespace std;

#include <limits.h>

//Define number of nodes within the graph
#define V 8

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

void fewestConnectingNodes(int graph[V][V], int source, int target){

    int path[3];

    //Sets the lowestDist to infinity initially - any path found is guarenteed to be lower so a path can always be chosen
    int lowestDist = INT_MAX;

    for (int i = 0; i < V; i++){
      int dist = 0;
      //Checks if the node is accessible by the source
      if (graph[source][i] != 0){
        //Checks if the node can access the target directly
        if (graph[i][target] != 0){
          //Prints all fewest connecting node paths
          printf("\nPath with fewest connecting points: %c %c %c", intToChar(source), intToChar(i), intToChar(target));
          dist = graph[source][i] + graph[i][target];
          printf("\nDistance: %d", dist);

          //Checks if distance is less than current lowest distance
          if (dist < lowestDist){
            lowestDist = dist;
            path[0] = source;
            path [1] = i;
            path[2] = target;
          }
        }
      }
    }

  //Prints out path with the fewest connecting points and the shortest distance of all fewest paths
  printf("\n\nPath with fewest connecting points and shortest distance: %c %c %c", intToChar(path[0]), intToChar(path[1]), intToChar(path[2]));
  printf("\nDistance: %d", lowestDist);
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
  //2 Dimensional array to represent the graph
  int graph [V][V] = {{0, 10, 0, 12, 0, 0, 11, 4},
  {10, 0, 0,8, 0, 0, 0, 20},
  {0, 0, 0, 17, 8, 0, 13, 10},
  {12, 8, 17, 0, 0, 16, 24, 14},
  {0, 0, 8, 0, 0, 8, 11, 5},
  {0, 0, 0, 16, 8, 0, 18, 21},
  {11, 0, 13, 24, 11, 0, 18, 30},
  {4, 20, 10, 14, 5, 21, 30, 0}};

  char sourceChar;
  char targetChar;

  cout << "Enter source node: ";
  cin >> sourceChar;

  cout << "\nEnter target node: ";
  cin >> targetChar;

  int source= charToInt(sourceChar);
  int target = charToInt(targetChar);
    

  //Checks if there is a direct connection between source and target 
  if (graph[source][target] != 0){
    printf("Path with fewest connecting points: %c %c ", sourceChar, targetChar);
    printf("\nDistance: %d", graph[source][target]);
  } else {
    fewestConnectingNodes(graph, source, target);
  }
}
