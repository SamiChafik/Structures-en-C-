#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct address {
    char street[50];
    char city[20];
    int code_postal;
} address; //struct to stock user address

typedef struct Apprenent {
        char family_name[20];
        char name[30];
        int age;
        float note;
        address addr;
    } apprenent; //struct to stock user info.

int creat(apprenent A[], int *count) {//function to stock user data in the struct.
    if (*count >= 50) {
        printf ("you reached the limit, you cant add more learners");
        return 0;
    }
    
    printf ("<= new learner =>\n");
    printf ("entre family name : ");
    scanf (" %[^\n]", A[*count].family_name);//%[^\n] to read string with spaces
    printf ("entre personal name : ");
    scanf (" %[^\n]", A[*count].name);
    printf ("age : ");
    scanf ("%d", &A[*count].age);
    printf ("note :");
    scanf ("%f", &A[*count].note);
    printf ("entre your address\n");
    printf ("street : ");
    scanf (" %[^\n]", A[*count].addr.street);
    printf ("city : ");
    scanf (" %[^\n]", A[*count].addr.city);
    printf ("code postal : ");
    scanf ("%d", &A[*count].addr.code_postal);

    (*count)++;//pointer of count to add 1 to count in main.
    printf ("learner added");
}
void print(apprenent A[], int count) {//function to print all stored user data.
    int i;
    printf ("\n<= list of learners =>\n");

    for (i = 0; i < count; i++) {//this loop print all users info in order from 0 to count.
        printf ("=== learner %d ===\n", i + 1);
        printf ("name : %s\n", A[i].name);
        printf ("family name : %s\n", A[i].family_name);
        printf ("age : %d\n", A[i].age);
        printf ("note : %.2f\n", A[i].note);
        printf ("address : %s %s %d\n", A[i].addr.street, A[i].addr.city, A[i].addr.code_postal);
        printf ("=========\n");
    }
}
void modify(apprenent A[], int count) {//function to modify user info in the struct.
    int id;

    printf ("enter the learner id to modify : ");
    scanf ("%d", &id);

    if (id == 0 || id > count) {//this loop checks if user exists if not it prints a message.
        printf ("learner does not exist.\n");
        return 0;
    }

    id--;//decreases by 1 so it starts from id - 1 because the users stored in the array starts from 0.
    printf ("<= Update learner info =>\n");
    printf ("new name : ");
    scanf (" %[^\n]", A[id].name);
    printf ("new family name : ");
    scanf (" %[^\n]", A[id].family_name);
    printf ("new age : ");
    scanf ("%d", &A[id].age);
    printf ("new note : \n");
    scanf ("%f", &A[id].note);
    printf ("new address\n");
    printf ("street : ");
    scanf (" %[^\n]", A[id].addr.street);
    printf ("city : ");
    scanf (" %[^\n]", A[id].addr.city);
    printf ("code postal : ");
    scanf ("%d", &A[id].addr.code_postal);

    printf ("update successful.\n");
}
void delete(apprenent A[], int *count) {//function to delete user info from the struct.
    int i,id;
    printf ("enter the learner id you want to delete (1-%d) : ", *count);
    scanf ("%d", &id);

    if (id == 0 || id > count) {
        printf ("learner does not exist.\n");
        return 0;
    }
    
    id--;
    for (i = id; i < *count - 1; i++) {//this loop shifts the user in the next array to the array of the user we want to delete.
        A[i] = A[i+1];
    }
    (*count)--;//count - 1 in the main function since we deleted a user. 
    printf ("learner deleted succefully.\n");
}

int main () {
    int ch,count = 0;
    apprenent A[50];//array for the size of our struct. 

    do {//display menu.
        printf ("--- Menu ---");
        printf ("\n1.creat a learner");
        printf ("\n2.learners list");
        printf ("\n3.modify learner");
        printf ("\n4.delete learner");
        printf ("\n5.exit");

        printf ("\nentre your choice : ");
        scanf ("%d", &ch);

        switch (ch) {
            case 1 : 
                creat(A, &count);//& because we used the pointer in this function.
            break;
            case 2 :
                print(A, count);
            break;
            case 3 :
                modify(A, count);
            break;
            case 4 :
                delete(A, &count);
            break;
            case 5 :
                printf ("exiting program...\n");//exit the program
                exit(0);
            default :
                printf ("invalid choice, try again.\n");//if the user entred wrong number (ch).
        } 
    } while (ch != 0);
}