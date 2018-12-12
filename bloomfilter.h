#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <stdio.h>
#include <math.h>

int hash(const char* str, int index);
void initBitMap(unsigned char* bitMap);
bool isKeyExistInBitMap(unsigned char* bitMap, const char* str);
void appendKey2BitMap(unsigned char* bitMap, const char* str);

#endif // BLOOMFILTER_H
