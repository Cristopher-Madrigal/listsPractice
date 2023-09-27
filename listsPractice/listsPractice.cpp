#include <iostream>

class Dog {
public:
    int age;
    std::string name;
    bool hasOwner;
    std::string breed;

    Dog(int _age, const std::string& _name, bool _hasOwner, const std::string& _breed) :
        age(_age), name(_name), hasOwner(_hasOwner), breed(_breed) {}
};

class Node {
public:
    Dog* data;
    Node* next;

    Node(Dog* _data) : data(_data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void printByOwner(bool hasOwner) {
        Node* current = head;
       
            while (current) {
                if (current->data->hasOwner == hasOwner) {
                std::cout << current->data->name << ", ";
                }
                current = current->next;
            }
       
            std::cout << std::endl;
       
    }

    void insert(Dog* newDog) {
        Node* newNode = new Node(newDog);

        if (!head) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

};

int main() {
    LinkedList dogList;
    dogList.insert(new Dog(3, "Buddy", true, "Golden Retriever"));
    dogList.insert(new Dog(2, "Max", false, "Labrador"));
    dogList.insert(new Dog(5, "Lucy", true, "Poodle"));

    std::cout << "Dogs with owner:" << std::endl;
    dogList.printByOwner(true);
    std::cout << "Dogs without owner:" << std::endl;
    dogList.printByOwner(false);

    return 0;
}