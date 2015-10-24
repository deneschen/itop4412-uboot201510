dtb-$(CONFIG_S5PC100) += s5pc1xx-smdkc100.dtb
dtb-$(CONFIG_S5PC110) += s5pc1xx-goni.dtb
dtb-$(CONFIG_EXYNOS4) += exynos4210-origen.dtb \
	exynos4210-smdkv310.dtb \
	exynos4210-universal_c210.dtb \
	exynos4210-trats.dtb \
	exynos4412-trats2.dtb \
	exynos4412-odroid.dtb

dtb-$(CONFIG_EXYNOS5) += exynos5250-arndale.dtb \
	exynos5250-snow.dtb \
	exynos5250-spring.dtb \
	exynos5250-smdk5250.dtb \
	exynos5420-smdk5420.dtb \
	exynos5420-peach-pit.dtb \
	exynos5800-peach-pi.dtb \
	exynos5422-odroidxu3.dtb


targets += $(dtb-y)

# Add any required device tree compiler flags here
DTC_FLAGS +=

PHONY += dtbs
dtbs: $(addprefix $(obj)/, $(dtb-y))
	@:

clean-files := *.dtb
