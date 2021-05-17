#include <iostream>
#include <fstream>
#include <chrono>

void sort(int *arr, int size){
	for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return;
}

int main() {
        std::ofstream fout("Bubble.csv");
        for (int N = 1024; N < 43100; N += 1024) {
                std::cout << "N = " << N << std::endl;
                int* arr = new int[N];
                for (int i = 0; i < N; i++) {
                        arr[i] = i;
                }

                auto start = std::chrono::high_resolution_clock::now();
                sort(arr, N);
                auto end = std::chrono::high_resolution_clock::now();
                auto nsec = end - start;
                fout << N << "," << nsec.count() << std::endl;
                std::cout << "N = " << N << " done" << std::endl;
		delete[] arr;
        }
        fout.close();
        return 0;
}
