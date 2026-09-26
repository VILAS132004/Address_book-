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


        while(1)
        {
            printf("Enter email: ");
            scanf("%s", addressBook->contacts[index].email);
            while(getchar()!='\n');

            int len = strlen(addressBook->contacts[index].email);
            int isValid = 1;

            for (int i=0;i<len;i++)
            {
                if (isupper(addressBook->contacts[index].email[i]))
                {
                    isValid = 0;
                    break;
                }
            }
            if(isValid==0)
            {
                printf("invalid email! capital letter is not allowed.\n");
                continue;
            }
            if(addressBook->contacts[index].email[0]=='@')
            {
                printf("invalid email! first letter should be an alphabet.\n");
                continue;
            }
            int atcount=0;
            int atindex=-1;
            for(int i=0;i<len;i++)
            {
                if(addressBook->contacts[index].email[i] == '@')
                {
                    atcount++;
                    atindex=i;
                }
            }
            if(atcount!=1)
            {
                printf("invalid email! must contain only one '@' symbol\n");
                continue;
            }
            if(len<5 ||strcmp(&addressBook->contacts[index].email[len-4], ".com")!=0)
            {
                printf("invalid email! email must end with '.com'\n");
                continue;
            }
            if((len-4)-atindex<=1)
            {
                printf("invalid email! must contain domain name (at least 1 character between '@' and '.com')\n");
                continue;
            }
            break;
        }
        printf("Email accepted: %s\n", addressBook->contacts[index].email);
        addressBook->contactCount++;

        printf("Contact created successfully! Total contacts: %d\n", addressBook->contactCount);

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
