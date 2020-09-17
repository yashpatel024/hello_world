#include <bits/stdc++.h>
using namespace std;

struct Node 
{ 
    int data; 
    Node* right;
    Node* left; 
};

//generating perfect binary tree
struct Node* perfectBinaryTree(int value[], struct Node* currentNode, int index, int nodes){
    if(index < nodes){
        struct Node* tempNode = (struct Node*)malloc(sizeof(struct Node));

        tempNode->data = value[index];
        tempNode->left= NULL;
        tempNode->right = NULL;
        currentNode = tempNode;
        
        currentNode->left = perfectBinaryTree(value, currentNode->left, (2*index)+1, nodes);
        currentNode->right = perfectBinaryTree(value, currentNode->right, (2*index)+2, nodes);
    }
    return currentNode;
}

//function for printing generated tree in level-order
void orderTraversal(struct Node* root){
    if (root == NULL) return; 
  
    queue<struct Node *> qNodes; 

    Node *currentNode; 
   
    qNodes.push(root); 
    qNodes.push(NULL); 
  
    while (qNodes.size() > 1){ 
        currentNode = qNodes.front(); 
        qNodes.pop(); 

        if (currentNode == NULL){ 
           qNodes.push(NULL); 
           cout << "\n";
           
        }else{
            if(currentNode->left)
                qNodes.push(currentNode->left); 
            if(currentNode->right) 
                qNodes.push(currentNode->right); 
              
            cout<<currentNode->data<<" "; 
        } 
    } 
}

//function for checking if sum of vector of element is same as the target
int checkSum(vector<int> ele, int target){
    int sum=accumulate(ele.begin(), ele.end(), 0);
    if(sum==target){
        cout<<"path = ";
        for(int i=0; i<ele.size(); i++){
            cout<<ele[i]<<" ";
        }
        cout<<endl;
        return 1;
    }else if(sum>target)return -1;
    else return 0;
    
}
void sumFind(struct Node* node, int target, vector<int> temp){
    if(node == NULL) return;

    temp.push_back(node->data);

    // 0-if sum doesn't exist then travel more, 
    // 1-if sum match then printing and stop on that path
    // -1-if sum exceeds then stop on that path
    int check=checkSum(temp, target);
    if(check==0){
        sumFind(node->left,target,temp);
        sumFind(node->right,target,temp);
    }
}

void findPaths(struct Node* cNode, int target){
    if(cNode == NULL) return;

    vector<int> temp;
    temp.push_back(cNode->data);

    //traversing to both side
    sumFind(cNode->left,target,temp);
    sumFind(cNode->right,target,temp);

    //moving into next level of tree 
    findPaths(cNode->left,target);
    findPaths(cNode->right,target);
}

int main(){
    srand(time(0));//random number generation every time

    int depth, nodes, sum;
    cout<<"Enter depth = ";cin>>depth;

    nodes = pow(2,depth+1)-1;
    int value[nodes];

    //Automatic initialization
    int randNum;
    for(int i=0;i<nodes;i++){
        randNum = rand() %100 + 1;
        value[i] = randNum;
    }

    //creat perfect binary tree
    Node* root = perfectBinaryTree(value, root, 0, nodes);

    //printing of tree
    orderTraversal(root);
    
    //Paths checking of given sum
    while(true){
        cout<<"\nEnter sum (0 to exit)= ";cin>>sum;
        if(sum==0)break;
        findPaths(root, sum);
    }
}