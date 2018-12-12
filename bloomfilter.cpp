#include "bloomfilter.h"

// return a hash range from 0 to 79999
int hash(const char* str, int index)
{
    int hash = 1;
    int seed = 12345;
    int curr;
    switch(index)
    {
    case 0:{
        while(curr = int(*str++))
        {
            hash = 128 * hash + curr;
        }
        return abs(hash%80000);
    }
    case 1:{
        while(curr = int(*str++))
        {
            hash = (25536 * hash + curr)%80000;
        }
        return abs(hash);
    }
    case 2:{
        while(curr = int(*str++))
        {
            hash = (seed * hash + curr)%80000;
            seed *= 123;
        }
        return abs(hash);
    }
    case 3:{
        while(curr = int(*str++))
        {
            hash += curr*curr;
        }
        return abs(hash%80000);
    }
    case 4:{
        while(curr = int(*str++))
        {
            hash += abs(curr*curr*curr);
        }
        return abs(hash%80000);
    }
    case 5:{
        while(curr = int(*str++))
        {
            hash *= (hash + curr*seed)%80000;
        }
        return abs(hash%80000);
    }
    case 6:{
        while(curr = int(*str++))
        {
            seed = 345;
            hash = (seed * hash + curr)%80000;
            seed *= 345;
        }
        return abs(hash);
    }
    }
    return -1;
}

void initBitMap(unsigned char* bitMap)
{
    for(int i = 0; i<10000;i++)
    {
        bitMap[i] = 0;
    }
}

bool isKeyExistInBitMap(unsigned char* bitMap, const char* str)
{
    for(int i = 0; i<7; i++)
    {
        int code = hash(str, i);
        if(!((bitMap[code/8] >> code%8) % 2))
        {
            return false;
        }
    }
    return true;
}

void appendKey2BitMap(unsigned char* bitMap, const char* str)
{
    if(isKeyExistInBitMap(bitMap, str))
    {
        return;
    }
    for(int i = 0; i<7; i++)
    {
        int code = hash(str, i);
        if(!((bitMap[code/8] >> code%8) % 2))
        {
            bitMap[code/8] += 1 << code%8;
        }
    }
}
