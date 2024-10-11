// Time Complexity : O(N*32) + O(N*32);

struct Node {

    Node* Links[2];

    bool containsKey(int bit) { 
        return (Links[bit] != NULL);
    }
    Node* get(int bit) { 
        return Links[bit]; 
    }
    void put(int bit, Node* node) { 
        Links[bit] = node; 
    }
};

class Trie {

    Node* root;

    public:
    Trie() { 
        root = new Node(); 
    }

    // ------------------------------------------

    void insert(int num) {

        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    // -----------------------------------------------

    int getMax(int num) {
        Node* node = root;
        int numMax = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                numMax = numMax | (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return numMax;
    }
};

// -----------------------------------------------

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        Trie T;
        for (auto it : nums) {
            T.insert(it);
        }
        int maxxi = 0;
        for (auto& it : nums) {
            maxxi = max(maxxi, T.getMax(it));
        }
        return maxxi;
    }
};