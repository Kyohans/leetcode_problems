include common.mk

all:
	@echo "Must specify either 'make clean' or 'make [challenge]'"

clean:
	@rm $(BINDIR)/solution && echo "Removed $(abspath $(BINDIR))/solution"

product_of_array_except_self:
	@mkdir -p bin && $(MAKE) -C $(SRCDIR)/product_of_array_except_self
add_two_numbers:
	@mkdir -p bin && $(MAKE) -C $(SRCDIR)/add_two_numbers
number_of_set_bits:
	@mkdir -p bin && $(MAKE) -C $(SRCDIR)/number_of_set_bits
find_unique_binary_string:
	@mkdir -p bin && $(MAKE) -C $(SRCDIR)/find_unique_binary_string
