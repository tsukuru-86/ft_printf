#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

/* 出力を目で比較。戻り値は同じなら OK、違えば NG。 */
int	main(void)
{
	int	standard;
	int	mine;
	int	flag_score;
	int	flag_total;

	setbuf(stdout, NULL);
	flag_score = 0;
	flag_total = 3;

	/* INT_MIN を %d で表示 */
	printf("\nINT_MIN を %%d で表示\n");
	printf("   printf: ");
	standard = printf("|%d|\n", INT_MIN);
	printf("ft_printf: ");
	mine = ft_printf("|%d|\n", INT_MIN);
	printf("return: printf=%d, ft_printf=%d [%s]\n",
		standard, mine, standard == mine ? "OK" : "NG");

	/* # フラグ：16進数に 0x / 0X を付ける */
	printf("\n# フラグ：%%#x・%%#X\n");
	printf("   printf: ");
	standard = printf("|%#x| |%#X|\n", 42, 42);
	printf("ft_printf: ");
	mine = ft_printf("|%#x| |%#X|\n", 42, 42);
	flag_score += standard == mine;
	printf("return: printf=%d, ft_printf=%d [%s] (1点)\n",
		standard, mine, standard == mine ? "OK" : "NG");

	/* + フラグ：正の数に + を付ける */
	printf("\n+ フラグ：%%+d\n");
	printf("   printf: ");
	standard = printf("|%+d| |%+d|\n", 42, -42);
	printf("ft_printf: ");
	mine = ft_printf("|%+d| |%+d|\n", 42, -42);
	flag_score += standard == mine;
	printf("return: printf=%d, ft_printf=%d [%s] (1点)\n",
		standard, mine, standard == mine ? "OK" : "NG");

	/* スペースフラグ：正の数に空白を付ける */
	printf("\nスペースフラグ：%% d\n");
	printf("   printf: ");
	standard = printf("|% d| |% d|\n", 42, -42);
	printf("ft_printf: ");
	mine = ft_printf("|% d| |% d|\n", 42, -42);
	flag_score += standard == mine;
	printf("return: printf=%d, ft_printf=%d [%s] (1点)\n",
		standard, mine, standard == mine ? "OK" : "NG");

	/* - フラグ：幅 4・8・12（自由に変更OK） */
	printf("\n- フラグ：幅 4・8・12（自由に変更OK）\n");
	printf("   printf: ");
	standard = printf("|%-4d| |%-8d| |%-12d|\n", 42, -42, 123);
	printf("ft_printf: ");
	mine = ft_printf("|%-4d| |%-8d| |%-12d|\n", 42, -42, 123);
	printf("return: printf=%d, ft_printf=%d [%s]\n",
		standard, mine, standard == mine ? "OK" : "NG");

	/* 0 フラグ：%04d・%08d */
	printf("\n0 フラグ：%%04d・%%08d\n");
	printf("   printf: ");
	standard = printf("|%04d| |%04d| |%08d|\n", 42, -42, 123);
	printf("ft_printf: ");
	mine = ft_printf("|%04d| |%04d| |%08d|\n", 42, -42, 123);
	printf("return: printf=%d, ft_printf=%d [%s]\n",
		standard, mine, standard == mine ? "OK" : "NG");

	/* . 精度：0・1・2・5・8 桁 */
	printf("\n. 精度：0・1・2・5・8 桁\n");
	printf("   printf: ");
	standard = printf("|%.0d| |%.1d| |%.2d| |%.5d| |%.8d|\n", 0, 42, 42, 42, -42);
	printf("ft_printf: ");
	mine = ft_printf("|%.0d| |%.1d| |%.2d| |%.5d| |%.8d|\n", 0, 42, 42, 42, -42);
	printf("return: printf=%d, ft_printf=%d [%s]\n",
		standard, mine, standard == mine ? "OK" : "NG");

	/* . 文字列の精度：0・3・8 文字 */
	printf("\n. 文字列の精度：0・3・8 文字\n");
	printf("   printf: ");
	standard = printf("|%.0s| |%.3s| |%.8s|\n", "hello", "hello", "hello");
	printf("ft_printf: ");
	mine = ft_printf("|%.0s| |%.3s| |%.8s|\n", "hello", "hello", "hello");
	printf("return: printf=%d, ft_printf=%d [%s]\n",
		standard, mine, standard == mine ? "OK" : "NG");

	/* - と . / 0 と . の組み合わせ */
	printf("\n- と . / 0 と . の組み合わせ\n");
	printf("   printf: ");
	standard = printf("|%-10.5d| |%08.5d|\n", 42, 42);
	printf("ft_printf: ");
	mine = ft_printf("|%-10.5d| |%08.5d|\n", 42, 42);
	printf("return: printf=%d, ft_printf=%d [%s]\n",
		standard, mine, standard == mine ? "OK" : "NG");

	printf("\nフラグ得点：%d/%d 点\n", flag_score, flag_total);
	return (0);
}
