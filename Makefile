
NAME = base_converter

SRC =	convert_base.c\

LIBFT = libft.a

all: $(NAME)

$(NAME): $(SRC)
		@echo "-----------------------------------"
		@echo "Compiling base_converter"
		@gcc -o $(NAME) $(SRC) $(LIBFT)
		@echo "-----------------------------------"
		@echo "base_converter is ready"
fclean:	
	@rm -f $(NAME)
	@echo "-----------------------------------"
	@echo "base_converter successfully removed"
re: 
	@make fclean
	@make all