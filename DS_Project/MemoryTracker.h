#include <iostream>
#include <unordered_map>
#include <cstdlib>

class MemoryTracker {
public:
    // map to store the size of each allocated block of memory
    static std::unordered_map<void*, size_t> memoryMap;

    // total memory usage
    static size_t totalMemory;

    // overload operator new to track memory usage
    static void* operator new(size_t size) {
        // allocate memory using the default new operator
        void* ptr = ::operator new(size);

        // update the memory map and total memory usage
        memoryMap[ptr] = size;
        totalMemory += size;

        std::cout << "Allocated " << size << " bytes at address " << ptr << std::endl;
        std::cout << "Total memory usage: " << totalMemory << " bytes" << std::endl;

        return ptr;
    }

    // overload operator delete to track memory usage
    static void operator delete(void* ptr) {
        // update the total memory usage
        totalMemory -= memoryMap[ptr];
        memoryMap.erase(ptr);

        std::cout << "Deallocated " << memoryMap[ptr] << " bytes at address " << ptr << std::endl;
        std::cout << "Total memory usage: " << totalMemory << " bytes" << std::endl;

        // deallocate memory using the default delete operator
        ::operator delete(ptr);
    }
};

// define the static members of the MemoryTracker class
std::unordered_map<void*, size_t> MemoryTracker::memoryMap;
size_t MemoryTracker::totalMemory = 0;