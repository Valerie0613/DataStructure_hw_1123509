// hw_1123509
// Valerie_1123509_2024/11/27
// Level order traversal, processing from left to right (using a queue for first-in, first-out)
// Create root 1, i=0
// [1] is added to the queue
// Remove node (val) 1
// Create nodes 2 (left child) i=1, and 3 (right child) i=2
// [2, 3]

// Remove 2
// Create nodes 4 (i=3) and 5 (i=4)
// [3, 4, 5]

// Remove 3
// Create nodes -1 (i=5) and -1 (i=6), skip the left and right child nodes
// [4, 5]

// Remove 4
// Create nodes -1 (i=7) and -1 (i=8), skip the left and right child nodes
// [5]
// Remove 5
// Create nodes 6 (i=9) and 7 (i=10)
// [6, 7]
// Remove 6 and 7
// i=11, i<v.size()=11

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build the binary tree using level-order input
TreeNode* buildTree(const vector<int>& levelOrder)
{
    if (levelOrder.empty() || levelOrder[0] == -1)
        return nullptr;

    TreeNode* root = new TreeNode(levelOrder[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < levelOrder.size())
    {
        TreeNode* current = q.front();
        q.pop();

        if (levelOrder[i] != -1)
        {
            current->left = new TreeNode(levelOrder[i]);
            q.push(current->left);
        }
        i++;

        if (i < levelOrder.size() && levelOrder[i] != -1)
        {
            current->right = new TreeNode(levelOrder[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

// Helper function to calculate the diameter of the tree
int Diameter(TreeNode* root, int& diameter)
{
    if (!root) return 0;

    int leftHeight = Diameter(root->left, diameter);
    int rightHeight = Diameter(root->right, diameter);

    // Update the diameter at each node
    diameter = max(diameter, leftHeight + rightHeight + 1); // Include the current node

    // Return the height of the current node
    return max(leftHeight, rightHeight) + 1;
}

// Main function to calculate the diameter
int diameterOfBinaryTree(TreeNode* root)
{
    int diameter = 0;
    Diameter(root, diameter);
    return diameter;
}

int main()
{
    // Input
    string input;
    cout << "Enter level-order traversal of the binary tree (-1 for null nodes): ";

    getline(cin, input);
    stringstream ss(input);
    vector<int> levelOrder;
    int num;
    while (ss >> num)
    {
        levelOrder.push_back(num);
    }
    // Build the tree
    TreeNode* root = buildTree(levelOrder);

    // Calculate and print the diameter
    cout << "Diameter of the binary tree: " << diameterOfBinaryTree(root) << endl;
    return 0;
}
