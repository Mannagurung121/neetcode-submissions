class Node {
public:
    int key, val;
    Node* prev;
    Node* next;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
    }
};
class LRUCache {
public:
    unordered_map<int, Node*> mpp;
    int cap;
    Node* head = NULL;
    Node* tail = NULL;
    LRUCache(int capacity) {
        this->cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void getNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    void insert(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->next = temp;
        temp->prev = node;
        node->prev = head;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) {
            return -1;
        }
        Node* curr = mpp[key];
        getNode(curr);
        insert(curr);
        return curr->val;
    }

    void put(int key, int value) {

        if (mpp.find(key) != mpp.end()) {
            Node* temp = mpp[key];
            temp->val = value;
            getNode(temp);
            insert(temp);
        } else {

            if (mpp.size() == cap) {
                Node* node = tail->prev;
                mpp.erase(node->key);
                getNode(node);
                delete node;
                
            }
            Node* newNode = new Node(key, value);
             insert(newNode);
            mpp[key] = newNode;
           
        }
    }
};
