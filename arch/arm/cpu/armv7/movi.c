#include <common.h>
#include <asm/io.h>

#define UBOOT_BLK_CNT (1024 * 1024 / (1 << 9))
#define MOVI_UBOOT_POS (512 / (1 << 9))

typedef u32 (*copy_sd_mmc_to_mem) (u32 start_block, u32 block_count, u32* dest_addr);

void movi_uboot_copy(void)
{
	copy_sd_mmc_to_mem copy_bl2 = (copy_sd_mmc_to_mem)*(u32 *)(0x02020030);
	copy_bl2(1, 2048, (u32 *)CONFIG_SYS_TEXT_BASE);
}
