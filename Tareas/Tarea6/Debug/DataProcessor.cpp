#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class DataProcessor {
public:
  DataProcessor(int size)
      : size(size), data(size > 0 ? new int[size] : nullptr) {
    if (size <= 0) {
      std::cout << "Error: invalid size\n";
    }
  }

  ~DataProcessor() { delete[] data; }

  void populateData() {
    for (int i = 0; i < size; ++i) {
      data[i] = i * 10;
    }
  }

  int calculateSum() {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
      sum += data[i];
    }
    return sum;
  }

  double calculateAverage() {
    return size > 0 ? static_cast<double>(calculateSum()) / size : 0.0;
  }

  void concurrentProcess() {
    std::thread t1(&DataProcessor::processData, this);
    std::thread t2(&DataProcessor::processData, this);

    t1.join();
    t2.join();
  }

  void printData() {
    for (int i = 0; i < size; i++) {
      std::cout << "Data[" << i << "] = " << data[i] << std::endl;
    }
  }

private:
  int *data;
  int size;
  std::mutex mtx;

  void processData() {
    for (int i = 0; i < size; ++i) {
      std::lock_guard<std::mutex> lock(mtx);
      data[i] *= 2;
    }
  }
};

int main() {
  int size;
  std::cout << "Enter size of data: ";
  std::cin >> size;

  if (size <= 0) {
    std::cout << "Error: invalid size\n";
    return 1;
  }

  DataProcessor processor(size);

  processor.populateData();
  processor.concurrentProcess();
  processor.printData();
  std::cout << "Average: " << processor.calculateAverage() << std::endl;

  return 0;
}