#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

/* 出力を目で比較。戻り値は同じなら OK、違えば NG。 */
int	main(void)
{
	int	standard;
	int	mine;
	int	value;

	value = 42;
	setbuf(stdout, NULL);

	/* 文字・文字列・% */
	printf("\n文字・文字列・%%\n");
	printf("   printf: ");
	standard = printf("|%c| |%s| |%%|\n", 'A', "hello");
	printf("ft_printf: ");
	mine = ft_printf("|%c| |%s| |%%|\n", 'A', "hello");
	printf("return: printf=%d, ft_printf=%d [%s]\n",
		standard, mine, standard == mine ? "OK" : "NG");

	/* 整数（%d・%i） */
	printf("\n整数（%%d・%%i）\n");
	printf("   printf: ");
	standard = printf("|%d| |%i| |%d|\n", 42, -42, 0);
	printf("ft_printf: ");
	mine = ft_printf("|%d| |%i| |%d|\n", 42, -42, 0);
	printf("return: printf=%d, ft_printf=%d [%s]\n",
		standard, mine, standard == mine ? "OK" : "NG");

	/* INT_MIN・INT_MAX */
	printf("\nINT_MIN・INT_MAX\n");
	printf("   printf: ");
	standard = printf("|%d| |%d|\n", INT_MIN, INT_MAX);
	printf("ft_printf: ");
	mine = ft_printf("|%d| |%d|\n", INT_MIN, INT_MAX);
	printf("return: printf=%d, ft_printf=%d [%s]\n",
		standard, mine, standard == mine ? "OK" : "NG");

	/* 符号なし・16進数 */
	printf("\n符号なし・16進数\n");
	printf("   printf: ");
	standard = printf("|%u| |%x| |%X|\n", UINT_MAX, 255u, 255u);
	printf("ft_printf: ");
	mine = ft_printf("|%u| |%x| |%X|\n", UINT_MAX, 255u, 255u);
	printf("return: printf=%d, ft_printf=%d [%s]\n",
		standard, mine, standard == mine ? "OK" : "NG");

	/* ポインタ */
	printf("\nポインタ\n");
	printf("   printf: ");
	standard = printf("|%p|\n", (void *)&value);
	printf("ft_printf: ");
	mine = ft_printf("|%p|\n", (void *)&value);
	printf("return: printf=%d, ft_printf=%d [%s]\n",
		standard, mine, standard == mine ? "OK" : "NG");

	/* 複数の変換 */
	printf("\n複数の変換\n");
	printf("   printf: ");
	standard = printf("%s: %d %c\n", "answer", 42, '!');
	printf("ft_printf: ");
	mine = ft_printf("%s: %d %c\n", "answer", 42, '!');
	printf("return: printf=%d, ft_printf=%d [%s]\n",
		standard, mine, standard == mine ? "OK" : "NG");

	return (0);
}
