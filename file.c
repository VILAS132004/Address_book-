#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook)
{
    FILE *file = fopen("contacts.csv","w");
    if(file==NULL)
    {
        printf("Error: Unable to open file for saving\n");
        return;
    }

    fprintf(file,"# %d\n",addressBook->contactCount);

    for(int i=0;i<addressBook->contactCount;i++)
    {
        fprintf(file,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(file);
    printf("successfully contacts saved to 'contacts.csv\n\n");
}

void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *file=fopen("contacts.csv","r");
    if(file==NULL)
    {
        addressBook->contactCount=0;
        return;
    }
    if(fscanf(file,"# %d\n",&addressBook->contactCount)!=1)
    {
        addressBook->contactCount=0;
        fclose(file);
        return;
    }
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fscanf(file,"%49[^,],%19[^,],%49[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(file);
}
