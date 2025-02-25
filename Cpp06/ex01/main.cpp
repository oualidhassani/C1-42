#include "Serializer.hpp"

int main(int ac, char **av)
{
    (void)av;
    if(ac == 1)
    {
        try
        {
            Data ptr;
            ptr.id = 42;

            uintptr_t serializedData = Serializer::serialize(&ptr);

            Data* deserializedData = Serializer::deserialize(serializedData);

            if (deserializedData != &ptr)
            {
                throw std::runtime_error("Deserialized pointer does not match the original pointer");
            }

            std::cout << "Serialization and deserialization successful!" << std::endl;
            std::cout << "Original Data ID: " << ptr.id << std::endl;
            std::cout << "Deserialized Data ID: " << deserializedData->id << std::endl;
            return 0;
        }        
        
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            return -1;
        }
    }
}