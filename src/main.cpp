/**
 * @file main.cpp
 * @brief This is a linked list implemtation.
 * @details This code pays around with linked list  .
 * @author Addis Bogale
 * @date 2/15/2021
 * 
 */



#include <iostream>
using namespace std;

class DLNode {
public:
    int data; // data in the node
    DLNode* nextNode; // pointer to the next node
    DLNode* prevNode; // pointer to the next node

    DLNode(int d) {
        data = d;
        nextNode = NULL;
        prevNode = NULL;
    }
};

class DLL {
public:
    DLNode* head; // pointer to the first node in the list
    int n; // count of how many nodes are in the list

    DLL() {
        head = NULL;
        n = 0;
    }
   
    bool addHead(int d) {
        DLNode* newNode = new DLNode(d);
        if (n == 0) { // the list is empty
            head = newNode;
        }
        else {
            newNode->nextNode = head;
            head->prevNode = newNode;
            head = newNode;


        }
        n++;
        return(true);
    }
    
    bool addToTail(int d) {
        DLNode* newNode = new DLNode(d);
        if (n == 0) { // the list is empty
            head = newNode;
        }
        else {
            DLNode* value = head;
            while (value->nextNode != NULL) {
                value = value->nextNode;
            }
            newNode->prevNode = value;
            newNode->nextNode = NULL;
            value->nextNode = newNode;
        }
        n++;
        return(true);
    }
    
    bool removeTail(int d) {
        DLNode* var = head->nextNode;

        if (head->nextNode == NULL) {
            return(false);
        }
        while (var->nextNode->nextNode != NULL) {
            var = var->nextNode;
        }
        d = var->nextNode->data;
        delete var->nextNode;
        var->nextNode = NULL;

        n--;
        return(true);

    }
    
    int get(int ii) {
        DLNode* curNode;
        if (head == NULL) { // the list is empty
            return(-999999);
        }
        else if (ii >= n) {
            cout << "ERROR: Asked for node beyond tail" << endl;
            return(-999998);
        }
        else if (ii < 0) {
            cout << "ERROR: Asked for negative index" << endl;
            return(-999997);
        }
        else {
            curNode = head;
            // traverse list to desired node
            for (int jj = 0; jj < ii; jj++) {
                curNode = curNode->nextNode;
            }
            return(curNode->data);
        }
    }

    bool addMiddle(int ii, int d) {
        DLNode* curNode;
        DLNode* newNode = new DLNode(d);
        if (head == NULL) { // the list is empty
            return(false);
        }
        else if (ii >= n) {
            cout << "ERROR: Asked for node beyond tail" << endl;
            return(false);
        }
        else if (ii < 0) {
            cout << "ERROR: Asked for negative index" << endl;
            return(false);
        }
        else {
            curNode = head;
            // traverse list to desired node
            for (int jj = 0; jj < ii; jj++) {
                curNode = curNode->nextNode;
            }
            newNode->nextNode = curNode->nextNode;
            newNode->prevNode = curNode;
            curNode->nextNode = newNode;
            if(newNode->nextNode != NULL){
                newNode->nextNode->prevNode = newNode;
            }
            n++;
            return(true);
        }
    }

    bool removeHead(int& d) {
        int val;
        DLNode* old; // save off the old node
        if (head != NULL) {
            val = head->data; // collect the data from node to be removed
            old = head; // save off pointer to node we are removing
            head = head->nextNode;// update head to new node
            head->prevNode = NULL;
            delete old; // release the memory from the removed node
            n--; // decrement n to show shorter list
            d = val;
            return(true);
        }
        else { //list is empty
            return(false);
        }
    }

    void printList() {
        DLNode* curNode;
        if (head == NULL) { // the list is empty
            cout << "Empty list" << endl;
        }
        else { // the list is not empty
            curNode = head; // start at the beginning
            while (curNode->nextNode != NULL) {
                cout << curNode->data << " -> ";
                curNode = curNode->nextNode; // update to next node
            }
            cout << curNode->data;
            cout << endl;
        }
    }
};

int main(int, char**) {
    DLL myList;
    int retData; // for data from remove
    
    myList.printList();
    myList.addToTail(1);
    myList.printList();
    myList.addToTail(2);
    myList.printList();
    myList.addToTail(3);
    myList.printList();
    myList.addToTail(4);
    myList.printList();
    myList.addToTail(5);
    myList.printList();

    cout << "get(0) = " << myList.get(0) << endl;
    cout << "get(1) = " << myList.get(1) << endl;
    cout << "get(4) = " << myList.get(4) << endl;
    cout << "get(5) = " << myList.get(5) << endl;
    cout << "get(7) = " << myList.get(7) << endl;
    cout << "get(-3) = " << myList.get(-3) << endl;

    myList.addMiddle(3, 10);
    myList.printList();
    myList.addMiddle(3, 11);
    myList.printList();
    myList.addMiddle(6, 12);
    myList.printList();
    myList.addMiddle(0, 13);
    myList.printList();

    myList.printList();
    if (myList.addHead(retData))
        cout << "addedtohead " << retData << endl;
    else
        cout << "list was empty" << endl;
   
    if (myList.addToTail(retData))
        cout << "RemovedTail " << retData << endl;
    else
        cout << "list was empty" << endl;
   
    myList.printList();
    if (myList.removeHead(retData))
        cout << "Removed " << retData << endl;
    else
        cout << "list was empty" << endl;
    myList.printList();
    if (myList.removeTail(retData))
        cout << "Removed Tail " << retData << endl;

    myList.printList();
    if (myList.removeHead(retData))
        cout << "Removed " << retData << endl;
    else
        cout << "list was empty" << endl;
    myList.printList();
    if (myList.removeHead(retData))
        cout << "Removed " << retData << endl;
    else
        cout << "list was empty" << endl;
    myList.printList();
    if (myList.removeHead(retData))
        cout << "Removed " << retData << endl;
    else
        cout << "list was empty" << endl;
    myList.printList();
    if (myList.removeHead(retData))
        cout << "Removed " << retData << endl;
    else
        cout << "list was empty" << endl;
    myList.printList();
    if (myList.removeHead(retData))
        cout << "Removed " << retData << endl;
    else
        cout << "list was empty" << endl;
    myList.printList();
    if (myList.removeHead(retData))
        cout << "Removed " << retData << endl;
    else
        cout << "list was empty" << endl;
    myList.printList();
    if (myList.removeHead(retData))
        cout << "Removed " << retData << endl;
    else
        cout << "list was empty" << endl;
    myList.printList();
}
