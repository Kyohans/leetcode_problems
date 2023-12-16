include common.mk

all:
	@echo "Must specify either 'make clean' or 'make [problem]'"

clean:
	@rm $(BINDIR)/solution && echo "Removed $(abspath $(BINDIR))/solution"

product_of_array_except_self:
	@mkdir -p bin && $(MAKE) -C $(PROBLEMDIR)/product_of_array_except_self
add_two_numbers:
	@mkdir -p bin && $(MAKE) -C $(PROBLEMDIR)/add_two_numbers
number_of_set_bits:
	@mkdir -p bin && $(MAKE) -C $(PROBLEMDIR)/number_of_set_bits
find_unique_binary_string:
	@mkdir -p bin && $(MAKE) -C $(PROBLEMDIR)/find_unique_binary_string
minimum_window_substring:
	@mkdir -p bin && $(MAKE) -C $(PROBLEMDIR)/minimum_window_substring
