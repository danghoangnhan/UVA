#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
class node
{
public:
    int data;
    node *left, *right;
};
void printCurrentLevel(node *root, int level);
int height(node *node);
node *newNode(int data);

void printLevelOrder(node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

/* Print nodes at a current level */
void printCurrentLevel(node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}

node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}
char inputSamples[1000];
bool finished = false;
bool containsRoot = false;
int number;
char buff[20];

int main()
{

    while (cin >> inputSamples)
    {
        node *root;
        char *stringPtr = strtok(inputSamples, " ");
        while (stringPtr != NULL )
        {
            if (sizeof(stringPtr) == 2)
                break;
            cout << stringPtr << endl;
            sscanf(stringPtr, "(%d,%[^:])", &number, buff);
            cout << number << " " << buff << endl;
            if (buff==")"){
                containsRoot = true;
                if (root)
                {
                    root = newNode(number);
                }
                else
                {
                    root->data = number;
                }
            }
            else{
                if(!containsRoot)
                    root = newNode(INF);
                node *currentNode = root;
                for (long long int i; i < sizeof(buff); ++i){
                    if(buff[i]==')')
                        break;;
                    if(buff[i+1]!=')'){
                        if (buff[i] = 'L')
                        {
                            if(currentNode->left)
                                currentNode->left = newNode(INF);
                            currentNode = currentNode->left;
                        }
                        if (buff[i] == 'R'){
                            if(currentNode->right)
                                currentNode->right = newNode(INF);
                            currentNode = currentNode->right;
                        }
                    }
                    else{
                        if (buff[i] = 'L')
                        {
                            if(currentNode->left)
                                currentNode->left = newNode(number);
                            else
                                currentNode->left->data=number;
                        }
                        if (buff[i] == 'R')
                        {
                            if (currentNode->right)
                                currentNode->right = newNode(number);
                            else
                                currentNode->right->data = number;
                        }
                    }

                }
            }
            stringPtr = strtok(NULL, " ");
            
        }

        printLevelOrder(root);
    }
    return 0;
}