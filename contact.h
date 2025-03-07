// Header file for the Address Book application.  
// Defines data structures and function prototypes for managing contacts.

#ifndef CONTACT_H
#define CONTACT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 100 // Maximum number of contacts

// Structure to store contact details: name, phone number, and email.
typedef struct
{
    char name[100];
    char phone[15];
    char email[50];
} Contact;

// Structure to manage the address book, containing an array of contacts and a count.
typedef struct
{
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

// Function prototypes for address book operations
void initialize(AddressBook *addressBook);      // Initialize the address book
void listContacts(AddressBook *addressBook);    // Display all contacts
void loadContactsFromFile(AddressBook *addressBook); // Load contacts from file
void saveContactsToFile(AddressBook *addressBook);   // Save contacts to file
void editContact(AddressBook *addressBook);     // Edit a contact
void deleteContact(AddressBook *addressBook);   // Delete a contact
void createContact(AddressBook *addressBook);   // Create a new contact
void searchContact(AddressBook *addressBook);   // Search for a contact
void populateAddressBook(AddressBook* addressBook);

#endif // CONTACT_H
