#ifndef SINGLETON_H
#define SINGLETON_H

#include <QtCore>
#include "GMacros.h"

template <class Type>
class Singleton
{
public:
    static Type &instance();
    Singleton(Type *instancePtr) {
        if(instancePtr_ == nullptr) {
            instancePtr_ = static_cast<Type*>(instancePtr);
        }
    }
private:
    static Type *instancePtr_;
    DISABLE_COPY(Singleton);
};

////////////////////Template implementations///////////////////
template<class Type>
Type* Singleton<Type>::instancePtr_ = G_NULLPTR;

template<class Type>
Type &Singleton<Type>::instance(){
    return *instancePtr_;
}

#endif // SINGLETON_H
