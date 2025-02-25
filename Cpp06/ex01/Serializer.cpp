#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::~Serializer() {}
Serializer::Serializer(const Serializer &other) { (void)other; }
Serializer& Serializer::operator=(const Serializer &other) { (void)other; return *this; }

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t value;

    value = reinterpret_cast<uintptr_t> (ptr);

    return value;
}


Data* Serializer::deserialize(uintptr_t raw)
{
    Data* obj;

    obj = reinterpret_cast<Data*> (raw);

    return obj;
}


