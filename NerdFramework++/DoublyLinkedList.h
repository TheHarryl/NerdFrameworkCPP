#pragma once

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
    public:
        T data;
        Node* previous;
        Node* next;

        Node(T data, Node* previous, Node* next) {
            this->data = data;
            this->previous = previous;
            this->next = next;
        }
        ~Node() = default;
    };

    class Iterator {
    public:
        Node* node;

        Iterator(Node* node) {
            this->node = node;
        }
        ~Iterator() = default;

        T operator*() const {
            // Returns value of data at current node
            return this->node->data;
        }
        Iterator& operator++() {
            // Does nothing if no forward node exists
            if (this->node == nullptr) return *this;

            // Move node forwards
            this->node = this->node->next;
            return *this;
        }
        Iterator& operator--() {
            // Does nothing if no previousward node exists
            if (this->node == nullptr) return *this;

            // Move node previouswards
            this->node = this->node->previous;
            return *this;
        }
        bool operator==(Iterator const& rhs) const {
            // Iterators are equivalent if nodes point to same memory
            return this->node == rhs.node;
        }
        bool operator!=(Iterator const& rhs) const {
            // Iterators are equivalent if nodes point to same memory
            return this->node != rhs.node;
        }
    };

    Node* first;
    Node* last;

    void unlinkNode(Node* node) {
        // If node is first node, reassign
        if (node == this->first)
            this->first = node->next;
        // If node is last node, reassign
        if (node == this->last)
            this->last = node->previous;

        // If node has neighbors, relink them
        if (node->previous != nullptr)
            node->previous->next = node->next;
        if (node->next != nullptr)
            node->next->previous = node->previous;

        // Delete node
        delete node;
    }
public:

    LinkedList() {
        this->first = nullptr;
        this->last = nullptr;
    }
    ~LinkedList() {
        this->clear();
    }

    // Returns iterator pointing to first node
    Iterator begin() const {
        return Iterator(this->first);
    }
    // Returns iterator pointing to last node
    Iterator tail() const {
        return Iterator(this->last);
    }
    // Returns iterator pointing after last node
    Iterator end() const {
        return ++tail();
    }
    // Returns data at first node
    T getFront() const {
        return this->first->data;
    }
    // Returns data at last node
    T getBack() const {
        return this->last->data;
    }
    bool isEmpty() const {
        // List is empty if the first node doesn't exist
        return this->first == nullptr;
    }
    bool contains(T element) const {
        // Iterates through the list; returns true if any node matches element
        for (Iterator i = this->begin(); i != this->end(); ++i) {
            if (*i == element)
                return true;
        }
        // Otherwise, return false
        return false;
    }
    void enqueue(T element) {
        // Create new node and links it
        Node* newNode = new Node(element, this->last, nullptr);

        if (!this->isEmpty()) // If list isn't empty, link the node
            this->last->next = newNode;
        else // If it is empty, this node is the first node too
            this->first = newNode;

        // This node is now the last node
        this->last = newNode;
    }
    void dequeue() {
        // If list is empty already, do nothing
        if (this->isEmpty()) return;

        // Unlink first node
        unlinkNode(this->first);
    }
    void pop() {
        // If list is empty already, do nothing
        if (this->isEmpty()) return;

        // Unlink last node
        unlinkNode(this->last);
    }
    void clear() {
        // Iterate through all nodes in list
        for (Iterator i = this->begin(); i != this->end(); ++i) {
            // Unlink and destroy node
            unlinkNode(i.node);
        }
    }
    void remove(T element) {
        // Iterate through all nodes in list
        for (Iterator i = this->begin(); i != this->end(); ++i) {

            // If node matches element, unlink and destroy node
            if (*i == element) {
                unlinkNode(i.node);
                return;
            }
        }
    }

    T& operator[](size_t i) const {
        Iterator i = this->begin();
        for (size_t n; n < i; n++)
            ++i;
        return *i;
    }
};

