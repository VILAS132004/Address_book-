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
    
    int index = addressBook->contactCount;

    while(1)
    {
        printf("Enter name: ");
        scanf(" %[^\n]", addressBook->contacts[index].name);

        int len = strlen(addressBook->contacts[index].name);
        int isValid = 1;

        if(len < 2)
        {
            isValid = 0;
        }
        else
        {
            for(int i=0;i<len;i++)
            {
                if(!isalnum(addressBook->contacts[index].name[i]) && addressBook->contacts[index].name[i]!= ' ')
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

        printf("Invalid Name! Name must be at leat 2 characters long.\n");
    }

    printf("name accepted : %s\n\n",addressBook->contacts[index].name);
    
    while(1)
    {
        printf("Enter phone number: ");
        scanf("%s",addressBook->contacts[index].phone);

        while(getchar() != '\n');

        int len = strlen(addressBook->contacts[index].phone);
        int isValid = 1;

        if(len!=10)
        {
            printf("invalid phone number!must be exactly 10 digits.\n");
            continue;
        }
        if(addressBook->contacts[index].phone[0]< '6'||addressBook->contacts[index].phone[0]> '9')
        {
            printf("invalid phone number! first digit must be between 6 and 9\n");
            continue;
        }

        for(int i=0;i<len;i++)
        {
            if(!isdigit(addressBook->contacts[index].phone[i]))
            {
                isValid = 0;
                break;
            }

        }
            if(isValid==0)
            {
                printf("invalid phone number! must contain only digits\n");
                continue;
            }

            break;
    }
    
        printf("Phone number accepted: %s\n\n", addressBook->contacts[index].phone);

        addressBook->contactCount++;
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
