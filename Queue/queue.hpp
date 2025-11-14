#include <iostream>
#include <string>
#ifndef queue_hpp
#define queue_hpp

using namespace std;

class Patient{
    public:
        string patientName;
        int patientID;
        string reason;
        int priority; // 0 = normal, 1 = urgent
        Patient *next;

        Patient(string name, int id, string r, int pri = 0){
            patientName = name;
            patientID = id;
            reason = r;
            priority = pri;
            next = nullptr;
        }
};

class HospitalQueue{
    private:
        Patient *head;
        Patient *tail;
        int length;
        int nextPatientID;
    public:
        HospitalQueue(){
            head = tail = nullptr;
            length = 0;
            nextPatientID = 1;
        }

        ~HospitalQueue(){
            clearQueue();
        }
        
        void enqueue(string name, string reason, int priority){
            int id = nextPatientID++;
            Patient *new_patient = new Patient {name, id, reason, priority};

            if (priority == 1){
                new_patient->next =head;
                head = new_patient;
                if (tail == nullptr) tail = head;
            } else {
                if (!tail){
                    head = tail = new_patient;
                } else {
                    tail->next = new_patient;
                    tail = new_patient;
                }
            }
            length++;
        }

        Patient *dequeue(){
            if (!head){
                cout << "No patient" << endl;
                return nullptr;
            }
            Patient *served = head;
            head = head->next;
            if (!head) tail = nullptr; //check if queue become empty
            served->next = nullptr;
            length--;
            return served;
        }

        Patient *peek(){
            return head;
        }

        bool isEmpty(){
            return length == 0;
        }

        int getLength(){
            return length;
        }

        void clearQueue(){
            while (head){
                Patient *temp = head;
                head = head->next;
                delete temp;
            }
            tail = nullptr;
            length = 0;
        }
};

#endif