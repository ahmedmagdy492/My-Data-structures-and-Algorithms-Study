#include <iostream>

#include "LastKNumbersFromStream.h"

int main() {
	LastKNumbersFromStream lastK(4);

	std::cout << 1 << " -> " << lastK.next(1) << std::endl;
	std::cout << 2 << " -> " << lastK.next(2) << std::endl;
	std::cout << 3 << " -> " << lastK.next(3) << std::endl;
	std::cout << 4 << " -> " << lastK.next(4) << std::endl;
	std::cout << 5 << " -> " << lastK.next(5) << std::endl;
	std::cout << 6 << " -> " << lastK.next(6) << std::endl;
}