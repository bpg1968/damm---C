#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <getopt.h>

#define VERSION "1.0"

// The Damm algorithm's quasigroup matrix
int damm_table[10][10] = {
  {0, 3, 1, 7, 5, 9, 8, 6, 4, 2},
  {7, 0, 9, 2, 1, 5, 4, 8, 6, 3},
  {4, 2, 0, 6, 8, 7, 1, 3, 5, 9},
  {1, 7, 5, 0, 9, 8, 3, 4, 2, 6},
  {6, 1, 2, 3, 0, 4, 5, 9, 7, 8},
  {3, 6, 7, 4, 2, 0, 9, 5, 8, 1},
  {5, 8, 6, 9, 7, 2, 0, 1, 3, 4},
  {8, 9, 4, 5, 3, 6, 2, 0, 1, 7},
  {9, 4, 3, 8, 6, 1, 7, 2, 0, 5},
  {2, 5, 8, 1, 4, 3, 6, 7, 9, 0}
};

// Compute the Damm check digit
int compute_damm_check_digit (const char *number)
{
  int interim = 0;
  for (size_t i = 0; i < strlen (number); i++)
    {
      if (number[i] < '0' || number[i] > '9')
        {
          fprintf (stderr, "Error: Input contains non-digit characters.\n");
          exit (EXIT_FAILURE);
        }
      interim = damm_table[interim][number[i] - '0'];
    }
  return interim;
}

// Validate a number with its check digit
bool validate_damm (const char *number)
{
  return compute_damm_check_digit (number) == 0;
}

void print_help (const char *program_name)
{
  printf ("Usage: %s <number>\n", program_name);
  printf ("       %s [OPTIONS] <number>\n", program_name);
  printf ("Options:\n");
  printf ("  -c, --check    Validate a number with its check digit\n");
  printf ("      --version  Show version information\n");
  printf ("      --help     Show this help message\n");
}

int main (int argc, char *argv[])
{
  int check_mode = 0;
  int version_flag = 0;
  int help_flag = 0;
  struct option long_options[] = {
    {"check", no_argument, &check_mode, 1},
    {"version", no_argument, &version_flag, 1},
    {"help", no_argument, &help_flag, 1},
    {0, 0, 0, 0}
  };

  int opt;
  while ((opt = getopt_long (argc, argv, "c", long_options, NULL)) != -1)
    {
      if (opt == 'c')
        {
          check_mode = 1;
        }
    }

  if (version_flag)
    {
      printf ("damm version %s\n", VERSION);
      return EXIT_SUCCESS;
    }

  if (help_flag)
    {
      print_help (argv[0]);
      return EXIT_SUCCESS;
    }

  if (optind >= argc)
    {
      fprintf (stderr, "Usage: %s [-c | --check] <number>\n", argv[0]);
      return EXIT_FAILURE;
    }

  char *input = argv[optind];

  if (check_mode)
    {
      if (validate_damm (input))
        {
          return EXIT_SUCCESS;  // Valid check digit; output nothing
        }
      else
        {
          fprintf (stderr, "Error: Invalid check digit.\n");
          return EXIT_FAILURE;
        }
    }
  else
    {
      int check_digit = compute_damm_check_digit (input);
      printf ("%s%d\n", input, check_digit);
      return EXIT_SUCCESS;
    }
}
