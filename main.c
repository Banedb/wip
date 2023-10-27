#include "shell.h"
/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Arguments passed to function
 *
 * Return: 0 (Success)
 */
int main(int argc, char **argv)
{
	int exit_status;

	prompt = "$ ";
	/*printf("main1 here\n");*/
	name = argv[0];
	if (signal(SIGINT, sig_h) == SIG_ERR)
	{
		exit(EXIT_FAILURE);
		/*printf("main2 here\n");*/
	}

	/* Interactive mode: */
	if (isatty(STDIN_FILENO))
	{
		/*printf("main3 here\n");*/
		while (1)
		{
			/*printf("main4 here\n");*/
			write(STDOUT_FILENO, prompt, 2);
			/*printf("main5 here\n");*/
			fflush(stdout);
			/*printf("main6 here\n");*/
			exit_status = run_input();
			/*printf("main10 here\n");*/
		}
	}
	else
	{/* Non-interactive mode: */
		exit_status = run_input();
		printf("main7 here\n");
		return (exit_status);
	}
	printf("main8 here\n");
	(void)argc;
	return (exit_status);
}
