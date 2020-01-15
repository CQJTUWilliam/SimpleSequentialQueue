#include <iostream>
#include "SequentialQueue.h"

using namespace std;
int main() {
    SequentialQueue<int> queue;
    queue.enqueue(12);
    cout<<*queue.dequeue();
    cout<<*queue.dequeue();
    return 0;
}