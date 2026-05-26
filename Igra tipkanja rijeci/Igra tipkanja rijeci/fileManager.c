#include <stdio.h>
#include "fileManager.h"

long getFileSize(FILE* fp)
{
    if (fp == NULL)
        return -1;

    fseek(fp, 0, SEEK_END);

    long size = ftell(fp);

    rewind(fp);

    return size;
}