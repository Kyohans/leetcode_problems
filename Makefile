include common.mk

all:
	@echo "Must specify either a challenge or clean task"

clean:
	@rm $(BINDIR)/solution
	@echo "Removed $(abspath $(BINDIR))/solution"

product_of_array_except_self:
	$(MAKE) -C $(SRCDIR)/product_of_array_except_self
add_two_numbers:
	$(MAKE) -C $(SRCDIR)/add_two_numbers
