#include <iostream>
#include <fstream>
#include <chrono>

void sort(int *arr, int size){
	for (int startIndex = 0; startIndex < size - 1; ++startIndex)
	{
		int smallestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex){
			if (arr[currentIndex] < arr[smallestIndex])
				smallestIndex = currentIndex;
		}
		std::swap(arr[startIndex], arr[smallestIndex]);
	}
	return;
}

int main() {
        std::ofstream fout("Choices.csv");
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
                fout << nsec.count() << std::endl;
                std::cout << "N = " << N << " done" << std::endl;
		delete[] arr;
        }
        fout.close();
        return 0;
}
