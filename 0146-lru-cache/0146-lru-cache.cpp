class LRUCache {
public:
     class Node {
         public: 
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int _key, int _value) {
            key = _key;
            value = _value;
        }
    };
    
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    
    int cap = 0;
    unordered_map<int, Node* > hashmap;
    
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    void addNode(Node* node) {
        Node* temp = head -> next;
        node -> next = temp;
        node -> prev = head;
        head -> next = node;
        temp -> prev = node;
    }
    
    void deleteNode(Node* node) {
        Node* delPrev = node -> prev;
        Node* delNext = node -> next;
        delPrev -> next = delNext;
        delNext -> prev = delPrev;
    }
    
    int get(int key) {
        if(hashmap.find(key) != hashmap.end()) {
            Node* requiredNode = hashmap[key];
            int valuee = requiredNode -> value;
            hashmap.erase(key);
            deleteNode(requiredNode);
            addNode(requiredNode);
            hashmap[key] = requiredNode;
            return valuee;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hashmap.find(key) != hashmap.end()) {
            Node* existingNode = hashmap[key];
            hashmap.erase(key);
            deleteNode(existingNode);
        }
        if(hashmap.size() == cap) {
            hashmap.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }
        Node* newNode = new Node(key, value);
        addNode(newNode);
        hashmap[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */