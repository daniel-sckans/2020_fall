#ifndef CONTRIB_H
#define CONTRIB_H

// jon class 
typedef struct jon_class jon_class; 
jon_class* jon_ctor(); 
char* jon_get(); 
void jon_set(); 
void* jon_custom(); 
void jon_print(); 
void jon_dtor(); 

// nic class
typedef struct nic_class nic_class; 
nic_class* nic_ctor(); 
int nic_get(); 
void nic_set(); 
void* nic_custom(); 
void nic_print(); 
void nic_dtor(); 

// akito class
typedef struct akito_class akito_class; 
akito_class* akito_ctor(); 
int akito_get(); 
void akito_set(); 
void* akito_custom(); 
void akito_print(); 
void akito_dtor(); 

// santiago class
typedef struct santiago_class santiago_class; 
santiago_class* santiago_ctor(); 
santiago_class santiago_get(); 
void santiago_set(); 
void* santiago_custom(); 
void santiago_print(); 
void santiago_dtor(); 

// francis class
typedef struct francis_class francis_class; 
francis_class* francis_ctor(); 
int francis_get(); 
void francis_set(); 
void* francis_custom(); 
void francis_print(); 
void francis_dtor(); 

// trevor class
typedef struct trevor_class trevor_class; 
trevor_class* trevor_ctor(); 
int trevor_get(); 
void trevor_set(); 
void* trevor_custom(); 
void trevor_print(); 
void trevor_dtor(); 

// skyler class
typedef struct skyler_class skyler_class; 
skyler_class* skyler_ctor(); 
int skyler_get(); 
void skyler_set(); 
void* skyler_custom(); 
void skyler_print(); 
void skyler_dtor(); 

// ashley class
typedef struct ashley_class ashley_class; 
ashley_class* ashley_ctor(); 
int ashley_get(); 
void ashley_set(); 
void* ashley_custom(); 
void ashley_print(); 
void ashley_dtor(); 

#endif
