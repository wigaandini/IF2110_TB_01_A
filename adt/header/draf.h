/* Definisi ADT DRAF */
#include "wordmachine.h"
#include "datetime.h"
#include "boolean.h"
#include "stack.h"
#include <time.h>

#ifndef DRAF_H
#define DRAF_H

void LihatDraf(DrafStack S);

void AddDraf(DrafStack * S,Word word);

void EditDraf(DrafStack * S,Word word);

void DeleteDraf(DrafStack *S,Draf *Out);

#endif