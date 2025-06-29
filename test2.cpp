#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

// Node structure for the FP-tree
struct FPNode {
    string item; // Item name
    int count;   // Support count
    unordered_map<string, FPNode*> children; // Child nodes
    FPNode* parent;  // Pointer to parent node

    FPNode(const string& itemName, FPNode* parentNode = nullptr)
        : item(itemName), count(1), parent(parentNode) {}
};

// FP-tree structure
class FPTree {
public:
    FPNode* root; // Root of the tree
    unordered_map<string, vector<FPNode*>> headerTable; // Header table for item links

    FPTree() {
        root = new FPNode("null"); // Initialize root node
    }

    // Add a transaction to the tree
    void addTransaction(const vector<string>& transaction) {
        FPNode* currentNode = root;
        for (const string& item : transaction) {
            if (currentNode->children.find(item) == currentNode->children.end()) {
                // Create a new child if the item is not present
                currentNode->children[item] = new FPNode(item, currentNode);
                headerTable[item].push_back(currentNode->children[item]);
            } else {
                // Increment the count of the existing node
                currentNode->children[item]->count++;
            }
            currentNode = currentNode->children[item];
        }
    }

    // Destructor to clean up nodes
    ~FPTree() {
        deleteTree(root);
    }

private:
    void deleteTree(FPNode* node) {
        for (auto& child : node->children) {
            deleteTree(child.second);
        }
        delete node;
    }
};

// Utility function: Get frequent items
unordered_map<string, int> getFrequentItems(const vector<vector<string>>& transactions, int minSupport) {
    unordered_map<string, int> freqMap;
    for (const auto& transaction : transactions) {
        for (const string& item : transaction) {
            freqMap[item]++;
        }
    }
    for (auto it = freqMap.begin(); it != freqMap.end();) {
        if (it->second < minSupport) {
            it = freqMap.erase(it);
        } else {
            ++it;
        }
    }
    return freqMap;
}

// Utility function: Sort transactions by descending frequency
vector<string> sortTransaction(const vector<string>& transaction, const unordered_map<string, int>& freqMap) {
    vector<string> sortedTransaction;
    for (const string& item : transaction) {
        if (freqMap.find(item) != freqMap.end()) {
            sortedTransaction.push_back(item);
        }
    }
    sort(sortedTransaction.begin(), sortedTransaction.end(),
         [&freqMap](const string& a, const string& b) {
             return freqMap.at(a) > freqMap.at(b);
         });
    return sortedTransaction;
}

// Utility function to print the FP-tree
void printFPTree(FPNode* node, int depth = 0) {
    if (!node) return;
    // Indentation based on depth
    for (int i = 0; i < depth; i++) cout << "  ";
    cout << node->item << " (" << node->count << ")" << endl;
    for (const auto& child : node->children) {
        printFPTree(child.second, depth + 1);
    }
}

// Recursive FP-growth function
void fpgrowth(FPTree* tree, vector<string> prefix, int minSupport, vector<pair<vector<string>, int>>& result) {
    // Extract keys from headerTable and sort them in reverse order
    vector<string> keys;
    for (const auto& pair : tree->headerTable) {
        keys.push_back(pair.first);
    }
    sort(keys.rbegin(), keys.rend());

    // Process each key
    for (const string& item : keys) {
        int support = 0;
        for (FPNode* node : tree->headerTable[item]) {
            support += node->count;
        }
        if (support >= minSupport) {
            vector<string> newPattern = prefix;
            newPattern.push_back(item);
            result.push_back(make_pair(newPattern, support));

            vector<vector<string>> conditionalPatternBase;
            for (FPNode* node : tree->headerTable[item]) {
                vector<string> path;
                FPNode* parent = node->parent;
                while (parent && parent->item != "null") {
                    path.push_back(parent->item);
                    parent = parent->parent;
                }
                for (int i = 0; i < node->count; i++) {
                    if (!path.empty()) {
                        conditionalPatternBase.push_back(path);
                    }
                }
            }

            unordered_map<string, int> conditionalFreqMap = getFrequentItems(conditionalPatternBase, minSupport);
            if (!conditionalFreqMap.empty()) {
                FPTree* conditionalTree = new FPTree();
                for (size_t i = 0; i < conditionalPatternBase.size(); ++i) {
                    auto sortedTransaction = sortTransaction(conditionalPatternBase[i], conditionalFreqMap);
                    if (!sortedTransaction.empty()) {
                        conditionalTree->addTransaction(sortedTransaction);
                    }
                }
                fpgrowth(conditionalTree, newPattern, minSupport, result);
                delete conditionalTree;
            }
        }
    }
}

int main() {
    // Example input: transactions and minimum support
    vector<vector<string>> transactions = {
        {"a", "b", "c", "d", "e"},
        {"a", "b", "c"},
        {"a", "b", "d"},
        {"a", "e"},
        {"b", "c", "e"}
    };
    int minSupport = 2;

    // Step 1: Calculate frequent items
    auto freqMap = getFrequentItems(transactions, minSupport);

    // Step 2: Sort and filter transactions
    vector<vector<string>> filteredTransactions;
    for (const auto& transaction : transactions) {
        auto sortedTransaction = sortTransaction(transaction, freqMap);
        if (!sortedTransaction.empty()) {
            filteredTransactions.push_back(sortedTransaction);
        }
    }

    // Step 3: Build FP-tree
    FPTree* tree = new FPTree();
    for (const auto& transaction : filteredTransactions) {
        tree->addTransaction(transaction);
    }

    // Print the FP-tree
    cout << "FP-Tree Structure:" << endl;
    printFPTree(tree->root);

    // Step 4: Mine patterns
    vector<pair<vector<string>, int>> frequentPatterns;
    fpgrowth(tree, {}, minSupport, frequentPatterns);

    // Output the results
    cout << "\nFrequent Patterns:" << endl;
    for (const auto& pattern : frequentPatterns) {
        for (const string& item : pattern.first) {
            cout << item << " ";
        }
        cout << ": " << pattern.second << endl;
    }

    delete tree;
    return 0;
}
