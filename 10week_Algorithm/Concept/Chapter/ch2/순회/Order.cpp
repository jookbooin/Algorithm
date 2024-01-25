#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1004];
int visited[1004];

/**
  * postorder( node )
  * if (node.visited == false) 
  *     postorder( node->left ) 
  *     postorder( node->right )
  *     node.visited = true
*/

void postOrder(int here){
    
    if(visited[here] == 0){

        if(adj[here].size() == 1) postOrder(adj[here][0]);
        if(adj[here].size() == 2){
            postOrder(adj[here][0]);
            postOrder(adj[here][1]);
        }
        visited[here] = 1;
        cout << here << ' ';
    }
}


/**
  * preorder( node )
  *  if (node.visited == false)
  *      node.visited = true
  *      preorder( node->left )
  *      preorder( node->right )  *
*/

void preOrder(int here){
    if(visited[here] == 0){
        visited[here] = 1;
        cout << here << ' ';
        if(adj[here].size() == 1) preOrder(adj[here][0]);
        if(adj[here].size() == 2){
            preOrder(adj[here][0]);
            preOrder(adj[here][1]);
        }
    }
}

/**
 * inorder( node )
 *  if (node.visited == false) 
 *      inorder( node->left )
 *      node.visited = true
 *      inorder( node->right )
*/

void inOrder(int here){
    if(visited[here] == 0){
        if(adj[here].size() == 1){
            inOrder(adj[here][0]);
            visited[here] = 1;
            cout << here << ' ';
        }else if(adj[here].size == 2){}
            inOrder(adj[here][0]);
            
            visited[here] = 1;
            cout << here << ' ';

            inOrder(adj[here][1]);
    }
}

int main(void){
    
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(5);

    int root = 1;


    return 0;
}