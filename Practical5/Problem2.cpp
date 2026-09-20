#include <iostream>
using namespace std;

class SNode {
public:
    int data;
    SNode* next;

    SNode(int value) {
        data = value;
        next = NULL;
    }
};

class SinglyCircular {
public:
    SNode* head = NULL;

    void insertBeginning(int value) {
        SNode* newNode = new SNode(value);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        SNode* temp = head;

        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertEnd(int value) {
        SNode* newNode = new SNode(value);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        SNode* temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    void insertAfter(int x, int value) {
        if (head == NULL) {
            cout << "Circle is empty\n";
            return;
        }

        SNode* temp = head;

        do {
            if (temp->data == x) {
                SNode* newNode = new SNode(value);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }

            temp = temp->next;
        } while (temp != head);

        cout << "Student not found\n";
    }

    void removeStudent(int value) {
        if (head == NULL) {
            cout << "Circle is empty\n";
            return;
        }

        if (head->next == head) {
            if (head->data == value) {
                delete head;
                head = NULL;
            }
            return;
        }

        if (head->data == value) {
            SNode* temp = head;

            while (temp->next != head)
                temp = temp->next;

            SNode* del = head;
            head = head->next;
            temp->next = head;
            delete del;
            return;
        }

        SNode* prev = head;
        SNode* temp = head->next;

        while (temp != head) {
            if (temp->data == value) {
                prev->next = temp->next;
                delete temp;
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        cout << "Student not found\n";
    }

    void display() {
        if (head == NULL) {
            cout << "Empty\n";
            return;
        }

        SNode* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;

    DNode(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class DoublyCircular {
public:
    DNode* head = NULL;

    void insertBeginning(int value) {
        DNode* newNode = new DNode(value);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }

        DNode* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;

        head = newNode;
    }

    void insertEnd(int value) {
        DNode* newNode = new DNode(value);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }

        DNode* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
    }

    void insertAfter(int x, int value) {
        if (head == NULL) {
            cout << "Circle is empty\n";
            return;
        }

        DNode* temp = head;

        do {
            if (temp->data == x) {
                DNode* newNode = new DNode(value);

                newNode->next = temp->next;
                newNode->prev = temp;

                temp->next->prev = newNode;
                temp->next = newNode;

                return;
            }

            temp = temp->next;
        } while (temp != head);

        cout << "Student not found\n";
    }

    void removeStudent(int value) {
        if (head == NULL) {
            cout << "Circle is empty\n";
            return;
        }

        DNode* temp = head;

        do {
            if (temp->data == value) {

                if (temp->next == temp) {
                    delete temp;
                    head = NULL;
                    return;
                }

                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if (temp == head)
                    head = temp->next;

                delete temp;
                return;
            }

            temp = temp->next;
        } while (temp != head);

        cout << "Student not found\n";
    }

    void display() {
        if (head == NULL) {
            cout << "Empty\n";
            return;
        }

        DNode* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

int main() {
    SinglyCircular s;
    DoublyCircular d;

    int choice, value, after;

    while (true) {
        cout << "\n1. Join Beginning\n";
        cout << "2. Join End\n";
        cout << "3. Join After\n";
        cout << "4. Leave\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cin >> value;

            s.insertBeginning(value);
            d.insertBeginning(value);

            s.display();
            d.display();
        }

        else if (choice == 2) {
            cin >> value;

            s.insertEnd(value);
            d.insertEnd(value);

            s.display();
            d.display();
        }

        else if (choice == 3) {
            cin >> after >> value;

            s.insertAfter(after, value);
            d.insertAfter(after, value);

            s.display();
            d.display();
        }

        else if (choice == 4) {
            cin >> value;

            s.removeStudent(value);
            d.removeStudent(value);

            s.display();
            d.display();
        }

        else if (choice == 5) {
            s.display();
            d.display();
        }

        else if (choice == 6) {
            break;
        }

        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}