#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "contact.h"
// #include "file.h"
// #include "populate.h"

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the choosen criteria
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    if(addressBook->contactCount >=100)
    {
        printf("Error: Address Book is full!\n");
        return;
    }
    
    Contact newContact;

    while(1)
    {
        printf("Enter name: ");
        scanf(" %[^\n]", newContact.name);

        int len = strlen(newContact.name);
        int isValid = 1;

        if(len < 2)
        {
            isValid = 0;
        }
        else
        {
            for(int i=0;i<len;i++)
            {
                if(!isalnum(newContact.name[i]) && newContact.name[i]!= ' ')
                {
                    isValid=0;
                    break;
                }
            }
        }


        if(isValid)
        {
            break;  //name is valid
        }

        printf("Invalid Name!\n");
    }

    printf("name accepted : %s\n",newContact.name);
    
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
   
}
