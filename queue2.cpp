#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
    for (int i = 0; i < MAX; i++){
        Q.info[i] = 0;
    }
}

bool isEmptyQueue(Queue Q){
    return (Q.head == -1);
}

bool isFullQueue(Queue Q){
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)){
        cout << "Queue penuh!" << endl;
    } 
    else {
        if (isEmptyQueue(Q)){
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        cout << "Queue kosong!" << endl;
        return -999;
    }

    infotype x = Q.info[Q.head];

    // head bergerak maju
    Q.head++;

    // Jika sudah melewati tail, reset queue
    if (Q.head > Q.tail){
        Q.head = -1;
        Q.tail = -1;
    }

    return x;
}

void printInfo(Queue Q){
    cout << Q.head << " - " << Q.tail << "\t| ";

    if (isEmptyQueue(Q)){
        cout << "empty queue";
    } 
    else {
        for (int i = 0; i < MAX; i++){
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
