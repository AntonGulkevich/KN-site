#include<iostream> 
#include<cstdlib> 
#include<thread> 
using namespace std; 
 
class printNumber { 
public: 
 
    void operator()(int number,int arr[],int idx) { 
        int sum = 0; 
        for(int i = 0; i < number; i++) { 
            if(1%15 == 0) continue; 
            if(i%3 == 0) sum += 3*i; 
            if(i%5 == 0) sum += 5*i; 
        } 
        arr[idx] = sum; 
    } 
}; 
 
int main() { 
    const int length = 10; 
    thread::id id; 
    thread thread_array[length]; 
    int res_arr[length] = {0}; 
    for (int i = 0; i < length; i++) { 
        thread_array[i] = thread(printNumber(), rand(),res_arr,i); 
    } 
    for (int i = 0; i < length; i++) { 
        if (thread_array[i].joinable()) { 
            id = thread_array[i].get_id(); 
            thread_array[i].join(); 
            cout << "Thread with id " << id << " finished. With result "<<res_arr[i]<<"\n"; 
        } 
    } 
    return 0; 
}