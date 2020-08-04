#pragma once
#include "refcounter.hpp"

template <typename T>
class SharedPtr {
public:
    explicit SharedPtr(T* ptr = nullptr) : data_(ptr), refCounter_(new RefCounter()){
        if(ptr){
            ++(*refCounter_);
        }
    }
    SharedPtr(const SharedPtr<T>& sharedPtr){
        data_ = sharedPtr.data_;
        refCounter_ = sharedPtr.refCounter_;
        ++(*refCounter_);
    }
    SharedPtr(SharedPtr<T>&& sharedPtr){
        data_ = sharedPtr.data_;
        refCounter_ = sharedPtr.refCounter_;

        sharedPtr.data_ = nullptr;
        sharedPtr.refCounter_ = new RefCounter();
    }

    ~SharedPtr(){
        if(data_){
             --(*refCounter_);
        }
        if(refCounter_->getCounter() == 0){
            delete refCounter_;
            delete data_;
            std::cout << "SHARED PTR DESTRUCTOR\n";
        }
    }

    T* get(){
        return data_;
    }
    unsigned int useCount(){
        return refCounter_->getCounter();
    }

    T& operator=(const SharedPtr<T>& sharedPtr){
        if(&sharedPtr != this){
            data_ = sharedPtr.data_;
            refCounter_ = sharedPtr.refCounter_;
            ++(*refCounter_);
        }
        return *this;
    }

    T& operator=(SharedPtr<T>&& sharedPtr){
        if(&sharedPtr != this){
            delete data_;
            delete refCounter_;

            data_ = sharedPtr.data_;
            refCounter_ = sharedPtr.refCounter_;

            sharedPtr.data_ = nullptr;
            sharedPtr.refCounter_ = new RefCounter();
        }
        return *this;
    }

    T* operator->(){
        return data_;
    }
    T& operator*(){
        return *data_;
    }

private:
    T* data_;
    RefCounter* refCounter_;
};
