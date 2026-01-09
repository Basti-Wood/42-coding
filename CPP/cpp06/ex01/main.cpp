#include "Serializer.hpp"



int main()
{
	Data *Data1 = new Data;
	Data *Data2 = new Data("this is important data UwU");
	uintptr_t rawData1 = 0;
	uintptr_t rawData2 = 0;

	std::cout << "Data1: " << *Data1 << std::endl;
	std::cout << "Data2: " << *Data2 << std::endl;

	rawData1 = Serializer::serialize(Data1);
	rawData2 = Serializer::serialize(Data2);

	std::cout << "RawData1: " << rawData1 << std::endl;
	std::cout << "RawData2: " << rawData2 << std::endl;

	Data *Data3 = Serializer::deserialize(rawData1);
	Data *Data4 = Serializer::deserialize(rawData2);

	std::cout << "Data3: " << *Data3 << std::endl;
	std::cout << "Data4: " << *Data4 << std::endl;
	
	delete(Data1);
	delete(Data2);
	return 0;
}