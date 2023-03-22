#include "list.h"
#include <cstdlib>
#include <iostream>
#include<cmath>
using namespace std;

class ArrayList : public List { // : means "is-a" / extend
    int* array;
    int index;
    int capacity;

public:
    // CONSTRUCTOR
    ArrayList() {
        capacity = 4;
        array = (int*) malloc(capacity);
        index = 0;
    }

    void add(int num) {
        *(array + index) = num;
        index++;
        if(index == capacity){
            capacity *= 1.5;
        }
    }

    void remove(int num){ // first num that we found
        // FIND the num
        for (int i = 0; i < index; i++) {
            if (num == *(array + i)) { // we have found the num
                for (int j = i; j < index - 1; j++) {
                    *(array + j) = *(array + j + 1);
                }
                index--;
                if(index < capacity*0.66){
                    capacity = floor(capacity-(capacity/3));
                }
            }
        }
        if(index == 0) {
            return;
        }
        return;
    }

    int get(int pos){
        return *(array + pos - 1);
    }

    int size(){
        return index;
    }

    void print() {
        cout << "[";
        for (int i = 0; i < capacity; i++) {
            if (i < index) {
                cout << *(array + i);
            } else {
                cout << "?";
            }

            if (i != capacity - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    void addAt(int num, int pos) {
        if(pos < index+1 && pos > 0) {
            int p = pos-1;
            for(int i = index-1; i >= p; i--) {
                array[i+1] = array[i];
            }
            if(index > capacity){
                capacity *= 1.5;
            }
            array[p]=num;
            index++;
            return;
        }
        cout << "Positon value invalid";
        return;
    }

    void removeAt(int pos) {
        if(pos < index+1 && pos > 0) {
            int p = pos-1;
            for(int i = 0; i < index; i++) {
                if(p == i) {
                    for(int j = p+1; j < index; j++){
                        array[j-1] = array[j];
                    }
                }
            }
            index--;
            if(index < capacity*0.66){
                capacity = floor(capacity-(capacity/3));
            }
        }
        else{
            cout << "Position value invalid";
        }
        return;
    }

    void bubbleSort(){
        for(int i = 0; i < index; i++){
            for(int j = 0; j < index-i-1; j++){
                if (array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                    print();
                }
            }
        }
    }

    void insertionSort(){
        for(int i = 1; i < index; i++){
            for(int j = i; j > 0 && array[j-1] > array[j]; j--){
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
                print();
            }
        }
    }
    void removeAll(int num) {
        for(int i = 0; i <= index; i++){
            if(array[i] == num){
                for(int j=i; j<index; j++){
                    array[j] = array[j+1];
                }
                index--;
                i--;
                if(index < capacity*0.66){
                    capacity = floor(capacity-(capacity/3));
                }
                continue;
            }
        }
        return;
    }
};