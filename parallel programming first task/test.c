// #include <stdio.h>
// #include <string.h>
// int main(void) {
//     int userCount = 1;
//     char usernames[100][10] = {"mohamed"};
//     while (1) {
//         printf("Enter 'register' to add a new user or 'login' to log in: ");
//         char choice[10];
//         scanf("%s", choice);
//         if (strcmp(choice, "register") == 0) {
//             if (userCount < 5) {
//                 printf("Enter a new username: ");
//                 char newUser[10];
//                 scanf("%s", newUser);
//                 // Check if the new username already exists
//                 int usernameExists = 0;
//                 for (int i = 0; i < userCount; i++) {
//                     if (strcmp(newUser, usernames[i]) == 0) {
//                         printf("Username already exists. Registration failed.\n");
//                         usernameExists = 1;
//                         break;
//                     }
//                 }
//                 if (!usernameExists) {
//                     strcpy(usernames[userCount], newUser);
//                     userCount++;
//                     printf("User registered successfully.\n");
//                 }
//             } else {
//                 printf("User limit reached. Cannot register more users.\n");
//             }
//         } else if (strcmp(choice, "login") == 0) {
//             char user[10];
//             printf("Enter your username: ");
//             scanf("%s", user);
//             int flags = 0;
//             for (int i = 0; i < userCount; i++) {
//                 if (strcmp(user, usernames[i]) == 0) {
//                     flags = 1;
//                     break;
//                 }
//             }
//             if (flags == 1) {
//                 printf("Login successful. Welcome, %s!\n", user);
//             } else {
//                 printf("Login failed. User not found.\n");
//             }
//         } else {
//             printf("Invalid choice. Please enter 'register' or 'login'.\n");
//         }
//     }
//     return 0;
// }


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char** usernames = NULL;
    int userCount = 0;

    while (1) {
        printf("Enter 'register' to add a new user or 'login' to log in: ");
        char choice[10];
        scanf("%s", choice);

        if (strcmp(choice, "register") == 0) {
            char newUser[10];
            printf("Enter a new username: ");
            scanf("%s", newUser);


            int usernameExists = 0;
            for (int i = 0; i < userCount; i++) {
                if (strcmp(newUser, usernames[i]) == 0) {
                    printf("Username already exists. Registration failed.\n");
                    usernameExists = 1;
                    break;
                }
            }

            if (!usernameExists) {
                usernames = (char**)realloc(usernames, (userCount + 1) * sizeof(char*));
                usernames[userCount] = (char*)malloc(10 * sizeof(char));
                strcpy(usernames[userCount], newUser);
                userCount++;
                printf("User registered successfully.\n");
            }
        } else if (strcmp(choice, "login") == 0) {
            char user[10];
            printf("Enter your username: ");
            scanf("%s", user);

            int flags = 0;
            for (int i = 0; i < userCount; i++) {
                if (strcmp(user, usernames[i]) == 0) {
                    flags = 1;
                    break;
                }
            }

            if (flags == 1) {
                printf("Login successful. Welcome, %s!\n", user);
            } else {
                printf("Login failed. User not found.\n");
            }
        } else {
            printf("Invalid choice. Please enter 'register' or 'login'.\n");
        }
    }
    return 0;
}
