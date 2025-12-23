#ifndef __LISTE_H__ 
#define __LISTE_H__

#include <stdlib.h> 
#include <stdio.h>
#include "regle.h"

typedef struct elemBC {
	 regle *connaisance;
	 struct elemBC *next;
} elementBC;

typedef elementBC * BaseConnaisance;
//fonction1
//fonction2
//fonction3
//...


#endif 
