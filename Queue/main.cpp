#include "queue.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    HospitalQueue queue;

    // Add patients (normal and urgent)
    queue.enqueue("Panha", "Flu symptoms", 0);
    queue.enqueue("Bot", "Broken arm", 1);      // Urgent
    queue.enqueue("Rith", "Headache", 0);

    cout << "Patients in queue: " << queue.getLength() << endl;

    // Serve (dequeue) the next patient
    Patient* served = queue.dequeue();
    if (served) {
        cout << "Serving patient: " << served->patientName << " (ID: " << served->patientID << ")" << endl;
        delete served;
    }

    // Peek at next patient
    Patient* next = queue.peek();
    if (next) {
        cout << "Next patient: " << next->patientName << endl;
    }

    // Clear queue and check empty
    queue.clearQueue();
    cout << "Queue is empty: " << (queue.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}