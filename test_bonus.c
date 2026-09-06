/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 00:00:00 by tkomai            #+#    #+#             */
/*   Updated: 2026/09/02 00:00:00 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CAPTURE_SIZE 4096

typedef struct s_capture
{
	char	output[CAPTURE_SIZE];
	int		length;
	int		return_value;
} t_capture;

static void	fatal_test_error(const char *operation)
{
	perror(operation);
	exit(EXIT_FAILURE);
}

static int	libc_printf(const char *format, ...)
{
	va_list	arguments;
	int		result;

	va_start(arguments, format);
	result = vprintf(format, arguments);
	va_end(arguments);
	return (result);
}

static void	begin_capture(int descriptors[2], int *saved_stdout)
{
	fflush(stdout);
	if (pipe(descriptors) == -1)
		fatal_test_error("pipe");
	*saved_stdout = dup(STDOUT_FILENO);
	if (*saved_stdout == -1)
		fatal_test_error("dup");
	if (dup2(descriptors[1], STDOUT_FILENO) == -1)
		fatal_test_error("dup2");
	close(descriptors[1]);
}

static void	end_capture(t_capture *capture, int read_fd, int saved_stdout)
{
	ssize_t	bytes_read;
	int		total;

	fflush(stdout);
	if (dup2(saved_stdout, STDOUT_FILENO) == -1)
		fatal_test_error("dup2");
	close(saved_stdout);
	total = 0;
	bytes_read = read(read_fd, capture->output, CAPTURE_SIZE - 1);
	while (bytes_read > 0)
	{
		total += (int)bytes_read;
		bytes_read = read(read_fd, capture->output + total,
				CAPTURE_SIZE - 1 - total);
	}
	if (bytes_read == -1)
		fatal_test_error("read");
	close(read_fd);
	capture->output[total] = '\0';
	capture->length = total;
}

static int	report_test(const char *name, const char *format,
		t_capture *official, t_capture *mine)
{
	int	passed;

	passed = official->length == mine->length
		&& official->return_value == mine->return_value
		&& memcmp(official->output, mine->output, official->length) == 0;
	printf("[%s] %s  format=\"%s\"\n",
		passed ? "MATCH" : "DIFF", name, format);
	printf("  printf   : |");
	fwrite(official->output, 1, official->length, stdout);
	printf("| return=%d, bytes=%d\n", official->return_value,
		official->length);
	printf("  ft_printf: |");
	fwrite(mine->output, 1, mine->length, stdout);
	printf("| return=%d, bytes=%d\n", mine->return_value, mine->length);
	return (passed);
}

static int	test_int(const char *name, const char *format, int value)
{
	t_capture	official;
	t_capture	mine;
	int			descriptors[2];
	int			saved_stdout;

	begin_capture(descriptors, &saved_stdout);
	official.return_value = libc_printf(format, value);
	end_capture(&official, descriptors[0], saved_stdout);
	begin_capture(descriptors, &saved_stdout);
	mine.return_value = ft_printf(format, value);
	end_capture(&mine, descriptors[0], saved_stdout);
	return (report_test(name, format, &official, &mine));
}

static int	test_uint(const char *name, const char *format,
		unsigned int value)
{
	t_capture	official;
	t_capture	mine;
	int			descriptors[2];
	int			saved_stdout;

	begin_capture(descriptors, &saved_stdout);
	official.return_value = libc_printf(format, value);
	end_capture(&official, descriptors[0], saved_stdout);
	begin_capture(descriptors, &saved_stdout);
	mine.return_value = ft_printf(format, value);
	end_capture(&mine, descriptors[0], saved_stdout);
	return (report_test(name, format, &official, &mine));
}

static int	test_string(const char *name, const char *format,
		const char *value)
{
	t_capture	official;
	t_capture	mine;
	int			descriptors[2];
	int			saved_stdout;

	begin_capture(descriptors, &saved_stdout);
	official.return_value = libc_printf(format, value);
	end_capture(&official, descriptors[0], saved_stdout);
	begin_capture(descriptors, &saved_stdout);
	mine.return_value = ft_printf(format, value);
	end_capture(&mine, descriptors[0], saved_stdout);
	return (report_test(name, format, &official, &mine));
}

static int	test_char(const char *name, const char *format, int value)
{
	t_capture	official;
	t_capture	mine;
	int			descriptors[2];
	int			saved_stdout;

	begin_capture(descriptors, &saved_stdout);
	official.return_value = libc_printf(format, value);
	end_capture(&official, descriptors[0], saved_stdout);
	begin_capture(descriptors, &saved_stdout);
	mine.return_value = ft_printf(format, value);
	end_capture(&mine, descriptors[0], saved_stdout);
	return (report_test(name, format, &official, &mine));
}

static int	test_pointer(const char *name, const char *format,
		const void *value)
{
	t_capture	official;
	t_capture	mine;
	int			descriptors[2];
	int			saved_stdout;

	begin_capture(descriptors, &saved_stdout);
	official.return_value = libc_printf(format, value);
	end_capture(&official, descriptors[0], saved_stdout);
	begin_capture(descriptors, &saved_stdout);
	mine.return_value = ft_printf(format, value);
	end_capture(&mine, descriptors[0], saved_stdout);
	return (report_test(name, format, &official, &mine));
}

static int	test_percent(const char *name, const char *format)
{
	t_capture	official;
	t_capture	mine;
	int			descriptors[2];
	int			saved_stdout;

	begin_capture(descriptors, &saved_stdout);
	official.return_value = libc_printf(format);
	end_capture(&official, descriptors[0], saved_stdout);
	begin_capture(descriptors, &saved_stdout);
	mine.return_value = ft_printf(format);
	end_capture(&mine, descriptors[0], saved_stdout);
	return (report_test(name, format, &official, &mine));
}

static void	print_section(const char *title)
{
	printf("\n============================================================\n");
	printf("%s\n", title);
	printf("============================================================\n");
}

static void	test_text_conversions(int *passed, int *total)
{
	print_section("c / s: field width, '-' and precision");
	*passed += test_char("character width", "%5c", 'A');
	(*total)++;
	*passed += test_char("character left aligned", "%-5c", 'A');
	(*total)++;
	*passed += test_string("string width", "%10s", "hello");
	(*total)++;
	*passed += test_string("string left aligned", "%-10s", "hello");
	(*total)++;
	*passed += test_string("string precision", "%.3s", "abcdef");
	(*total)++;
	*passed += test_string("string width and precision", "%10.3s", "abcdef");
	(*total)++;
	*passed += test_string("string '-' width precision", "%-10.3s", "abcdef");
	(*total)++;
	*passed += test_string("string precision zero", "%.0s", "abcdef");
	(*total)++;
}

static void	test_signed_conversions(int *passed, int *total)
{
	print_section("d / i: width, '-', '0', precision, '+', space");
	*passed += test_int("INT_MIN", "%d", INT_MIN);
	(*total)++;
	*passed += test_int("INT_MAX", "%i", INT_MAX);
	(*total)++;
	*passed += test_int("minimum width", "%10d", 42);
	(*total)++;
	*passed += test_int("left aligned", "%-10d", 42);
	(*total)++;
	*passed += test_int("zero padded", "%010d", 42);
	(*total)++;
	*passed += test_int("zero padded negative", "%010d", -42);
	(*total)++;
	*passed += test_int("precision", "%.8d", 42);
	(*total)++;
	*passed += test_int("precision negative", "%.8d", -42);
	(*total)++;
	*passed += test_int("zero value precision zero", "%.0d", 0);
	(*total)++;
	*passed += test_int("width and empty number", "%8.0d", 0);
	(*total)++;
	*passed += test_int("'-' overrides '0'", "%-010d", 42);
	(*total)++;
	*passed += test_int("precision overrides '0'", "%010.5d", 42);
	(*total)++;
	*passed += test_int("plus positive", "%+d", 42);
	(*total)++;
	*passed += test_int("plus negative", "%+d", -42);
	(*total)++;
	*passed += test_int("space positive", "% d", 42);
	(*total)++;
	*passed += test_int("space negative", "% d", -42);
	(*total)++;
	*passed += test_int("'+' overrides space", "%+ d", 42);
	(*total)++;
	*passed += test_int("plus and zero", "%+010d", 42);
	(*total)++;
	*passed += test_int("space and zero", "% 010d", 42);
	(*total)++;
	*passed += test_int("all applicable flags", "%-+ 010.5d", 42);
	(*total)++;
}

static void	test_unsigned_conversions(int *passed, int *total)
{
	print_section("u: width, '-', '0' and precision");
	*passed += test_uint("UINT_MAX", "%u", UINT_MAX);
	(*total)++;
	*passed += test_uint("minimum width", "%12u", 42);
	(*total)++;
	*passed += test_uint("left aligned", "%-12u", 42);
	(*total)++;
	*passed += test_uint("zero padded", "%012u", 42);
	(*total)++;
	*passed += test_uint("precision", "%.10u", 42);
	(*total)++;
	*passed += test_uint("precision zero", "%.0u", 0);
	(*total)++;
	*passed += test_uint("combined", "%-012.8u", 42);
	(*total)++;
}

static void	test_hex_conversions(int *passed, int *total)
{
	print_section("x / X: width, '-', '0', precision and '#'");
	*passed += test_uint("lowercase", "%x", 0x2a);
	(*total)++;
	*passed += test_uint("uppercase", "%X", 0x2a);
	(*total)++;
	*passed += test_uint("hash lowercase", "%#x", 0x2a);
	(*total)++;
	*passed += test_uint("hash uppercase", "%#X", 0x2a);
	(*total)++;
	*passed += test_uint("hash with zero", "%#x", 0);
	(*total)++;
	*passed += test_uint("hash and zero padding", "%#012x", 0x2a);
	(*total)++;
	*passed += test_uint("hash, width and precision", "%#12.8x", 0x2a);
	(*total)++;
	*passed += test_uint("hash and left aligned", "%-#12x", 0x2a);
	(*total)++;
	*passed += test_uint("hex precision zero", "%#.0x", 0);
	(*total)++;
	*passed += test_uint("UINT_MAX uppercase", "%#X", UINT_MAX);
	(*total)++;
}

static void	test_pointer_and_percent(int *passed, int *total)
{
	int	marker;

	print_section("p / %: pointer and literal percent");
	marker = 42;
	*passed += test_pointer("pointer", "%p", &marker);
	(*total)++;
	*passed += test_pointer("pointer width", "%20p", &marker);
	(*total)++;
	*passed += test_pointer("pointer left aligned", "%-20p", &marker);
	(*total)++;
	*passed += test_pointer("null pointer", "%p", NULL);
	(*total)++;
	*passed += test_pointer("null pointer width", "%20p", NULL);
	(*total)++;
	*passed += test_percent("literal percent", "%%");
	(*total)++;
}

static void	test_platform_probes(void)
{
	int	marker;

	print_section("INFORMATIONAL: undefined or platform-specific formats");
	printf("These probes do not affect the scored summary.\n");
	printf("Their result is allowed to differ between libc implementations.\n");
	marker = 42;
	test_char("character zero flag", "%05c", 'A');
	test_char("character precision", "%.3c", 'A');
	test_string("string zero flag", "%010s", "hello");
	test_string("string zero width precision", "%010.3s", "hello");
	test_pointer("pointer zero padded", "%020p", &marker);
	test_pointer("pointer precision", "%.15p", &marker);
	test_pointer("pointer width precision", "%20.15p", &marker);
	test_percent("percent width", "%5%");
	test_percent("percent left aligned", "%-5%");
	test_percent("percent zero flag", "%05%");
	test_percent("percent precision", "%.3%");
}

int	main(int argc, char **argv)
{
	int	passed;
	int	total;

	passed = 0;
	total = 0;
	printf("ft_printf bonus differential test\n");
	printf("Each case compares output bytes and return value with printf.\n");
	test_text_conversions(&passed, &total);
	test_signed_conversions(&passed, &total);
	test_unsigned_conversions(&passed, &total);
	test_hex_conversions(&passed, &total);
	test_pointer_and_percent(&passed, &total);
	if (argc == 2 && strcmp(argv[1], "--extended") == 0)
		test_platform_probes();
	print_section("SUMMARY");
	printf("Passed: %d / %d\n", passed, total);
	if (passed == total)
	{
		printf("RESULT: ALL OK\n");
		return (EXIT_SUCCESS);
	}
	printf("RESULT: KO (%d failed)\n", total - passed);
	return (EXIT_FAILURE);
}
