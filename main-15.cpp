/**************************

 *

 * HEADER

 *Got help from A TA

 *Abdul Gaffir Zambi

 * ************************/


#include <iostream>

#include <fstream>

#include <vector>

#include <string>

#include <iomanip>

#include <cassert>

using namespace std;


//************************** Node *************************


class Node{

public:

    int value; // storing integers

    Node* pNext; // storing memory addresses

    

    

    Node(int val){

        value = val;

        pNext = NULL;

    }

    

    Node(){};

};



//************************** Graph ****************************

class Graph {

    public:

        //add the node with neighborId as the neighbor of nodeId

        void addNeighbor(int nodeId, int neighborId);


        //reads the edge list from file and creates the adjacency list data structure

        void loadGraph(string edgeListFileName);

        

        //writes the adjacency list into the file

        void dumpGraph(string adjListFileName);


        //Prints number of nodes, number of edges, and maximum degree on terminal

        void printGraphInfo();


        //returns the number of neighbor (degree) of a node

    int getNumNeighbors(int nodeId){


        if (vertices.at(nodeId) == NULL) {

       return 0;

       }

       Node *pHead = vertices.at(nodeId); //Is this the start of the list


        Node *pTemp = pHead;


        int counter = 0;


        while (pTemp != NULL) {

       counter += 1;

       pTemp = pTemp->pNext;

      }


      return counter;

            

        }


        //returns the number of nodes in the graph

    int getNumVertices(){

        int count = 0;

        for (int i = 0; i < vertices.size(); i++) {

            if (vertices.at(i) != NULL) {

                

                count += 1;

            }

        }

        return count;

    }

    private:

    // int -> numbers

    // Node * -> Memory addresses of type Node

    // vertices -> Multiple memory addresses of type Node. Always at the first element of the list

    

        vector<Node*> vertices;

        

};




void Graph :: addNeighbor(int nodeId, int neighborId){

    Node* pHead = vertices[nodeId];

    Node* pTemp = pHead;

    // pTemp -> 3->5->7 neighbor = pTemp-> 2->3->5->7

    // Inseeting at the beginning

    Node *newNode =new Node(neighborId) ;

   // newNode->value = neighborId;

    

    // Check for duplicates

    while(pTemp != NULL) {

        if(pTemp->value == neighborId) {

            return;

        }

        pTemp = pTemp->pNext;

    }

    pTemp = pHead;

    if (neighborId < pTemp->value){

        // accessing the variable that storing memory addresses

        // and setting it to another memory address (pTemp)

        newNode->pNext = pTemp;

        vertices.at(nodeId) = newNode;

        return;

    }

    // Check middle

    // 3->5->7 neighbor =

    // newNode-> 4->5

    // pTemp -> 3->5->7

    // 1. 4->5 3->4

    // 2. 3->4 4->5

    // 3->5->7->null

    // pTemp -> 7 -> NULL

    // Insert in the middle

    while (pTemp->pNext != NULL){

        if (neighborId > pTemp->value && neighborId < pTemp->pNext->value) {

            newNode->pNext = pTemp->pNext;

            pTemp->pNext = newNode;

            return;

        }

       pTemp = pTemp->pNext;

     }
    
    if (pTemp->pNext == NULL){
        pTemp->pNext =newNode;
        newNode->pNext = NULL;
        return;
    }

    // Insert in the end

    // pTemp -> 7 -> null

    // newNode -> 8


}



void Graph:: dumpGraph(string adjListFileName){
    ofstream outStream;
    outStream.open(adjListFileName);
    assert(outStream.fail() == false);
   
    for (int i = 0; i < vertices.size();i++){
        Node* pTemp = vertices.at(i);
        if (pTemp == NULL){

            continue;
        }
        else{
            outStream << i << ":";
            cout << i << ":";
        }
        while (pTemp != NULL) {
            //if (pTemp != NULL) {

                outStream << " " << pTemp->value;
                cout << " " << pTemp->value;
//           // }
//            else {
//                outStream << " "<<pTemp->value;
//                cout << " " << pTemp->value;
//            }
            pTemp = pTemp->pNext;
        }
        outStream << endl;
        cout << endl;
    }
   // outStream << endl;

    outStream.close();

}




void Graph::loadGraph(string edgeListFileName){

    

    ifstream file;

    file.open(edgeListFileName);

    int edge1;

    int edge2;

    

    while (!file.eof()){

        file >> edge1;

        file >> edge2;

        
        if (edge1 >= (vertices.size())){

            vertices.resize(edge1 + 1);

        }

        

        if (edge2 >= (vertices.size())){

            vertices.resize(edge2 + 1);

        }


        // vertices.at(5) = NULL

        // insert a node with value 5

        if(vertices.at(edge1) == NULL) {

            vertices.at(edge1) = new Node(edge2);

            //vertices.at(edge1)->value = edge2;

        } else {

            addNeighbor(edge1, edge2);

        }

        if (vertices.at(edge2) == NULL) {

            vertices.at(edge2) = new Node(edge1);

         //   vertices.at(edge2)->value = edge1;

        } else {

            addNeighbor(edge2, edge1);

        }

    }

    

}


void Graph:: printGraphInfo(){

    

    

    int edges = 0;

    int sum = 0;

    

   

    for (int i = 0; i < vertices.size(); i++) {


    edges += getNumNeighbors(i);


   }

    

    


    for(int j = 0; j<vertices.size(); j ++){


    if (getNumNeighbors(j)>sum){


    sum = getNumNeighbors(j);


    }


    }

    

    cout << "Number of nodes: " << getNumVertices() << endl;

    cout << "Number of edges: " << edges/2 << endl;

    cout << "Maximum degree: "  << sum << endl;

    

}



void run(string edgeListFileName, string adjListFileName) {

    Graph graph;

    graph.loadGraph(edgeListFileName);

    graph.getNumVertices();

    graph.printGraphInfo();

    graph.dumpGraph(adjListFileName);

}


//*****************************************************************************



// The main will be removed for testing, do not add any code in the main function

int main() {

    //Change the filenames according to your local path.

    string edgeListFileName("karate.txt");

    string adjListFileName("karate_adj.txt");

    run(edgeListFileName, adjListFileName);

    return 0;

}
