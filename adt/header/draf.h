/* Definisi ADT DRAF */
#include "wordmachine.h"
#include "datetime.h"
#include "boolean.h"
#include "stack.h"
#include <time.h>

#ifndef DRAF_H
#define DRAF_H

void LihatDraf(Stack S);

void AddDraf(Stack * S,Word word);

void EditDraf(Stack * S,Word word);

void DeleteDraf(Stack *S,Draf *Out);

void PostDraf();

#endif