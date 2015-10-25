#include <common.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <linux/compiler.h>
#include <asm/io.h>
#include <asm/arch/clk.h>
#include <asm/arch/uart.h>
#include <serial.h>

#define CONFIG_DEBUG_UART_BASE 0x13820000

#define CLK_SRC_PERIL0 			(0x10030000 + 0xC250)
#define CLK_SRC_MASK_PERIL0 	(0x10030000 + 0xC350)
#define CLK_DIV_PERIL0 			(0x10030000 + 0xC550)
#define CLK_DIV_STAT_PERIL0 	(0x10030000 + 0xC650)

#define TX_FIFO_FULL		(1 << 24)
void dbg_uart_init(void)
{
	struct s5p_uart *uart = (struct s5p_uart *)CONFIG_DEBUG_UART_BASE;

	/* clock for uart init */
	writel((readl(CLK_SRC_PERIL0) & ~(0xF << 8)) | (0x6 << 8), CLK_SRC_PERIL0);
	writel(readl(CLK_SRC_MASK_PERIL0) | (1 << 8), CLK_SRC_MASK_PERIL0);
	writel((readl(CLK_DIV_PERIL0) & ~(0xF << 8)) | (13 << 8), CLK_DIV_PERIL0);

	while(readl(CLK_DIV_STAT_PERIL0) & (1 << 8));

	writel(0x2 << 0 | 0x2 << 4, (0x11400000 + 0x0020));
	writel(0x3, &uart->ulcon);
	writel(0x5, &uart->ucon);
	writel((7 << 8) | (1 << 2) | (1 << 0), &uart->ufcon);
	writel(30, &uart->ubrdiv);
	writeb(0 , &uart->rest.value);
}

void dbg_uart_putc(int ch)
{
	struct s5p_uart *uart = (struct s5p_uart *)CONFIG_DEBUG_UART_BASE;

	while (readl(&uart->ufstat) & TX_FIFO_FULL);

	writeb(ch, &uart->utxh);
}
