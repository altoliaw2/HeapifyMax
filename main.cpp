#include <iostream>
#include <utility>

class Heap{
    public: void fn_MaxHeapify(int* ip_Arr, int i_Size,
                                int i_Ind){
        int i_Par = i_Ind;
        int i_L = 2 * i_Ind + 1;
        int i_R = 2 * i_Ind + 2;

        if (i_L < i_Size && ip_Arr[i_L] > ip_Arr[i_Par])
            i_Par = i_L;

        if (i_R < i_Size && ip_Arr[i_R] > ip_Arr[i_Par])
            i_Par = i_R;

        if (i_Par != i_Ind) {
            std::swap(ip_Arr[i_Ind], ip_Arr[i_Par]);
            fn_MaxHeapify(ip_Arr, i_Size, i_Par);
        }
    }

    public: void fn_HeapSort(int* ip_Arr, int i_Size){
        for (int i_Ct = i_Size / 2 - 1;
                i_Ct >= 0; i_Ct--){

            fn_MaxHeapify(ip_Arr, i_Size, i_Ct);
        }
    }
    public: void fn_GetResult(int* ip_Arr, int i_Size){
        for (int i_Ct = 0; i_Ct < i_Size; i_Ct++){
            std::cout << ip_Arr[i_Ct] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    int ia_Arr[] = { 12, 11, 13, 5, 6, 7 };
	int i_Size = sizeof(ia_Arr) / sizeof(int);
    Heap o_Heap;
    o_Heap.fn_HeapSort(ia_Arr, i_Size);


	std::cout << "Sorted array is \n";
	o_Heap.fn_GetResult(ia_Arr, i_Size);
}
