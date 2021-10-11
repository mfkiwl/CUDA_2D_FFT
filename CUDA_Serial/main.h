#include <tuple>
#include <iostream>
#include <stdio.h>

using namespace std;

template <typename T>
class system_2D{

    private:
        T* data;
        int j_len,i_len;

    public:
        system_2D(int w, int h):
            data(new T[w*h]), j_len(w), i_len(h) {}

        ~system_2D(){
            delete[] data;
        }

        T& operator()(int i, int j){
            return data[i_len*j+i];
        }

        tuple<int,int> get_dimensions() {
            return tuple<int,int>{j_len,i_len};
        }

        void print(){
            int i,j;
            for (auto i = 0; i < i_len; i++) {
                for (auto j = 0; j < j_len; j++) {
                    cout << (*this)(i,j) << " ";
                }        
                cout << "\n"; 
            }   
        }
};


//Function definitions
void forward_fft(system_2D<double>& system);
