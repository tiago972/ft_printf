CC = clang 
CFLAGS = -Wall -Wextra -Werror -I $(INCL)
OBJDIR = objs
SRCDIR = ./srcs
SRC = ft_printf.c \
	  display.c \
	 numbers.c \
	 parse.c \
	 tools.c
CLFLAGS_DEBOG = -g3 -I $(INCL)
DEBUG_SRC = main.c
DEBUG_OBJ = $(addsuffix .o, $(basename $(DEBUG_SRC)))
DEBUG = debug
INCL = ./includes
LIBCREATOR = $(addprefix $(LIBDIR)/, $(LIB))
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(basename $(SRC))))
NAME = libftprintf.a
include libft/Makefile_lib

all: $(NAME)

$(NAME): $(OBJ) $(NAME_LIB) 
	@ar rc $(NAME) $(NAME_LIB) $<
	@ranlib $(NAME)
	@echo "\n\033[38;5;4;1;4m$(NAME)\033[0m compiled successfully\n" 

$(OBJDIR)/%.o : $(SRCDIR)/%.c  
	@mkdir -p $(OBJDIR)
	@echo "\033[38;5;82m$@\033[0m has been created" 
	@$(CC) -o $@ -c $? $(CFLAGS)

clean: 
	@rm -rf $(OBJDIR)
	@echo "\033[38;5;208m$(OBJDIR)\033[0m has been deleted" 

fclean: clean
	@rm -f $(NAME)
	@echo "\033[38;5;208m$(NAME)\033[0m has been deleted" 

re: fclean all

fclean_all: fclean_lib fclean

re_all: fclean_lib re

$(DEBUG): $(DEBUG_OBJ) $(NAME)
	@$(CC) $(CLFLAGS) -o $@ $< -L. -lftprintf
	@echo "\n\033[38;1;25m READY to debug man\033[0m\n"

clean_deb:
	@rm -rf $(DEBUG_OBJ)
fclean_deb: clean_deb
	@rm -rf $(DEBUG)

re_debug: fclean_deb $(DEBUG)
	
$(DEBUG_OBJ): $(DEBUG_SRC)
	$(CC) $(CLAGS_DEBOG) -o $@ -c $<

.PHONY: clean fclean all
