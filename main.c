#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// User struct
typedef struct
{
  char name[20]; // Username
  // 0 for A meaning unsure or in between
  int a; // Introversion/Extroversion (E/I) +1 for E, -1 for I
  int b; // Sensing/Intuition (S/N) +1 for N, -1 for S
  int c; // Thinking/Feeling (T/F) +1 for T, -1 for F
  int d; // Judging/Perceiving (J/P) +1 for P, -1 for J
  int e; // Difficult/Cooperative (Y/N) +1 for Y, -1 for N
} user;

user users[100];    // Array of users
int user_count = 0; // Number of users

// Function to create a user
void create_user(char name[20], int a, int b, int c, int d, int e)
{
  // Create user
  user *u = malloc(sizeof(user));
  strcpy(u->name, name);
  u->a = a;
  u->b = b;
  u->c = c;
  u->d = d;
  u->e = e;
  // Add user to array
  users[user_count] = *u;
  user_count++;
}
// Function to output user details
void output_user(user u)
{
  char a, b, c, d, e;
  // First letter
  if (u.a > 0)
  {
    a = 'E';
  }
  else if (u.a < 0)
  {
    a = 'I';
  }
  else
  {
    a = 'A';
  }
  // Second letter
  if (u.b > 0)
  {
    b = 'N';
  }
  else if (u.b < 0)
  {
    b = 'S';
  }
  else
  {
    b = 'A';
  }
  // Third letter
  if (u.c > 0)
  {
    c = 'T';
  }
  else if (u.c < 0)
  {
    c = 'F';
  }
  else
  {
    c = 'A';
  }
  // Fourth letter
  if (u.d > 0)
  {
    d = 'P';
  }
  else if (u.d < 0)
  {
    d = 'J';
  }
  else
  {
    d = 'A';
  }
  // Fifth letter
  if (u.e > 0)
  {
    e = 'Y';
  }
  else if (u.e < 0)
  {
    e = 'N';
  }
  else
  {
    e = 'A';
  }
  printf("Name: %s\nPersonality: %c%c%c%c+%c\n", u.name, a, b, c, d, e);
}
// Add user function
user new_user(char name[20])
{
  int a = 0, b = 0, c = 0, d = 0, e = 0;
  char user_in;
  printf("Question 1: When attending a social gathering, do you feel energized and look forward to meeting new people (y), or do you prefer to stick with a few familiar faces and leave early to recharge (n)?\n");
  scanf("%c", &user_in);
  printf("%c\n", toupper(user_in));
  if (toupper(user_in) == 'Y')
  {
    a++;
  }
  else if (toupper(user_in) == 'N')
  {
    a--;
  }
  printf("Question 2: In your free time, do you prefer engaging in activities alone (e.g., reading, writing, or watching movies) (y), or do you prefer group activities like team sports or going out with friends (n)?\n");
  getchar();
  scanf("%c", &user_in);
  if (toupper(user_in) == 'Y')
  {
    a--;
  }
  else if (toupper(user_in) == 'N')
  {
    a++;
  }
  printf("Question 3: When solving a problem, do you focus more on practical details and proven methods (y), or do you prefer exploring creative possibilities and brainstorming new approaches (n)?\n");
  getchar();
  scanf("%c", &user_in);
  if (toupper(user_in) == 'Y')
  {
    b--;
  }
  else if (toupper(user_in) == 'N')
  {
    b++;
  }
  printf("Question 4: Do you rely on tangible facts and your past experiences when making decisions (y), or do you tend to trust your instincts and envision future outcomes (n)?");
  getchar();
  scanf("%c", &user_in);
  if (toupper(user_in) == 'Y')
  {
    b--;
  }
  else if (toupper(user_in) == 'N')
  {
    b++;
  }
  printf("Question 5: When making a difficult decision, do you prioritize logic, fairness, and consistency over the emotional impact it may have on others?\n");
  getchar();
  scanf("%c", &user_in);
  if (toupper(user_in) == 'Y')
  {
    c++;
  }
  else if (toupper(user_in) == 'N')
  {
    c--;
  }
  printf("Question 6: When resolving a conflict, do you focus on solving the problem objectively (y), or do you prioritize maintaining harmony and understanding everyone’s feelings (n)?\n");
  getchar();
  scanf("%c", &user_in);
  if (toupper(user_in) == 'Y')
  {
    c++;
  }
  else if (toupper(user_in) == 'N')
  {
    c--;
  }
  printf("Question 7: Do you prefer sticking to a structured plan with clear deadlines (y), or do you feel more comfortable adapting to changes and keeping your options open until the last minute (n)?\n");
  getchar();
  scanf("%c", &user_in);
  if (toupper(user_in) == 'Y')
  {
    d--;
  }
  else if (toupper(user_in) == 'N')
  {
    d++;
  }
  printf("Question 8: When organizing a trip or project, do you like creating detailed itineraries or schedules (y), or do you enjoy leaving room for spontaneity and unexpected opportunities (n)?\n");
  getchar();
  scanf("%c", &user_in);
  if (toupper(user_in) == 'Y')
  {
    d--;
  }
  else if (toupper(user_in) == 'N')
  {
    d++;
  }
  printf("Question 9: Do you often find yourself drawn to people who approach problems, decisions, or life in a way that challenges your usual perspective, even if it sometimes feels frustrating?\n");
  getchar();
  scanf("%c", &user_in);
  if (toupper(user_in) == 'Y')
  {
    e++;
  }
  else if (toupper(user_in) == 'N')
  {
    e--;
  }
  printf("Question 10: When someone close to you makes decisions or reacts in a way you wouldn’t (e.g., being spontaneous when you prefer planning, or being emotional when you prefer logic), do you feel curious and intrigued about their perspective rather than frustrated?\n");
  getchar();
  scanf("%c", &user_in);
  if (toupper(user_in) == 'Y')
  {
    e++;
  }
  else if (toupper(user_in) == 'N')
  {
    e--;
  }
  getchar();
  if (a > 0)
  {
    a = 1;
  }
  else if (a < 0)
  {
    a = -1;
  }
  if (b > 0)
  {
    b = 1;
  }
  else if (b < 0)
  {
    b = -1;
  }
  if (c > 0)
  {
    c = 1;
  }
  else if (c < 0)
  {
    c = -1;
  }
  if (d > 0)
  {
    d = 1;
  }
  else if (d < 0)
  {
    d = -1;
  }
  if (e > 0)
  {
    e = 1;
  }
  else if (e < 0)
  {
    e = -1;
  }
  create_user(name, a, b, c, d, e);
  printf("User added.\n");
  output_user(users[user_count - 1]);
}
// Check compatibility with all users
void check_compatibility(char name[20])
{
  int user_found = -1;
  for (int i = 0; i < user_count; i++)
  {
    if (strcmp(users[i].name, name) == 0)
    {
      user_found = i;
    }
  }
  if (user_found == -1)
  {
    printf("Error: User %s not found.\n", name);
    return;
  }
  int score;
  user u = users[user_found];
  if (u.e < 0)
  {
    for (int i = 0; i < user_count; i++)
    {
      score = 0;
      if (u.a == users[i].a)
      {
        score += 25;
      }
      if (u.b == users[i].b)
      {
        score += 25;
      }
      if (u.c == users[i].c)
      {
        score += 25;
      }
      if (u.d == users[i].d)
      {
        score += 25;
      }
      printf("Compatibility with %s: %d%%\n", users[i].name, score);
    }
    return;
  }
  for (int i = 0; i < user_count; i++)
  {
    score = 0;
    if (users[i].e < 0)
    {
      if (u.a == users[i].a)
      {
        score += 25;
      }
      if (u.b == users[i].b)
      {
        score += 25;
      }
      if (u.c == users[i].c)
      {
        score += 25;
      }
      if (u.d == users[i].d)
      {
        score += 25;
      }
      printf("Compatibility with %s: %d%%\n", users[i].name, score);
      continue;
    }
    if (u.e > 0 && users[i].e > 0)
    {
      if (u.a + users[i].a == 0)
      {
        score += 25;
      }
      else
      {
        score += 15;
      }
      if (u.b + users[i].b == 0)
      {
        score += 25;
      }
      else
      {
        score += 15;
      }
      if (u.c == users[i].c)
      {
        score += 25;
      }
      else
      {
        score += 5;
      }
      if (u.d == users[i].d)
      {
        score += 25;
      }
      else
      {
        score += 5;
      }
      printf("Compatibility with %s: %d%%\n", users[i].name, score);
      continue;
    }
    else
    {
      if (u.a == users[i].a)
      {
        score += 25;
      }
      else
      {
        score += 15;
      }
      if (u.b == users[i].b)
      {
        score += 25;
      }
      else
      {
        score += 15;
      }
      if (u.c == users[i].c)
      {
        score += 25;
      }
      else
      {
        score += 5;
      }
      if (u.d == users[i].d)
      {
        score += 25;
      }
      else
      {
        score += 5;
      }
      printf("Compatibility with %s: %d%%\n", users[i].name, score);
      continue;
    }
  }
}
// Main function
int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    printf("Usage: %s <users_file>\n", argv[0]);
    return 1;
  }

  printf("Welcome.\n");
  char line[100];
  // Open file
  FILE *fp;
  fp = fopen(argv[1], "r");
  // Check if file opened
  if (fp == NULL)
  {
    printf("Error opening users file.\n");
    return 1;
  }
  // Read file into users array
  while (fgets(line, 100, fp))
  {
    char *username = strtok(line, ":");
    char *ac = strtok(NULL, ":");
    char *bc = strtok(NULL, ":");
    char *cc = strtok(NULL, ":");
    char *dc = strtok(NULL, ":");
    char *ec = strtok(NULL, "\n");
    int a = atoi(ac);
    int b = atoi(bc);
    int c = atoi(cc);
    int d = atoi(dc);
    int e = atoi(ec);
    create_user(username, a, b, c, d, e);
  }
  fclose(fp);

  char user_input[20];
  // Main loop
  while (1)
  {
    printf("To add a user type: add <username>\nTo list users type: list.\nTo test a users compatibility type: check <username>\nTo exit type: exit.\n");
    fgets(user_input, sizeof(user_input), stdin);
    user_input[strcspn(user_input, "\n")] = '\0';
    if (user_input == NULL)
    {
      continue;
    }
    // Exit
    if (strcmp(user_input, "exit") == 0)
    {
      // Write users to file
      FILE *fpw;
      fpw = fopen("users", "w");
      for (int i = 0; i < user_count; i++)
      {
        fprintf(fpw, "%s:%d:%d:%d:%d:%d\n", users[i].name, users[i].a, users[i].b, users[i].c, users[i].d, users[i].e);
      }
      fclose(fpw);
      printf("Goodbye!\n");
      return 0;
    }
    // List users
    else if (strcmp(user_input, "list") == 0)
    {
      for (int i = 0; i < user_count; i++)
      {
        output_user(users[i]);
      }
      continue;
    }
    char *command = strtok(user_input, " ");
    if (command == NULL)
    {
      continue;
    }
    char *command_argument = strtok(NULL, "\n");
    if (command_argument == NULL)
    {
      continue;
    }
    printf("%s:%s\n", command, command_argument);
    // Add user
    if (strcmp(command, "add") == 0 && command_argument != NULL)
    {
      printf("Answer these questions with Y/N/U (Yes/No/Unsure) for %s\n", command_argument);
      new_user(command_argument);
      continue;
    }
    // Check compatibility of user
    if (strcmp(command, "check") == 0 && command_argument != NULL)
    {
      check_compatibility(command_argument);
      continue;
    }
  }
  return 0;
}