// Is Linked List A Palindrome?
#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int data;
    node *next;
};

class linked_list {
   public:
    node *head, *tail;
    int size = 0;

   public:
    linked_list() {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n) {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if (head == NULL) {
            head = tmp;
            tail = tmp;
        } else {
            tail->next = tmp;
            tail = tail->next;
        }
        size++;
    }
    void display() {
        for (node *tmp = head; tmp != NULL; tmp = tmp->next) {
            cout << tmp->data << " ";
        }
    }

    int isPalindrome() {
        vector<int> values;
        node *temp = head;
        while (temp) {
            values.push_back(temp->data);
            temp = temp->next;
        }

        for (int i = 0, j = values.size() - 1; i < j; i++, j--)
            if (values[i] != values[j])
                return false;
        return true;
    }
};

int main() {
    int b;
    cin >> b;
    linked_list a;
    vector<int> arr(b, 0);
    for (int i = 0; i < b; i++) {
        cin >> arr[i];
        a.add_node(arr[i]);
    }

    int res = a.isPalindrome();
    if (res == 1) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}