#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "contact.h"
#include "file.h"
// #include "populate.h"

// sorting by names
void sortContactsByName(AddressBook *addressBook)
{
    int count=addressBook->contactCount;
    for(int i=0;i < count-1;i++)
    {
        for(int j=0;j < count-i-1;j++)
        {
            if(strcmp(addressBook->contacts[j].name, addressBook->contacts[j+1].name) > 0)
            {
                Contact temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1] = temp;
            }
        }
    }
}
// sorting by phone number
void sortContactsByPhone(AddressBook *addressBook)
{
    int count=addressBook->contactCount;
    for(int i=0;i < count-1;i++)
    {
        for(int j=0;j < count-i-1;j++)
        {
            if(strcmp(addressBook->contacts[j].phone, addressBook->contacts[j+1].phone) > 0)
            {
                Contact temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1] = temp;
            }
        }
    }
}
// sorting by email
void sortContactsByEmail(AddressBook *addressBook)
{
    int count=addressBook->contactCount;
    for(int i=0;i < count-1;i++)
    {
        for(int j=0;j < count-i-1;j++)
        {
            if(strcmp(addressBook->contacts[j].email, addressBook->contacts[j+1].email) > 0)
            {
                Contact temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1] = temp;
            }
        }
    }
}

   
// Func 3: Main list function
void listContacts(AddressBook *addressBook)
{
    // if no contact found
    if (addressBook->contactCount == 0)
    {
        printf("\nNo contacts found!\n\n");
        return;
    }

   int criteria;
   printf("sort based on:\n1.Name\n2.phone\n3.email\n");
   scanf("%d",&criteria);
   if(criteria==1)
   {
        sortContactsByName(addressBook);
   }
   else if(criteria==2)
   {
        sortContactsByPhone(addressBook);
   }
   else if(criteria==3)
   {
        sortContactsByEmail(addressBook);
   }
   else{
        printf("invalid choice!\n");
   }

    printf("\n=======================================================================\n");
    printf("%-6s %-20s %-16s %-30s\n", "S.No", "Name", "Phone Number", "Email");
    printf("-----------------------------------------------------------------------\n");

    // prints the content in rows
    for (int i=0;i<addressBook->contactCount;i++)
    {
        printf("%-6d %-20s %-16s %-30s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

    printf("=======================================================================\n");
    printf("Total Contacts: %d\n\n", addressBook->contactCount);
}  


void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}



void validateName(AddressBook *addressBook, int index, int *isValid)
{
    *isValid = 1;
    int len = strlen(addressBook->contacts[index].name);

    if (len<2)
    {
        printf("Invalid Name! Name must be at least 2 characters \n");
        *isValid = 0;
        return;
    }

    for (int i=0;i<len;i++)
    {
        if (!isalnum(addressBook->contacts[index].name[i]) && addressBook->contacts[index].name[i] != ' ')
        {
            printf("Invalid Name! Name must contain only alphanumeric characters or spaces\n");
            *isValid = 0;
            return;
        }
    }

    for (int i=0; i<index; i++)
    {
        if (strcmp(addressBook->contacts[i].name, addressBook->contacts[index].name) == 0)
        {
            printf("Name already exists! Please re-enter.\n");
            *isValid = 0;
            return;
        }
    }
}

void validatePhone(AddressBook *addressBook, int index, int *isValid)
{
    *isValid = 1;
    int len = strlen(addressBook->contacts[index].phone);

    if (len != 10)
    {
        printf("invalid phone number!must be exactly 10 digits.\n");
        *isValid = 0;
        return;
    }

    if (addressBook->contacts[index].phone[0] < '6' || addressBook->contacts[index].phone[0] > '9')
    {
        printf("invalid phone number! first digit must be between 6 and 9\n");
        *isValid = 0;
        return;
    }

    for (int i=0;i<len;i++)
    {
        if (!isdigit(addressBook->contacts[index].phone[i]))
        {
            printf("invalid phone number! must contain only digits\n");
            *isValid = 0;
            return;
        }
    }

    for (int i=0; i<index; i++)
    {
        if (strcmp(addressBook->contacts[i].phone, addressBook->contacts[index].phone) == 0)
        {
            printf("Phone number already exists! Please re-enter.\n");
            *isValid = 0;
            return;
        }
    }
}

void validateEmail(AddressBook *addressBook, int index, int *isValid)
{
    *isValid = 1;
    int len = strlen(addressBook->contacts[index].email);

    for (int i=0;i<len;i++)
    {
        if (isupper(addressBook->contacts[index].email[i]))
        {
            printf("invalid email! capital letter is not allowed.\n");
            *isValid = 0;
            return;
        }
    }

    if (addressBook->contacts[index].email[0] == '@')
    {
        printf("invalid email! first letter should be an alphabet.\n");
        *isValid = 0;
        return;
    }

    int atcount = 0;
    int atindex = -1;
    for (int i=0;i<len;i++)
    {
        if (addressBook->contacts[index].email[i] == '@')
        {
            atcount++;
            atindex = i;
        }
    }

    if (atcount != 1)
    {
        printf("invalid email! must contain only one '@' symbol\n");
        *isValid = 0;
        return;
    }

    if (len < 5 || strcmp(&addressBook->contacts[index].email[len-4], ".com") != 0)
    {
        printf("invalid email! email must end with '.com'\n");
        *isValid = 0;
        return;
    }

    if ((len-4) - atindex <= 1)
    {
        printf("invalid email! must contain domain name\n");
        *isValid = 0;
        return;
    }

    for (int i=0; i<index; i++)
    {
        if (strcmp(addressBook->contacts[i].email, addressBook->contacts[index].email) == 0)
        {
            printf("Email already exists! Please re-enter.\n");
            *isValid = 0;
            return;
        }
    }
}

void createContact(AddressBook *addressBook)
{
    if (addressBook->contactCount >= 100)
    {
        printf("Error: Address Book is full!\n");
        return;
    }

    int index = addressBook->contactCount;
    int isValid;

    while (1)
    {
        printf("Enter name: ");
        scanf(" %[^\n]", addressBook->contacts[index].name);

        validateName(addressBook, index, &isValid);
        if (isValid)
        {
            break;
        }
    }
    // printf("name accepted : %s\n\n", addressBook->contacts[index].name);

    while (1)
    {
        printf("Enter phone number: ");
        scanf("%s", addressBook->contacts[index].phone);
        while (getchar() != '\n');

        validatePhone(addressBook, index, &isValid);
        if (isValid)
        {
            break;
        }
    }
    // printf("Phone number accepted: %s\n\n", addressBook->contacts[index].phone);

    while (1)
    {
        printf("Enter email: ");
        scanf("%s", addressBook->contacts[index].email);
        while (getchar() != '\n');

        validateEmail(addressBook, index, &isValid);
        if (isValid)
        {
            break;
        }
    }
    // printf("Email accepted: %s\n", addressBook->contacts[index].email);

    addressBook->contactCount++;
    printf("Contact created successfully! Total contacts: %d\n\n", addressBook->contactCount);
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
