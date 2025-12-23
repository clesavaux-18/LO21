#ifndef __LISTE_H__ 
#define __LISTE_H__

#include <stdlib.h> 
#include <stdio.h>
#include "regle.h"

typedef struct elemBC {
	 regle *connaissance;
	 struct elemBC *next;
} elementBC;

typedef elementBC * BaseConnaissance;
//fonction1
//fonction2
//fonction3
//...


#endif 
