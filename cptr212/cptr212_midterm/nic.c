#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "contrib.h"

typedef struct nic_class {
    char Full_Name;
    int id;
    int Age;
    char Email_address;
    char Job_description;

} nic_class;

nic_class* nic_ctor(){
    nic_class* ab = malloc(sizeof(nic_class));

    // Each of these is only a single character.  
    ab->Full_Name = '.'; 
    ab->id = 28;
    ab->Age = 21;
    ab->Email_address = '.'; 
    ab->Job_description = '.'; 

    return ab; 
}
int nic_get(nic_class* ab) {
    return ab->Age;

}

void nic_set(nic_class* ab){
   ab->Age = 21;
} 
void* nic_custom(nic_class* ab) {
    ab->Age *= 22;
    return NULL;

} 

void nic_print(nic_class* ab){
    printf("Full Name: %c", ab->Full_Name);
    printf("Job Description: %c",ab->Job_description);


}
void nic_dtor(nic_class* ab){
    free(ab); 
}
