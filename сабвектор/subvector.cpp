#include <stdlib.h>
using namespace std;

struct subvector{
    int *mas;
    unsigned int top;
    unsigned int capacity;
};
bool init(subvector *qv){

    qv->mas = nullptr;
    qv->top = 0;
    qv->capacity = 0;

};
bool resize(subvector* qv, unsigned int new_capacity) {

    if (new_capacity < qv->capacity){
        return false;
    }
    int *p = new int[new_capacity];
    if (qv->mas != nullptr) {
        for (int i=0; i < qv->top; i++){
            p[i] = *(qv->mas+i);
        }
        delete[] qv->mas;}
    qv->mas = p;
    qv->capacity = new_capacity;
    return true;

};

bool push_back(subvector *qv, int d){

    qv->top += 1;
     if (qv->capacity == 0){
        resize(qv, 1);
    }
    if (qv->top >=  qv->capacity){
        resize(qv, qv->capacity*2);
    }
    *(qv->mas + qv->top - 1) = d;
    return true;

};
//можно было сделать reallock, но я нагуглила ее только после написания функции, так что вот
//добавление элемента в конец недовектора
//с выделением дополнительной памяти при необходимости

int pop_back(subvector* qv){

    if (qv->top == 0) return 0;
    qv->top -= 1;
    int ret = qv->mas[qv->top];
    return ret;

};//удаление элемента с конца недовектора


void shrink_to_fit(subvector *qv){

    qv->mas = (int*) realloc (qv->mas, qv->top*sizeof(int));
    qv->capacity = qv->top;

}; //очистить неиспользуемую память

void clear(subvector *qv){
    int* p = new int[qv->capacity];
    if (qv->mas != NULL) {
        delete[] qv->mas;
    };
    qv->mas = p;
    qv->top = 0;
};
//очистить содержимое недовектора, занимаемое место
//при этом не меняется

void destructor(subvector *qv){

    if (qv->mas != NULL) {delete[]qv->mas;}
    qv->top = 0;
    qv->capacity = 0;

};
//очистить всю используемую память, инициализировать
//недовекторкак пустой

bool init_from_file(subvector *qv, char *filename); //инициализировать недовекториз файла
