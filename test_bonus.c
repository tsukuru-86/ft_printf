#include "ft_printf_bonus.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CAPTURE_SIZE 256

enum e_argument_type
{
	ARG_NONE,
	ARG_INT,
	ARG_UNSIGNED,
	ARG_STRING,
	ARG_POINTER
};

typedef struct s_capture
{
	char	output[CAPTURE_SIZE];
	int		length;
	int		return_value;
} t_capture;

static void	capture_begin(int pipefd[2], int *saved_stdout)
{
	fflush(stdout);
	if (pipe(pipefd) == -1 || (*saved_stdout = dup(STDOUT_FILENO)) == -1
		|| dup2(pipefd[1], STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(pipefd[1]);
}

static void	capture_end(t_capture *capture, int read_fd, int saved_stdout)
{
	ssize_t	read_size;

	fflush(stdout);
	if (dup2(saved_stdout, STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(saved_stdout);
	read_size = read(read_fd, capture->output, CAPTURE_SIZE - 1);
	if (read_size < 0)
		exit(EXIT_FAILURE);
	capture->length = (int)read_size;
	capture->output[capture->length] = '\0';
	close(read_fd);
}

static int	call_libc_without_argument(const char *format, ...)
{
	va_list	arguments;
	int		result;

	va_start(arguments, format);
	result = vprintf(format, arguments);
	va_end(arguments);
	return (result);
}

static int	call_printf(int mine, const char *format,
		enum e_argument_type type, unsigned long long value)
{
	if (type == ARG_INT)
		return (mine ? ft_printf(format, (int)value) : printf(format, (int)value));
	if (type == ARG_UNSIGNED)
		return (mine ? ft_printf(format, (unsigned int)value)
			: printf(format, (unsigned int)value));
	if (type == ARG_STRING)
		return (mine ? ft_printf(format, (const char *)value)
			: printf(format, (const char *)value));
	if (type == ARG_POINTER)
		return (mine ? ft_printf(format, (const void *)value)
			: printf(format, (const void *)value));
	return (mine ? ft_printf(format) : call_libc_without_argument(format));
}

static int	test_case(const char *name, const char *format,
		enum e_argument_type type, unsigned long long value)
{
	t_capture	official;
	t_capture	mine;
	int			pipefd[2];
	int			saved_stdout;

	capture_begin(pipefd, &saved_stdout);
	official.return_value = call_printf(0, format, type, value);
	capture_end(&official, pipefd[0], saved_stdout);
	capture_begin(pipefd, &saved_stdout);
	mine.return_value = call_printf(1, format, type, value);
	capture_end(&mine, pipefd[0], saved_stdout);
	if (official.length != mine.length
		|| official.return_value != mine.return_value
		|| memcmp(official.output, mine.output, official.length) != 0)
	{
		printf("[FAIL] %-28s %s\n", name, format);
		printf("       printf: |%s| (%d)\n", official.output,
			official.return_value);
		printf("   ft_printf: |%s| (%d)\n", mine.output, mine.return_value);
		return (0);
	}
	printf("[ OK ] %-28s %s\n", name, format);
	return (1);
}

int	main(void)
{
	int	passed;
	int	total;
	int	marker;

	passed = 0;
	total = 0;
	marker = 42;
	printf("ft_printf bonus review checks\n\n");
	printf("Basic conversions\n");
	passed += test_case("char", "%c", ARG_INT, 'A'); total++;
	passed += test_case("string", "%s", ARG_STRING,
		(unsigned long long)"hello"); total++;
	passed += test_case("unsigned", "%u", ARG_UNSIGNED, 42); total++;
	passed += test_case("hex lowercase", "%x", ARG_UNSIGNED, 42); total++;
	passed += test_case("hex uppercase", "%X", ARG_UNSIGNED, 42); total++;
	passed += test_case("pointer", "%p", ARG_POINTER,
		(unsigned long long)&marker); total++;
	passed += test_case("percent", "%%", ARG_NONE, 0); total++;

	printf("\nRequired bonus flags and precision\n");
	passed += test_case("INT_MIN", "%d", ARG_INT, (unsigned int)INT_MIN); total++;
	passed += test_case("width", "%10d", ARG_INT, 42); total++;
	passed += test_case("minus flag", "%-10d", ARG_INT, 42); total++;
	passed += test_case("zero flag", "%04d", ARG_INT, 42); total++;
	passed += test_case("precision 2", "%.2d", ARG_INT, 42); total++;
	passed += test_case("precision 8", "%.8d", ARG_INT, 42); total++;
	passed += test_case("precision 0", "%.0d", ARG_INT, 0); total++;
	passed += test_case("hash lowercase", "%#x", ARG_UNSIGNED, 42); total++;
	passed += test_case("hash uppercase", "%#X", ARG_UNSIGNED, 42); total++;
	passed += test_case("plus flag", "%+d", ARG_INT, 42); total++;
	passed += test_case("space flag", "% d", ARG_INT, 42); total++;
	passed += test_case("plus over space", "%+ d", ARG_INT, 42); total++;

	printf("\nResult: %d/%d matched (output and return value)\n", passed, total);
	return (passed == total ? EXIT_SUCCESS : EXIT_FAILURE);
}
