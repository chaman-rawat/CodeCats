// Odd Even Linked List
#include <bits/stdc++.h>

#include <iostream>

using namespace std;

class Node {
   public:
    int data = 0;
    Node *next = nullptr;

    Node(int data) {
        this->data = data;
    }
};

class linkedlist {
   public:
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;

    // basic->============================================

    int size_() {
        return this->size;
    }

    bool isEmpty() {
        return this->size == 0;
    }

    string toString() {
        Node *curr = this->head;
        string sb = "";

        while (curr != nullptr) {
            sb += to_string(curr->data);
            if (curr->next != nullptr)
                sb += " ";
            curr = curr->next;
        }
        return sb;
    }

    // add->===============================================
   private:
    void addFirstNode(Node *node) {
        if (this->head == nullptr) {
            this->head = node;
            this->tail = node;
        } else {
            node->next = this->head;
            this->head = node;
        }

        this->size++;
    }

   public:
    void addFirst(int val) {
        Node *node = new Node(val);
        addFirstNode(node);
    }

   public:
    void addLastNode(Node *node) {
        if (this->head == nullptr) {
            this->head = node;
            this->tail = node;
        } else {
            this->tail->next = node;
            this->tail = node;
        }

        this->size++;
    }

    void addLast(int val) {
        Node *node = new Node(val);
        addLastNode(node);
    }

    void addNodeAt(Node *node, int idx) {
        if (idx == 0)
            addFirstNode(node);
        else if (idx == this->size)
            addLastNode(node);
        else {
            Node *prev = getNodeAt(idx - 1);
            Node *curr = prev->next;

            prev->next = node;
            curr->next = node;

            this->size++;
        }
    }

    void addAt(int data, int idx) {
        if (idx < 0 || idx > this->size) {
            throw("invalidLocation: " + to_string(idx));
        }

        Node *node = new Node(data);
        addNodeAt(node, idx);
    }

    // remove->============================================
    Node *removeFirstNode() {
        Node *node = this->head;
        if (this->size == 1) {
            this->head = nullptr;
            this->tail = nullptr;
        } else {
            this->head = this->head->next;
            node->next = nullptr;
        }

        this->size--;
        return node;
    }

    void removeFirst() {
        if (this->size == 0) {
            throw("nullptrPointerException: -1");
        }

        Node *node = removeFirstNode();
        int rv = node->data;
        delete node;
    }

    Node *removeLastNode() {
        Node *node = this->tail;
        if (this->size == 1) {
            this->head = nullptr;
            this->tail = nullptr;
        } else {
            Node *prev = getNodeAt(this->size - 2);
            this->tail = prev;
            prev->next = nullptr;
        }

        this->size--;
        return node;
    }

    int removeLast(int val) {
        if (this->size == 0) {
            throw("nullptrPointerException: -1");
        }

        Node *node = new Node(val);
        int rv = node->data;
        delete node;
        return rv;
    }

    Node *removeNodeAt(int idx) {
        if (idx == 0)
            return removeFirstNode();
        else if (idx == this->size - 1)
            return removeLastNode();
        else {
            Node *prev = getNodeAt(idx - 1);
            Node *curr = prev->next;

            prev->next = curr->next;
            curr->next = nullptr;

            this->size--;
            return curr;
        }
    }

    int removeAt(int idx) {
        if (idx < 0 || idx >= this->size) {
            throw("invalidLocation: " + idx);
        }

        Node *node = removeNodeAt(idx);
        int rv = node->data;
        delete node;
        return rv;
    }

    // get->================================================
    Node *getFirstNode() {
        return this->head;
    }

    int getFirst() {
        if (this->size == 0) {
            throw("nullptrPointerException: -1");
        }

        Node *node = getFirstNode();
        return node->data;
    }

    Node *getLastNode() {
        return this->tail;
    }

    int getLast() {
        if (this->size == 0) {
            throw("nullptrPointerException");
        }

        Node *node = getLastNode();
        return node->data;
    }

    Node *getNodeAt(int idx) {
        Node *curr = this->head;

        while (idx-- > 0) {
            curr = curr->next;
        }

        return curr;
    }

    int getAt(int idx) {
        if (idx < 0 || idx >= this->size) {
            throw("invalidLocation: " + idx);
        }

        Node *node = getNodeAt(idx);
        return node->data;
    }

   public:
    void oddEven() {
        Node *temp = head;
        Node *odd, *even, *join;
        odd = even = join = NULL;

        while (temp) {
            if (temp->data & 1) {
                // ODD values
                if (odd) {
                    odd->next = temp;
                    odd = odd->next;
                } else {
                    head = odd = temp;
                }
            } else {
                // Even value
                if (even) {
                    even->next = temp;
                    even = even->next;
                } else {
                    even = temp;
                    join = even;
                }
            }

            temp = temp->next;
        }
        odd->next = join;
        even->next = NULL;
        tail = even;
    }
};

linkedlist makeList() {
    linkedlist l;
    int n1;
    cin >> n1;

    for (int i = 0; i < n1; i++) {
        int val;
        cin >> val;
        l.addLast(val);
    }
    return l;
}

int main() {
    linkedlist l = makeList();
    int a;
    cin >> a;
    int b;
    cin >> b;

    cout << l.toString() << endl;
    l.oddEven();
    cout << l.toString() << endl;
    l.addLast(b);
    l.addFirst(a);
    cout << l.toString() << endl;

    return 0;
}