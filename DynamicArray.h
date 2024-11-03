#include <iostream>
#include <stdexcept>

using namespace std;

template<class T>
class DynamicArray
{
private:
    T* arr;
    size_t size;
    size_t capacity;

    // Helper function 
    void resize(size_t newCapacity) {
        if (newCapacity < 2) {
            newCapacity = 2;  
        }
        T* newArr = new T[newCapacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    DynamicArray(int cap = 2) : size(0), capacity(cap) {
        arr = new T[capacity];
    }

    // Copy constructor
    DynamicArray(const DynamicArray<T>& other) : size(other.size), capacity(other.capacity) {
        arr = new T[capacity];
        for (size_t i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    DynamicArray& operator=(const DynamicArray<T>& other) {
        if (this != &other) { 
            delete[] arr; 
            size = other.size;
            capacity = other.capacity;
            arr = new T[capacity];
            for (size_t i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }


    ~DynamicArray() {
        delete[] arr;
    }
    int search( T element) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                return i;
            }
        }
        return -1;  
    }


    // Append 
    void append(const T& element) {
        if (size >= capacity) {
            resize(capacity * 2);
        }
        arr[size++] = element; 
    }


    void Delete(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];  
        }
        size--;
        
        //shrink
        if (size < capacity / 4 && capacity > 2) {
            resize(capacity / 2);
        }
    }

    // Get the size of the array

    size_t getSize() const {
        return size;
    }

    // Get element 

    T get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }


    // Overload the subscript operator for const objects
     T& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }

     //Reverse

     void reverse() {
         int left = 0;
         int right = size - 1;
         while (left < right) {
             T temp = arr[left];
             arr[left] = arr[right];
             arr[right] = temp;
             left++;
             right--;
         }
     }


    // Print the array elements

    void display() const {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
